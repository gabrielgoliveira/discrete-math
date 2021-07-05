#include <iostream>

using namespace std;

int mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}

int main()
{
    int n;
    int ordem = 0;
    cout<<"Digite o n do grupo : ";
    cin>>n;
    
    cout<<"Zn = {";
    for(int i = 1; i < n; i++) {
        if(mdc(i, n) == 1){
            cout<<" "<<i<<",";
            ordem++;
        }
    }
    cout<<"}"<<endl;
    cout<<"O conjunto tem ordem : "<<ordem<<endl;

    return 0;
}