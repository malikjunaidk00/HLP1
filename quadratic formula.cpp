#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
// to calculate the value of (x) using quadratic formula
// also to find the type of roots of the equation
// in case of no real roots it should show a message

// requirements for quadratic formuala 
// discriminant
// check whether roots will be real or not
int disc (int a, int b, int c)
{
	int disc;
	disc = b*b - 4*a*c;
	return disc;
	
}
int inputs(int a , int b , int c)
{

	cout << "a = ";
	cin >> a;
	cout << "   b = ";
	cin >> b;
	cout << "   c = ";
	cin >> c;
}
int main()
{
	int a,b,c;
		cout << "input the co-efficients of the expressions ";
		cout<< inputs(a,b,c);
	
	// checking the roots
	if (disc(a,b,c) > 0 )
	{
		cout << "the roots are real and unequal\n"; 
	}
	else if (disc(a,b,c) == 0)
	{
		cout << "the roots and real and equal\n";
	}
	else
	{
		cout << " the roots are imaginary not real \n";
	}
	
	// determining the roots 
	
	int x,y;
	x= ((-b+sqrt(b*b - 4*a*c))/(2*a));
	y= ((-b-sqrt(b*b - 4*a*c))/(2*a));
	
	cout << "and the roots are "<< x << endl << y << endl;
	return 0;
}

