class Graph {
    private:
       // implementation
    public:
};

DFS(v) {
    visited <-- []
    DFS2(v, visited)
}

DFS2(v, visited) {
    visited[v] = true
    foreach v2 adjacent to v
      if visited[v2] != true
          DFS2(v2, visited)
      end
}

//  1 --> 2,3,4
//  2 --> 1, 3, 4
//  3 --> 1,2 4
//  4 --> 1,2,3
// DFSIterative(1)
// visited[1,4]
// planned = [2,3, 2, 2, ]

// DFSIterative(1)
// scheduled[1,2,3,4] = true
// planned = [2,3 ]


DFSIterative(v) {
    scheduled <-- [v]
    planned = new Stack()
    planned.push(v)
    while NOT planned.isEmpty() {
        v = planned.pop()
        print v
        foreach v2 adjacent to v  //O(V-1) = O(V)
           if NOT scheduled[v2]
              planned.push(v2)
              scheduled[v] = true
           end
    }

}

BFS(v)
  scheduled <-- [v]
  planned = new Queue();
  planned.enqueue(v); // one thing in the queue
  while NOT planned.empty()
    v = planned.dequeue()
    foreach v2 adjacent to v
      if NOT scheduled[v2]
        planned.enqueue(v2)
      end 
    end 
  end
end

}