#include "linkedList.h"

using namespace std;

linkedList::linkedList(listNode* h)
{
   head = h;
}

void linkedList::printList()
{
   listNode* ptr = head;
   while (ptr != nullptr)
   {
      cout << ptr->data;
      if (ptr->next != nullptr) cout << "->";
      ptr = ptr->next;
   }
   cout << endl;
}

listNode* linkedList::find(int d)
{
   listNode* ptr = head;
   while (ptr != nullptr)
   {
      if (ptr->data == d)
          return ptr;

      ptr = ptr->next;
   }
   return nullptr;
}

void linkedList::push_front(int d)
{
   listNode* newNode = new (nothrow) listNode(d, head);
   assert(newNode != nullptr);

   head = newNode;
}

void linkedList::push_back(int d)
{
   listNode* newNode = new (nothrow) listNode(d);
   assert(newNode != nullptr);

   if (head == nullptr)
   {
      head = newNode;
      return;
   }

   listNode* ptr = head;
   while (ptr->next != nullptr)
      ptr = ptr->next;

   ptr->next = newNode;
}

listNode* linkedList::pop_front()
{
   if (head == nullptr) return nullptr;

   listNode* node = head;
   head = head->next;
   return node;
}

listNode* linkedList::pop_back()
{
   if (head == nullptr) return nullptr;

   listNode* node = head;

   if (head->next == nullptr)
   {
      head = nullptr;
      return node;
   }

   listNode* trailer = node;
   node = node->next;

   while (node->next != nullptr)
   {
      trailer = node;
      node = node->next;
   }

   trailer->next = nullptr;
   return node;
}
