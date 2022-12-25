#include <iostream>

using namespace std;
class student
{
private: // data members
  int id;
  string name;
  float grade;

public: // functions
  student()
  {
    grade = 10;
  }
  student(float g)
  {
    grade = g;
  }
  student(float g, int i)
  {
    grade = g;
    id = i;
  }
  void set_id(int i)
  {
    id = i;
  }
  void set_name(string s)
  {
    name = s;
  }
  void set_grade(float g)
  {
    grade = g;
  }
  int get_id()
  {
    return id;
  }
  float get_grade()
  {
    return grade;
  }
  string get_name()
  {
    return name;
  }
};

float calculate_grade_average(int size, student *students);

int main()
{
  int size, id;
  float grade;
  string name;
  cout << "enter size: " << endl;
  cin >> size;
  student *s = new student[size];
  for (int i = 0; i < size; i++)
  {
    cout << "name" << endl;
    cin >> name;
    s[i].set_name(name);
    cout << "id";
    cin >> id;
    s[i].set_id(id);
    cout << "grade";
    cin >> grade;
    s[i].set_grade(grade);
  }
  float grade_average = calculate_grade_average(size, s);
  cout << "the grade average is: " << grade_average << endl;
  return 0;
}

float calculate_grade_average(int size, student *students)
{
  float total_grades = 0;
  for (int i = 0; i < size; i++)
  {
    total_grades += students[i].get_grade();
  }
  return total_grades / size;
}
