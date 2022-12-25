#include <iostream>
using namespace std;

template <typename T>

class Stack
{
private:
  T *stack;
  int top;
  int max_size;
  int count;

public:
  Stack(int size)
  {
    max_size = size;
    stack = new T(max_size);
    top = -1;
    count = 0;
  }
  bool stack_is_empty()
  {
    return top == -1;
  }
  bool stack_is_full()
  {
    return top == max_size - 1;
  }
  void push(T value)
  {
    if (stack_is_full())
    {
      cout << "Stack overflow" << endl;
    }
    else
    {
      stack[++top] = value;
      count++;
    }
  }

  T pop()
  {
    if (stack_is_empty())
    {
      cout << "Stack underflow" << endl;
      return -1;
    }
    else
    {
      count--;
      return stack[top--];
    }
  }

  T stack_top()
  {
    if (stack_is_empty())
    {
      cout << "Stack underflow" << endl;
      return -1;
    }
    else
    {
      return stack[top];
    }
  }
  void display()
  {
    if (stack_is_empty())
    {
      cout << "Stack underflow" << endl;
    }
    else
    {
      for (int i = top; i >= 0; i--)
      {
        cout << stack[i] << "\t";
      }
      cout << endl;
    }
  }
  int stack_size()
  {
    return count;
  }
};

int main()
{
  // Type int
  Stack<int> int_stack(5);
  cout << "Is the stack empty? " << int_stack.stack_is_empty() << endl;
  cout << "Is the stack full? " << int_stack.stack_is_full() << endl;
  cout << "Stack size is: " << int_stack.stack_size() << endl;
  int_stack.push(5);
  int_stack.push(4);
  cout << "Stack size is: " << int_stack.stack_size() << endl;
  int_stack.push(3);
  int_stack.push(2);
  int_stack.push(1);
  cout << "Stack size is: " << int_stack.stack_size() << endl;
  cout << "Is the stack empty? " << int_stack.stack_is_empty() << endl;
  cout << "Is the stack full? " << int_stack.stack_is_full() << endl;

  int_stack.display();
  cout << int_stack.stack_top() << endl;
  cout << int_stack.pop() << endl;
  cout << int_stack.stack_top() << endl;
  int_stack.display();

  // Copy constructor
  Stack<int> copy_int_stack(int_stack);
  copy_int_stack.display();

  // Type char
  Stack<char> char_stack(5);
  char_stack.push('d');
  char_stack.push('e');
  char_stack.push('m');
  char_stack.push('h');
  char_stack.push('a');

  char_stack.display();
  cout << char_stack.stack_top() << endl;
  cout << char_stack.pop() << endl;
  cout << char_stack.stack_top() << endl;
  char_stack.display();

  return 0;
}
