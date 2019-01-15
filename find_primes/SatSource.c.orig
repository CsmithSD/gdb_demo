/* File:  SatSource.C
 * Purpose:   Shows a comparisson of static and dynamic scheduling in omp 
 */



#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/* Return 1 if 'i'th bit of 'n' is 1; 0 otherwise */
#define EXTRACT_BIT(n,i) ((n&(1<<i))?1:0)

/* Function Prototypes*/
int check_circuit( int id, int z);
void Usage(char * prog_name);

int main (int argc, char *argv[]) 
{
    int global_count = 0;     /* Total number of solutions */
    int i;                /* Counter for combinations */
    int thread_count;     /* Number of processes */
    int n = 65536;
    int loc_count = 0;
    /* timing variables */
    double start  = 0;
    double finish = 0;
    double serial_time = 0;
    double static_time = 0;
    double dynamic_time = 0;
    if (argc != 2) Usage(argv[0]);
    thread_count =  strtoll(argv[1], NULL, 10);

    /* Enter code here
     *
     *
     */

    /*Serial*/
    start = omp_get_wtime();
    for( i = 0; i  < n; i++)
        global_count += check_circuit( 0 , i );
    finish = omp_get_wtime();

    serial_time = finish - start;
    printf("Serial count: %d\n",global_count);
    global_count = 0;
    /* Static scheduling*/
    start = omp_get_wtime();
    # pragma omp parallel for schedule(static,1) num_threads(thread_count) \
    default (none) reduction(+: global_count) private(loc_count,i) shared(n)
    for( i = 0; i < n; i++ )
    {
        loc_count = check_circuit( omp_get_thread_num(), i );
        global_count += loc_count;
    }
    finish = omp_get_wtime();
    static_time = finish - start;
    printf("Static count: %d\n", global_count);
    global_count = 0;
    /*Dynamic scheduling */
    start = omp_get_wtime();
    # pragma omp parallel for schedule(dynamic,1) num_threads(thread_count) \
    default (none) reduction( +: global_count) private(loc_count, i) shared(n)
    for( i = 0; i < n; i++ )
    {
        loc_count = check_circuit( omp_get_thread_num(), i );
        global_count += loc_count;
    }
    finish = omp_get_wtime();
    dynamic_time = finish - start;
    
    printf("Dynamic count: %d\n", global_count);

    printf("Serial runtime: %f\n", serial_time);
    printf("Static scheduling runtime: %f\n", static_time);
    printf("Dynamic scheduling runtime: %f\n",dynamic_time);
    return 0;
}



/* Function:  check_circuit()
 * Purpose:   Check if a given input produces TRUE (a one) 
 *
 * In args:      id, the process id
 *                z, the current combination
 * out:           1, if the the input TRUE in the circuit
 *                0, else
 */
int check_circuit (int id, int z) {
   int v[16];        /* Each element is a bit of z */
   int i;

   for (i = 0; i < 16; i++) v[i] = EXTRACT_BIT(z,i);
   if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
      && (!v[3] || !v[4]) && (v[4] || !v[5])
      && (v[5] || !v[6]) && (v[5] || v[6])
      && (v[6] || !v[15]) && (v[7] || !v[8])
      && (!v[7] || !v[13]) && (v[8] || v[9])
      && (v[8] || !v[9]) && (!v[9] || !v[10])
      && (v[9] || v[11]) && (v[10] || v[11])
      && (v[12] || v[13]) && (v[13] || !v[14])
      && (v[14] || v[15])) {
      printf ("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", id,
         v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],
         v[10],v[11],v[12],v[13],v[14],v[15]);
      fflush (stdout);
      return 1;
   } else return 0;
}

/*------------------------------------------------------------------
 * Function:  Usage
 * Purpose:   Print a message explaining how to run the program
 * In arg:    prog_name
 */
void Usage(char* prog_name) {
   fprintf(stderr, "usage: %s <n>\n", prog_name);  /* Change */
   fprintf(stderr, "   n is the number of threads >= 1\n");
   exit(0);
}  /* Usage */

