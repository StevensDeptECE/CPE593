class MagicSquare {
private:
  int* m;
  int n2;
  int n;
public:
  MagicSquare(int n) : n(n), n2(n*n) {
    m = new int[n2];
    for (int i = 0; i < n2; i++)
      m[i] = i+1;
    generate(0);
  }
  void doit() const { // print the solution in this case


  }
  bool test(int L) {
      return false;
  }
  void generate(int L) {
   if (L >= n2) {
       doit();
   }
   for (int i = 1; i <= n2; i++) {
     m[L] = i;
     if (test(L))
       generate(L+1);
   }
  }

  ~MagicSquare() { delete []m; }



};

int main() {
    MagicSquare m(4);


}