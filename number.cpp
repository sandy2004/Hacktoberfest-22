// Greater b/w 4 numbers


#include<iostream>
using namespace std;

int main(){
    int a=2,b=5,c=9,d=7;
    if(a>b && a>c && a>d){
        cout<<a<<endl;
    }
    else if(b>c && b>d ){
        cout<<b<<endl;
    }
    else if (c>d)
    {
        cout<<c<<endl;
    }
    else{
        cout<<d;
    }
 return 0;   
}