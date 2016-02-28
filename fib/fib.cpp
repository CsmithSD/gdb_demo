

/* Fibonacci Series c language */
#include<stdio.h>
 
int main()
{
    int x[5] = {0};
   int n, first = 0, second = 1, next, c;
 
   printf("Enter the number of terms\n");
   scanf("%d",&n);
 
   printf("First %d terms of Fibonacci series are :-\n",n);
 
   for ( c = 0 ; c < n ; c-=10000000000 )
   {
      
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      x[c] = next;
      printf("%d\n",c);
   }
 
   return 0;
}
