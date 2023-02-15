class Rope {
    struct node {
        char c; // the letter!
        int size; // size of the left subtree
        node* left;
        node* right;

    }

};


/* this is a test
         s,7
        /
       i,2
      / \
    h,1    s
   /      \
  t,0        ' '
    n letters in a document
    k people viewing the document

    insertion O(log n) + O(k)


*/

class Chain {
    struct node {
        node* next[4];
        string line; // the letter!
        int size; // size of the left subtree
    };

    vector<range> viewers;

    class iterator { // position within a chain

    };

    class range {
        iterator start;
        uint32_t len;
    };

    class window {


    };
};


int main() {
  string a = "abcd";
  a += "efg"; // "abcdefg"
  a.insert(2, "xxx"); // "abcxxxdefg" //O(n)


  Rope r;
  r.add("abc"); // O(log n)

// fast load a large file
  for (int i = 0; i < 100000000; i++)
    r.add("kjashfkjdfh kasjhdf kashjdf kasdfhj");



}