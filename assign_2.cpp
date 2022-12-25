#include <iostream>

using namespace std;

struct node
{
  int key;
  node *next;
};

node *head = NULL;

void insert(int value);
void display();
void rearrange();

int main()
{
  insert(7);
  insert(1);
  insert(-1);
  insert(0);
  insert(2);
  display();
  rearrange();
  display();
  return 0;
}

void insert(int value)
{
  node *temp, *tail;
  temp = new node;
  temp->key = value;
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    tail = head;
    while (tail->next != NULL)
    {
      tail = tail->next;
    }
    tail->next = temp;
  }
}

void display()
{
  node *current;
  if (head == NULL)
  {
    cout << "Empty list" << endl;
  }
  else
  {
    current = head;
    while (current != NULL)
    {
      cout << current->key << "\t";
      current = current->next;
    }
  }
  cout << endl;
}

void rearrange()
{
  node *i, *j;
  int temp;
  if (head != NULL)
  {
    for (i = head; i->next != NULL; i = i->next)
    {
      for (j = i->next; j != NULL; j = j->next)
      {
        if (i->key > j->key)
        {
          temp = i->key;
          i->key = j->key;
          j->key = temp;
        }
      }
    }
  }
}
