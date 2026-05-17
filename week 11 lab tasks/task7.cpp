#include <iostream>
using namespace std;
int printsum(int matrix[][3],int rows){
    int sum=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<3;j++){
            sum=sum+matrix[i][j];
        }
    }
    return sum;
}
int main(){
    int rows;
    cout<<"Enter the number of rows :";
    cin>>rows;
    int matrix[rows][3];
    for(int i=0;i<rows;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter the element of the positon"<< "["<< i <<"]"<< "["<<j<<"]"<<":"<<endl;
            cin>>matrix[i][j];
        }
    }
int ans=printsum(matrix,rows);
cout<<ans;
}