#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 10;

void updateVector(double darr[], int size)
{
   // Do some math to calculate an index
   for (int i = 0; i < size + 5; i++) 
      darr[i] = 3.14159;
}

template<typename T>
void fillVector(T arr[], int size)
{
   for (int i = 0 ; i < size ; i++)
      arr[i] = i;
}

template<typename T>
void printVector(T arr[], int size)
{
   for (int i = 0 ; i < size ; i++)
      cout << arr[i] << " ";

   cout << endl;
}

int main()
{
   double *darr = new double[MAX_SIZE];
   int *arr = new int[MAX_SIZE];

   srand(time(NULL));
   fillVector(arr, MAX_SIZE);
   fillVector(darr, MAX_SIZE);

   cout << "Arr array Before:" << endl;
   printVector(arr, MAX_SIZE);

   // Updating the double array
   cout << "Updating Darr array\n";
   updateVector(darr, MAX_SIZE);

   cout << "Arr array After:" << endl;
   printVector(arr, MAX_SIZE);

   return 0;
}
