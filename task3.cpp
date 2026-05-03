#include <iostream>
using namespace std;

// Function to calculate final price including tax
float taxCalculator(char type, float price)
{
    float taxRate = 0.0;

    // Determine tax rate based on vehicle type
    if (type == 'M' || type == 'm')
        taxRate = 0.06;
    else if (type == 'E' || type == 'e')
        taxRate = 0.08;
    else if (type == 'S' || type == 's')
        taxRate = 0.10;
    else if (type == 'V' || type == 'v')
        taxRate = 0.12;
    else if (type == 'T' || type == 't')
        taxRate = 0.15;
    else
        return -1; // invalid type

    float taxAmount = price * taxRate;
    float finalPrice = price + taxAmount;

    return finalPrice;
}

int main()
{
    char type;
    float price;

    cout << "Enter vehicle type (M, E, S, V, T): ";
    cin >> type;

    cout << "Enter vehicle price: ";
    cin >> price;

    float result = taxCalculator(type, price);

    if (result == -1)
    {
        cout << "Invalid vehicle type entered.";
    }
    else
    {
        cout << "The final price on a vehicle of type " 
             << type << " after adding the tax is $" 
             << result << ".";
    }

    return 0;
}