#include <iostream>
#include <unistd.h>

static void showMessage(int i);
static void bedTimeForBonzo(void);

int main()
{
   int i = 100000;

   do
   {
      showMessage(i);
      bedTimeForBonzo();
      i--;
   } while (i);

   return 0;
}

static void showMessage(int i)
{
   std::cout << i << " bugs in the code in the core\n";
}

static void bedTimeForBonzo()
{
   sleep(3);
}
