#include <iostream>
using namespace std;

float calculateSalary(float base, int score, int experience)
{
    float bonusRate = 0.0;

    if (score >= 90)
        bonusRate = 0.20;
    else if (score >= 75)
        bonusRate = 0.10;
    else
        bonusRate = 0.05;

    if (experience >= 5)
        bonusRate += 0.05;

    float finalSalary = base + (base * bonusRate);

    return finalSalary;
}

int main()
{
    float base;
    int score, experience;

    cout << "Enter base salary: ";
    cin >> base;

    cout << "Enter performance score: ";
    cin >> score;

    cout << "Enter years of experience: ";
    cin >> experience;

    float result = calculateSalary(base, score, experience);

    cout << "Final Salary: " << result;

    return 0;
}