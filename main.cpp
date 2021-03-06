#include <bits/stdc++.h>

using namespace std;

#define MAX 128

struct Person{
    string memberName;
    int memberSex;
};

struct Addressbooks{
    int size{};
    struct Person personArray[MAX];
};

void showMenue(){

    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、删除联系人  *****" << endl;
    cout << "*****  3、显示联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;

}

//遍历搜索，匹配则返回index
int isExit(Addressbooks *abs, const string& name){
    for (int i = 0; i <= abs->size; ++i) {


        //if (abs ->personArray->memberName == name){
        if(abs->personArray[i].memberName == name){
            //return 1;
            //return abs->size;
            return i;
        } else {
            return -1;
        }
    }
}

void addPerson(Addressbooks *abs){
    string name;
    cout << "请输入姓名" << endl;
    cin >> name ;

    if(isExit(abs,/*abs->personArray->memberName*/name) > 0){
        cout << "该人已存在" << endl;
        cout <<"size"<< abs->size <<endl;
        exit(0);
    } else{
            abs->personArray[abs->size].memberName = name ;


            int sex = 0;
            cout << "请输入性别1,2" << endl;
            cin >> sex;
            abs->personArray[abs->size].memberSex = sex;

            abs->size++;
            cout <<"size"<< abs->size <<endl;
    }

}

void deletePerson(Addressbooks * abs){

    string name;
    cout << "请输入姓名" << endl;
    cin >> name ;

    if(isExit(abs, /*abs->personArray[abs->size].memberName*/name) < 0){
        cout <<"size"<< abs->size <<endl;
        cout << "该人不存在 " << endl;
    } else{
        for (int i = isExit(abs, abs->personArray[abs->size].memberName); i < abs->size; ++i) {
            abs->personArray[i] = abs->personArray[i+1];
            //abs->size--;
        }
        abs ->size--;
    }

}

void changePerson(Addressbooks * abs){

    string name;
    cout << "请输入您要查询的姓名" << endl;
    cin >> name;
    int ret = isExit(abs,name);  //ret接收isExist返回的index

    int sex = 0;

    if (ret < 0){
        cout << "不存在该用户" << endl;
    } else{
        cout << "请输入性别" << endl;
        cin >> sex;
        abs->personArray[ret].memberSex = sex;
    }
}

void findPerson(Addressbooks * abs){
    string name;
    cout << "请输入您要查询的姓名" << endl;
    cin >> name;
    int ret = isExit(abs,name);  //ret接收isExist返回的index

    if (ret < 0){
        cout << "不存在该用户" << endl;
    } else{
        cout << "用户名:  " << abs->personArray[ret].memberName  <<"   "
           << "用户性别:  "  << abs->personArray[ret].memberSex << endl;
    }
}


void listPerson(Addressbooks * abs){
    for (int i = 0; i < abs->size; ++i) {
        cout << "姓名：" << abs->personArray[i].memberName << " "
             << "性别: " << abs->personArray[i].memberSex << endl;
    }
}

void clearPerson(Addressbooks * abs){
    //如何实现清空？
    abs->size = 0;
    cout << "已清空" << endl;
}


int main() {

    Addressbooks  abs;
    abs.size = 0;

    int select = 0;




        //showMenue();

        //cout << "请输入您的选择" << endl;
        //cin >> select;

        while(true) {

            showMenue();

            cout << "请输入您的选择" << endl;
            cin >> select;

            switch (select) {
                case 1:
                    addPerson(&abs);
                    break;
                case 2:
                    deletePerson(&abs);
                    break;
                case 3:
                    listPerson(&abs);
                    break;
                case 4:
                    findPerson(&abs);
                    break;
                case 5:
                    changePerson(&abs);
                    break;
                case 6:
                    clearPerson(&abs);
                    break;
                case 0:
                    cout << "欢迎下次使用" << endl;
                    return 0;
                    break;

                default:
                    break;
            }

        }


    return 0;

}