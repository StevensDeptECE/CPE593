#include <iostream>

#if 0
class Elephant {
private:
  int age;
  string name;

};
#endif

void swap(int& a, int& b) {
  a = a + b; // a is now the sum of both
  b = a - b; // (a+b) -b  = a
  a = a - b; // (a+b) -a = b
}

/*
A    B      A AND B     A OR B    A XOR B
--------------------------------------------
F    F      F           F         F
F    T      F           T         T
T    F      F           T         T
T    T      T           T         F

a^b = a XOR b


a = 5 =   101
b = 6 =   110


a = a^b  =011 = 3
b = a^b  =101 = 5
a = a^b = 110 = 6


 */
void swap(int& a, int& b) {
  a = a ^ b; // a is now the sum of both
  b = a ^ b; // (a+b) -b  = a
  a = a ^ b; // (a+b) -a = b
}

void bubbleSort(int x[], int n) {
  

}
