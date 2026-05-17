#include <iostream>
using namespace std;
void maxsum(int array[][5],int rows){
    cout<<"Orignal matrix"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            cout<<array[i][j]<<"\t";
        }
        cout<<endl;
    }
    int maxsum=0;
    int colindex=0;
   for(int i=0;i<rows;i++){
    maxsum=maxsum+array[i][0];
   }
   int coulumbsum=0;
   for(int j=1;j<5;j++){
    coulumbsum=0;
    for(int i=0;i<rows;i++){
        coulumbsum=coulumbsum+array[i][j];
    }
    if(coulumbsum>maxsum){
        maxsum=coulumbsum;
        colindex=j;
    }
   }
   if(colindex!=0){
    for(int i=0;i<rows;i++){
        int temp=array[i][0];
        array[i][0]=array[i][colindex];
        array[i][colindex]=temp;
    }
   }
    cout<<"Matrix after finding max coulum"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            cout<<array[i][j]<<"\t";
        }
        cout<<endl;
    }

    
}
int main(){
    int rows;
    cout<<"Enter the numeber of rows :";
    cin>>rows;
    int materix[rows][5];
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            cout<<"Enter the element at position "<<"["<<i<<"]"<<"["<<j<<"]"<<":";
            cin>>materix[i][j];
        }
    }
    maxsum(materix,rows);
}