#include <iostream>
using namespace std;
int converter(int totalcars[][5],int rows,int index){
    int sum=0;
    for(int i=0;i<rows;i++){
        sum=sum+totalcars[i][index];
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter the colour index :";
    cin>>n;
    int rows=5;
    int cars[5][5]={
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}
    }; 
    int ans=converter(cars,rows,n);
    cout<<"Total cars available in that specific colour "<<endl;
    cout<<ans;
}