#include <iostream>
using namespace std;
void cardata(int cars[][5],int rows){
    cout<<"----Cars Inventory-----"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            cout<<cars[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main() {
    int rows = 5;
    int car[5][5] = {
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}
    }; 

    cardata(car, rows); 

    return 0;
} 