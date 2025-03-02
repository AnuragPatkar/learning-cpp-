#include<iostream>
using namespace std;
int main()
{
    int a[10],add=0;
    cout<<"Enter 10 Numbers: ";
    for(int i=0;i<10;i++)
    {
         cin>>a[i];
         add+=a[i];
    }
    cout<<"Sum of 10 Numbers: "<<add; 
    return 0;
}
