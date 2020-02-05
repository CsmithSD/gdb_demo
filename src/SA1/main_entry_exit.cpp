#include <iostream>
#include <string>
#include "common.h"

using namespace std;

void fn1 ( int x );
void fn2 ( string y );
void fn3 ( double z );

void fn1 ( int x )
{
	ENTRY ( x )
	fn2 ( "Here" );
	fn3 ( 3.14159 );
	EXIT ( x )
}

void fn2 ( string y )
{
	ENTRY ( y )
	fn3 ( 6.72 );
	EXIT ( y )
}

void fn3 ( double z )
{
	ENTRY ( z )
	EXIT ( z )
}

int main()
{
	fn1 ( 10 );
	cout << "Finished!\n";
	return 0;
}
