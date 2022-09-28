#include<iostream>
#include<vector>
using namespace std;

void heapify(vecter<int> &v, int father, int end) {
  int leftchild = father * 2 + 1;
    int rightchild = father * 2 + 2;
    if (leftchild < end ){
        if (rightchild < end ){
            // if all exist
            if (v[leftchild] < v[rightchild]){
                if (v[rightchild] > v[father]){
                    swap(v[father], v[rightchild]);
                    make_a_heap(v, rightchild, end);
                }
            }
            else {
                if (v[leftchild] > v[father]){
                    swap(v[father], v[leftchild]);
                    make_a_heap(v, leftchild, end);
                }
            }
        }
        else {
            if (v[leftchild] > v[father]){
                swap(v[father], v[leftchild]);
            }
        }
    }
    return ;
}
void make_heap(vector<int> &v){
    for (int i = v.size() - 1; i >= 0; i--){
        make_a_heap(v, i, v.size() );
    }
}

void heap_sort(std::vector<int> &v){
    make_heap(v);
    for (int i = v.size()-1; i >= 0; --i){
        swap(v[0], v[i]);
        make_a_heap(v, 0, i);
    }
    print_arr(v);
}
