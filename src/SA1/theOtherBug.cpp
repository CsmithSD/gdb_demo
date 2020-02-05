#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main ( int argc, char* argv[] )
{
	int* p = new int;
	p = new int;
	delete p;
	p = new int;

	srand ( time ( NULL ) );
	int x = rand() % 6 + 1;
	int y = rand() % 2;
	int z = x / y;
	cout << x << " " << y << " " << z << endl;

	return 0;
}
