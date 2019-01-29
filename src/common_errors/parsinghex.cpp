#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;



int main()
{
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	ll i, j, k;

	string line;
	string hex;
	char xType;

	while ( getline ( cin, line ) && cin ) {
		for ( i = 0; i < line.size() - 1; i++ ) {
			if ( line[i] == '0' && ( line[i + 1] == 'x' || line[i + 1] == 'X' ) ) {
				if ( line[i + 1] == 'x' )
					xType = 'x';
				else
					xType = 'X';

				hex = "";
				j = i + 2;

				while ( j < line.size() && isxdigit ( line[j] ) ) {
					hex += line[j];
					j++;
				}

				if ( hex != "" )
					cout << "0" << xType << hex << " " << stoull ( hex, nullptr, 16 ) << "\n";
			}
		}
	}

	return 0;
}

/*
This problem is simple. Just search the input for hexadecimal numbers, and print any numbers you find in both hexadecimal and decimal format.

Input

Input is a sequence of at most 100
text lines, ending at end of file. Each line has at most 100 characters, and contains 0 or more hexadecimal numbers. No hexadecimal number spans multiple lines. A hexidecimal number begins with ‘0x’ or ‘0X’ (that’s a number zero followed by a letter x), followed by a string of hexadecimal digits (0–9

, a–f, or A–F). A hexadecimal number should be as long as possible, but no hexadecimal number in the input is greater than 0xffffffff. No two hexadecimal numbers are adjacent on any line.
Output

For each hexadecimal number (in the order they appear in the input), print a line containing the hexadecimal number as it appeared in the input and its non-negative decimal equivalent.
This Problem statement is modified to allow the demonstrated bug
*/
