#include <iostream>
using namespace std;

int function(int num){
  int n3= num%10;
  int n1=num/100;
 if(n1==n3){
    cout<<"number is syymetrical";
 }else{
    cout<<"number is not syymetrical";
 }

    
}
int main(){
    int n1;
    cout<<"Enter the THREE digit number :";
    cin>>n1;
    int fucntion(n1);
   return 0;
}