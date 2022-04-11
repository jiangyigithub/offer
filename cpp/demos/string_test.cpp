#include "string.hpp"
#include <iostream>

using namespace std;

int main()
{
  String s1("hello"); 
  String s2("world");
  
  String* p = new String("hello");
  delete p;

  String s3(s2);
  cout << s3 << endl;
  
  s3 = s1;
  cout << s3 << endl;     
  cout << s2 << endl;  
  cout << s1 << endl;      
}