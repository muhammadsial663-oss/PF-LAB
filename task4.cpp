#include <iostream>
using namespace std;

// Function to calculate project completion status
string projectTimeCalculation(int neededHours, int days, int workers)
{
    float effectiveDays = days * 0.9;

    float totalHours = effectiveDays * workers * 10;

    int finalHours = (int) totalHours;

    if (finalHours >= neededHours)
    {
        int hoursLeft = finalHours - neededHours;
        return "Yes!" + to_string(hoursLeft) + " hours left.";
    }
    else
    {
        int hoursNeeded = neededHours - finalHours;
        return "Not enough time!" + to_string(hoursNeeded) + " hours needed.";
    }
}

int main()
{
    int neededHours, days, workers;

    cout << "Enter needed hours: ";
    cin >> neededHours;

    cout << "Enter available days: ";
    cin >> days;

    cout << "Enter number of workers: ";
    cin >> workers;

    cout << projectTimeCalculation(neededHours, days, workers);

    return 0;
}