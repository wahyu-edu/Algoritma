#include <iostream>
using namespace std;

void asc(){
    int num[]= {5,2,3,1,4};
    int i,j,t;
    cout<<"DATA Bubble Sort"<<endl;
    for(i=0; i<5; i++)
    {
        cout<<num[i]<<" ";
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4-i; j++)
        {
            if(num[j]>num[j+1])
            {
                t=num[j];
                num[j]=num[j+1];
                num[j+1]=t;
            }
        }
    }

    cout<<endl<<"ASC"<<endl;
    for(i=0; i<5; i++)
    {
        cout<<num[i]<<" ";
    }

    
}

void desc(){
    int num[]= {109,3,9,150,4,10,69,75,15,99};
    int i,j,t;
    cout<<endl<<"DATA Bubble Sort"<<endl;
    for(i=0; i<109; i++)
    {
        cout<<num[i]<<" ";
    }
    
    for(i=0; i<99; i++)
    {
        for(j=0; j<99-i; j++)
        {
            if(num[j]<num[j+1])
            {
                t=num[j];
                num[j]=num[j+1];
                num[j+1]=t;
            }
        }
    }
    cout<<endl<<"DESC"<<endl;
    for(i=0; i<5; i++)
    {
        cout<<num[i]<<" ";
    }
}

int main()
{
    int pilih;
	char pil;
	
menu:
	cout<<"0.Exit"<<endl;
	cout<<"1.BubbleSort ASC"<<endl;
	cout<<"2.BubbleSort DESC"<<endl;
	cin>>pilih;
	switch(pilih){
		case 0: 
			goto keluar;
			break;
		case 1:
			asc();
			break;
        case 2:
			desc();
			break;
		default:
			cout<<"pilihan salah"<<endl;
			break;
		}
		cout<<endl<<"ingin mengulangi? (y/t)";
		cin>>pil;
		if ((pil == 'y')||(pil=='Y'))
        {
			goto menu;
		}
        else if ((pil=='t')||(pil=='T'))
        {
			goto keluar;
		}
keluar:
	cout<<"thanks"<<endl;

    return 0;
}