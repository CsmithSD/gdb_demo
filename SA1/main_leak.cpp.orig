#include <iostream>
#include <fstream>
#include "functions.h"
#include "io.h"

using namespace std;

int main(int argc, char *argv[])
{
   ifstream fin;
   linkedList* ll;

   if (!checkArgs(argc, argv))
      return -1;

   if (!openFile(fin, argv[1]))
      return -2;

   ll = fillList(fin);

   listNode* seven = ll->find(7);

   if (seven != nullptr) cout << "Found 7\n";   
   listNode* tmp, *six;

   while ((tmp = ll->pop_back()) != seven);

   ll->printList();

   six = ll->find(6);
   if (six != nullptr) cout << "Found 6\n";   
   while ((tmp = ll->pop_front()) != six);

   ll->printList();
   return 0;
}
