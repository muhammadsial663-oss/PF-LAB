#include<iostream>
#include<cmath>
using namespace std;
int main()
{
float base,angle;
cout<<"Enter the distance from your position :";
cin>>base;
cout<<"Enter the angle from your position to the top of the tree :";
cin>>angle;
int newangle;
newangle=angle/57.29;
int hight=base*tan(newangle);
cout<<"Hight of the tree is "<<hight;
}