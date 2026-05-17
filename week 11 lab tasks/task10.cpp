#include <iostream>
using namespace std;
int identical(int arrray[][3],int rows){
    int count=0;
    for(int i=1;i<rows;i++){
        for(int j=0;j<3;j++){
            if (arrray[0][j]==arrray[i][j]){
                count++;

            }
        }
    }
    return count;
}
int main(){
    int rows;
    cout<<"Enter the number of rows :";
    cin>>rows;
    int matrix[rows][3];
    for(int i=0;i<rows;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter the element at position :"<<"["<<i<<"]"<<"["<<j<<"]"<<":";
            cin>>matrix[i][j];
        }
    }
    int ans=identical(matrix,rows);
    cout<<ans;
}