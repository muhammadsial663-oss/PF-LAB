#include<iostream>
using namespace std;

float volumeofcube(float length, float width, float height, string unit)
{
    float volume=length*width*height;

    if (unit=="millimeters")
    {
        volume=volume*1000;
    }
    else if (unit=="centimeters")
    {
        volume=volume*100;
    }
    else if (unit=="meters")
    {
        volume=volume;
    }
    else if (unit=="kilometers")
    {
        volume=volume/1000;
    }
    else
    {
        cout<<"Invalid Input";
    }
    return volume;
}
main()
{
    cout<<"Enter the length of the rectangle = ";
    int length=0;
    cin>>length;

    cout<<"Enter the width of the rectangle = ";
    int width=0;
    cin>>width;

    cout<<"Enter the height of the rectangle = ";
    int height=0;
    cin>>height;

    cout<<"Enter the unit of the volume(centimeters, millimeters, meters, kilometers) = ";
    string unit;
    cin>>unit;

    int volume=volumeofcube(length, width, height, unit);

    cout<<"The volume of the rectangle is : "<<volume<<" "<<unit;
}