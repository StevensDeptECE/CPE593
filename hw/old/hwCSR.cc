#include <iostream>
#include <vector>

typedef void (*VertexFunc)(uint32_t v);

class CSRGraph {
private:
  std::vector<uint32_t> start;
  std::vector<uint32_t> adjacency;
  std::vector<double> w;
public:
  
  void binarySave(const char filename[]) {
    ofstream f(filename, ios::binary);
    f.write((char*)& start.size()); // encode the size!
    f.write((char*)start.begin(), sizeof(uint32_t) * start.size());
    f.write((char*)adjacency.begin(), sizeof(uint32_t) * adjacency.size());
    f.write((char*)w.begin(), sizeof(double) * w.size());
  }
  void binaryRead(const char filename[]) {

  }
  void dfs(uint32_t starting, VertexFunc f;) {
    stack<uint32_t> scheduled;
    scheduled.push(3);
    
    uint32_t v = scheduled.back();
    scheduled.pop();

    scheduled.is_empty();

    // call function f on each vertex: f(v);

  }
  void bfs(uint32_t starting);
  double& operator (uint32_t from, uint32_t to) {
      // return the weight to write to
  }
  void setW(uint32_t from, uint32_t to, double w) {

  }
};

int main() {
  CSRGraph g(1000, 2000);
  g(1,3) = 1.5;           // g('from index', 'to index') = 'given weight'
  g.setW(1,3,1.5);
  ifstream f("graph.dat");
  f >> g;
  //g.binarySave("graph.grx")

}