#include <iostream>
#include "kalkulator.cc"
using namespace std;

int main(){
    kalkulator k;
    int pilih;
    char pil;

    cout<<"Program Kalkulator Sederhana"<<endl;
    cout<<"Silahkan Pilih Menu yang Anda Inginkan"<<endl;

    menu:
        cout<<"0.Exit"<<endl;
        cout<<"1.Tambah"<<endl;
        cout<<"2.Kurang"<<endl;
        cout<<"3.Kali"<<endl;
        cout<<"4.Bagi"<<endl;
        cin>>pilih;
        switch(pilih){
            
            case 1:
                k.inputan();
                cout<<"Hasil : "<<k.tambah()<<endl;
                break;

            case 2:
                k.inputan();
                cout<<"Hasil : "<<k.kurang()<<endl;
                break;

            case 3:
                k.inputan();
                cout<<"Hasil : "<<k.kali()<<endl;
                break;

            case 4:
                k.inputan();
                cout<<"Hasil : "<<k.bagi()<<endl;
                break;

            default:
                cout<<"Pilihan Salah"<<endl;
        }
};