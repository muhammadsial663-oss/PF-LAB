#include<iostream>
using namespace std;
int add (int num1,int num2)
{
int sum=0;
sum=num1+num2;
return sum;
}
int main() 
{
    int number1,number2;
    cout<<"Enter 1st number :";
    cin>>number1;
    cout<<"Enter 2nd number :";
    cin>>number2;
    add(number1,number2);
cout<<add(number1,number2);
}
