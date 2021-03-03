#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int fact(int a)
{
    int  f = 1;
    for (int i=1; i<=a; i++)
    {
        f = f*i;
    }
    return f;
}

int permutation(int a, int b)
{
    return fact(a) / fact(a - b);
}

int combination(int a, int b)
{
    return permutation(a, b) / fact(b);
}

int main()
{
    int a, b;
    char check;

    cout << "Enter the +ve number: ";
    cin >> a;
    cout << "Enter the common ratio: ";
    cin >> b;
    cout << "Enter the operation you want to perform \n ";
    cout << "Enter P for permutation and C for combination\n";
    cin >> check;
   
    
    {
        if (check == 'p' || check == 'P')
        {
            cout << "the permution is = " << permutation(a, b) << endl;
        }
        else if (check == 'c' || check == 'C')
        {
            cout << "the combination is = " << combination(a, b) << endl;

        }
        else
            cout << "invalid inputs";
        return 0;
    }
  
}
