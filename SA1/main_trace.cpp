#include <iostream>
#include <string>
#include "common.h"

using namespace std;

void fn1();
void fn2();
void fn3();

int Counter;

void fn1()
{
	TRACE_ON
	cout << "fn1()\n";
	--Counter;
	fn2();
	fn3();
	TRACE_OFF
}

void fn2()
{
	TRACE_ON
	cout << "fn2()\n";
	fn3();
	TRACE_OFF
}

void fn3()
{
	TRACE_ON
	cout << "fn3()\n";

	if ( Counter > 0 ) fn1();

	TRACE_OFF
}

int main()
{
	Counter = 3;
	fn1();
	return 0;
}
