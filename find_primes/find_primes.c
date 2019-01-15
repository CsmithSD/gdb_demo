/*File: Find_Primes.c
 * Purpose: Demonstrates omp timings of static and dynmic against serial
 * runtime of finding prime numbers up to a given n.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

//corresponding multiple functions for timings
void mark_two_multiples ( const long long p, long long n, bool* is_prime );
void mark_multiples_odd ( const long long p, long long n, bool* is_prime );
//Program Usage output
void Usage ( char* prog_name );
//Functions where timing happens
void  serial_timing ( double* serial_time,  bool* is_prime, long long n, int thread_count );
void  dynamic_timing ( double* dynamic_time, bool* is_prime, long long n, int thread_count );
void  static_timing ( double* static_time,  bool* is_prime, long long n, int thread_count );
//Output to the screen
long long print_primes ( bool* is_prime, char* scheduling, long long n );
void print_timings ( double* serial_time, double* dynmaic_time, double* static_time );
long long serial_count = 0;
long long dynamic_count = 0;
long long static_count = 0;


//Start of the program
int main ( int argc, char* argv[] )
{
	long long n;
	//used to put count elements printed and put newlines in output
	int thread_count;
	bool* is_prime; //sets a flag for a number if its prime or not
	//Stores the times
	double* serial_time  = malloc ( sizeof ( double ) );
	double* dynamic_time = malloc ( sizeof ( double ) );
	double* static_time  = malloc ( sizeof ( double ) );

	//if no n value is given program exits
	if ( argc != 2 )
		Usage ( argv[0] );

	thread_count = omp_get_num_procs();
	n = strtoll ( argv[1], NULL, 10 );

	//if no cores program exits
	if ( thread_count < 1 || n <= 1 )
		Usage ( argv[0] );

	//allocates bool array for all values up to and including n
	is_prime = malloc ( ( n + 1 ) * sizeof ( *is_prime ) );

	//0 and 1 are never used so false is set
	is_prime[0] = false;
	is_prime[1] = false;

	//Times the code
	serial_timing ( serial_time, is_prime, n, thread_count );
	dynamic_timing ( dynamic_time, is_prime, n, thread_count );
	static_timing ( static_time, is_prime, n, thread_count );
	//Prints timings
	print_timings ( serial_time, dynamic_time, static_time );

	return 0;
}

//Marks the multiples of two initially
//since that is the biggest chunck of all non primes
void mark_two_multiples ( const long long p, long long n, bool* is_prime )
{
	long long i;

	for ( i = 2; i * p <= n; i++ )
		is_prime[i * p] = false;
}
//Marks the multiples of an odd number and an odd times an odd is always odd
//so all even multiples are skipped
void mark_multiples_odd ( const long long p, long long n, bool* is_prime )
{
	long long i;

	for ( i = 3; i * p <= n; i += 2 )
		is_prime[i * p] = false;
}
//Program usage statement
void Usage ( char* prog_name )
{
	fprintf ( stderr, "usage: %s <n>\n", prog_name ); /* Change */
	fprintf ( stderr, "   n is the number of terms and should be >= 2\n" );
	exit ( 0 );
}


//Serial timing function that has omp only to initilise everything to prime
void serial_timing ( double* serial_time, bool* is_prime, long long n, int thread_count )
{
	double start;
	double finish;
	long long i;
	//Marks everything prime initially in the boolean array
	#   pragma omp parallel for schedule(static) num_threads(thread_count) \
	default(none) private(i) shared(n, is_prime)

	for ( i = 2; i <= n; i++ )
		is_prime[i] = true;

	//Start timing
	start = omp_get_wtime();
	//starts with 2 and marks all even numbers as multiples
	mark_two_multiples ( 2, n, is_prime );

	//Only odd numbers are prime from 3 and onward so increments of two are done instead of 1
	for ( i = 3; i <= n; i += 2 ) {
		if ( is_prime[i] )
			mark_multiples_odd ( i, n, is_prime );
	}

	//End timing
	finish = omp_get_wtime();
	*serial_time = finish - start;
	serial_count = print_primes ( is_prime, "1", n );
}

