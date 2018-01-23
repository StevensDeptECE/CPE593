import java.util.*;

public class GraphList {
	private static class Edge {
    int v2;
		double w;
		public Edge(int v2, double w) { this.v2 = v2; this.w = w; }
	}

	private ArrayList< LinkedList<Edge> > edges;
	private int V;

	public GraphList(int V) {
		this.V = V;
		edges = new ArrayList<>(V);
		for (int i = 0; i < V; i++)
			edges.add(new LinkedList<Edge>());
	}
	public void set(int i, int j, double w) {
		LinkedList<Edge> edgei = edges.get(i);
		for (Edge e : edgei) {
			if (e.v2 == j) {
				e.w = w;
				return;
			}
		}
		edgei.add(new Edge(j, w));
	}
	public double get(int i, int j) {
		for (Edge e : edges.get(i)) {
			if (e.v2 == j)
				return e.w;
		}
		return Double.POSITIVE_INFINITY;
	}
	public void DFS(int v) {
		boolean[] visited = new boolean[V];
		DFS2(v, visited);
	}
	private void DFS2(int v, boolean[] visited) {
    visited[v] = true;
		System.out.print(v);
		for (Edge e : edges.get(v) ) {
			if (!visited[e.v2]) {
				DFS2(e.v2, visited);
			}
		}
	}
	public void iterativeDFS(int v) {
		boolean[] visited = new boolean[V];
		Stack<Integer> todo = new Stack<>();
    todo.push(v);
		visited[v] = true;;
		while (!todo.isEmpty()) {
			int v2 = todo.pop();
			System.out.print(v2);
			LinkedList<Edge> adjacent = edges.get(v2);
			for (Edge e : adjacent) {
				if (!visited[e.v2]) {
					todo.push(e.v2);
					visited[e.v2] = true;
				}
			}
		}
	}

	public static void main(String[] args) {
    GraphList gl = new GraphList(5);
		gl.set(0, 1, 1.5);
		gl.set(1, 2, 2.0);
		gl.set(2, 3, 2.5);
		gl.set(3, 4, 3.0);
		gl.DFS(0);
		System.out.println();
		gl.iterativeDFS(0);
		System.out.println();
	}
}
