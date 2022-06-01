#include <iostream>
using namespace std;

double fibo(int n) {
  if (n <= 2)
    return 1;
  return fibo(n - 1) + fibo(n - 2);
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  cout << fibo(n) << '\n';
}
