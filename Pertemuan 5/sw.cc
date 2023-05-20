#include <iostream>
using namespace std;

void penjumlahan(){
    int a = 10;
    int b = 5;
    int c = a + b;
    cout << c <<endl;
}

void loopingfor(){
    for(int a=1; a<=3; a++){
        cout<< a <<endl;
    }
}

void sGoto(){
    int a=5;
    
    if (a%2==0){
        goto genap;
    }else{
        cout<<"bukan ";
    }

    genap:
    cout<<"genap"<<endl;    
       
}

int main(){
    int pilih;
    char kembali;
    do {
        cout<<"0. exit"<<endl;
        cout<<"1. penjumlahan"<<endl;
        cout<<"2. loopingfor"<<endl;
        cout<<"3. goto"<<endl;
        cout<<"pilihan : ";
        cin>>pilih;
        switch(pilih){
            case 0:
                cout<<"terima kasih"<<endl;
                return 0;
            case 1:
                penjumlahan();
                break;
            case 2:
                loopingfor();
                break;
            case 3:
                sGoto();
                return 0;
            default:
                cout<<"pilihan salah"<<endl;
                break;
        }
        cout<<"pilih kembali?"<<endl;
        cin>>kembali;
    }
    while (kembali !='t');
    cout<<"terima kasih"<<endl;
    return 0;
}