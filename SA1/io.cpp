#include "io.h"

linkedList* fillList(ifstream& fin)
{
   linkedList *ll = new linkedList();

   int data;
   while (fin >> data)
      ll->push_back(data);
   
   return ll;
}
