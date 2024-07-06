#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1)
    {
        //system("data.exe > data.txt");
        //system("biaoda.exe < data.txt > biaoda.txt");
        system("fruit.exe < fruit1.in > fruit1.out");
        if(system("fc fruit1.out fruit1.ans")){
        	cout<<"error"<<endl;
			system("pause");
		}
		else{
			cout<<"no error"<<endl;
			system("pause");
		}
    }
    return 0;
}
