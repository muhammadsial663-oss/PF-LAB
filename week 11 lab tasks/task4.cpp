#include <iostream>
using namespace std;
int nissan(int cars[][5],int rows){
    int total=0;
    for(int i=0;i<5;i++){
        total=total+cars[2][i];
    }
    return total;
}
int main(){
    int rows=5;
    int cars[5][5]={
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}
    }; 
int combine=nissan(cars,rows);
cout<<"---TOTAL NISSAN CARS---"<<endl;
cout<<combine;
}