#include<iostream>
using namespace std;

int main()
{
	cout << "1: 0001" << endl;
	cout << "2: 0010" << endl;

	if ( 1 & 2 )
		cout << "1 & 2 is true" << endl;

	else
		cout << "1 & 2 is false" << endl;

	if ( 1 && 2 )
		cout << "1 && 2 is true" << endl;

	else
		cout << "1 && 2 is false" << endl;

	return 0;
}