//Dynamic timing function that uses dynamic sechduling around outer four loop
void dynamic_timing ( double* dynamic_time, bool* is_prime, long long n, int thread_count )
{
	double start;
	double finish;
	long long i;
	//Marks everything prime initially in the boolean array
	#   pragma omp parallel for schedule(static) num_threads(thread_count) \
	default(none) private(i) shared(n, is_prime)

	for ( i = 2; i <= n; i++ )
		is_prime[i] = true;

	//Start Timing
	start = omp_get_wtime();
	//starts with 2 and marks all even numbers as multiples
	mark_two_multiples ( 2, n, is_prime );

	//Only odd numbers are prime from 3 and onward so increments of two are done instead of 1
	# pragma omp parallel for schedule(dynamic, thread_count) num_threads(thread_count) \
	default(none) private(i) shared(n, is_prime, thread_count)

	for ( i = 3; i <= n; i++ ) {
		if ( is_prime[i] )
			mark_multiples_odd ( i, n, is_prime );
	}

	//End Timing
	finish = omp_get_wtime();
	*dynamic_time = finish - start;
	dynamic_count = print_primes ( is_prime, "dynamic scheduling", n );
}

//Static timing function that uses static scheduling around outer for loop
void static_timing ( double* static_time, bool* is_prime, long long n, int thread_count )
{
	double start = 0;
	double finish = 0;
	long long i;
	//Marks everything prime initially in the boolean array
	#   pragma omp parallel for schedule(static) num_threads(thread_count) \
	default(none) private(i) shared(n, is_prime)

	for ( i = 2; i <= n; i++ )
		is_prime[i] = true;

	start = omp_get_wtime();

	//starts with 2 and marks all even numbers as multiples
	mark_two_multiples ( 2, n, is_prime );

	//Only odd numbers are prime from 3 onward so increments of two are done instead of 1
	# pragma omp parallel for schedule(static) num_threads(thread_count) \
	default(none) private(i) shared(n, is_prime, thread_count)

	for ( i = 3; i <= n; i++ ) {
		if ( is_prime[i] )
			mark_multiples_odd ( i, n, is_prime );
	}

	finish = omp_get_wtime();

	*static_time = finish - start;

	static_count = print_primes ( is_prime, "static scheduling", n );
}

long long print_primes ( bool* is_prime, char* scheduling, long long n )
{
	long long i;
	long long newline_count;
	long long count = 0;

	//Used so primes are printed only once between timings
	if ( scheduling[0] == '1' ) {
		printf ( "Prime Numbers:\n" );
		printf ( "0: 2 " );
		newline_count = 1;
	}

	for ( i = 3; i <= n; i++ ) {
		if ( is_prime[i] ) {
			//increments prime count and outputs list of primes
			//only once between all timings
			count++;

			if ( scheduling[0] == '1' ) {
				newline_count += 1;

				if ( newline_count % 10 == 1 )
					printf ( "%lld: ", newline_count - 1 );

				printf ( "%lld ", i );

				if ( newline_count % 10 == 0 )
					printf ( "\n" );
			}
		}
	}

	if ( scheduling[0] == '1' )
		printf ( "\n\n" );

	return count;
}
//Prints the timings for all three types and the number of primes calculated
void print_timings ( double* serial_time, double* dynamic_time, double* static_time )
{
	printf ( "Serial Time:  %f Number of Primes: %lld\n", *serial_time, serial_count );
	printf ( "Dynamic Time: %f Number of Primes: %lld\n", *dynamic_time, dynamic_count );
	printf ( "Static Time:  %f Number of Primes: %lld\n\n", *static_time, static_count );
}

