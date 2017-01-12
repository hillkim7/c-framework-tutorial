#include <iostream>
#include <boost/ref.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;

void f(int & x) {++x;}

int main(int argc, char *argv[])
{
  int aaa = 0;

  boost::function<void()> byval = boost::bind(f, aaa);      // binds a copy
  boost::function<void()> byref = boost::bind(f, boost::ref(aaa)); // binds a reference

  byval(); cout << "byval() " << aaa << endl;   // increments a copy: prints 0
  byref(); cout << "byref() " << aaa << endl;

  return 0;
}

