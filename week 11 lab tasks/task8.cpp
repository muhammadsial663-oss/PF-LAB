#include <iostream>
using namespace std;
void identitymatrix(int matrix[][3],int rows){
    bool found=false;
    cout<<"Matrix you have entered"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<"\t";
            if(i==j){
                if(matrix[i][j]==1){
                    found=true;
                }
                else{
                    if(matrix[i][j]!=1){
                        found=false;
                    }
                }
            }
        }
        cout<<endl;
        
    }
    if(found==true){
        cout<<"this is identity matrix";
    }
    else if(found==false){
        cout<<"Not identity";
    }
}
int main(){
    int rows=3;
    int matrix[3][3];
    cout<<"Enter the elements of the matrix"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter the element at position "<<"["<<i<<"]"<<"["<<j<<"]"<<":";
            cin>>matrix[i][j];
        }
    }
identitymatrix(matrix,rows);
}