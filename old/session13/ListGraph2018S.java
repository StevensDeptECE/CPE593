import java.util.*;
import java.io.*;

public class ListGraph2018S {
	private static class Edge {
		int to;
		double w;
		public Edge(int to, double w) { this.to = to; this.w = w; }
	}
	private ArrayList<Edge> [] vertices; // vertices.length == V
	public ListGraph2018S(int V) {
		vertices = new ArrayList[V];
		for (int i = 0; i < V; i++)
			vertices[i] = new ArrayList<Edge>();
	}
	public ListGraph2018S(String filename) throws IOException {
		Scanner s = new Scanner(new FileReader(filename));
		int V = s.nextInt();
		vertices = new ArrayList[V];
		int from, to;
		double w;
		while (s.hasNext()) {
			from = s.nextInt(); to = s.nextInt(); w = s.nextDouble();
			System.out.println("From: " + from + "\tto:" + to + " w=" + w);
			vertices[from].add(new Edge(to, w));
		}
	}
	public double adjacent(int i, int j) {
		ArrayList<Edge> e = vertices[i];
		for (int k = 0; k < e.size(); k++)
			if (e.get(k).to == j)
				return e.get(k).w;
		return Double.POSITIVE_INFINITY;
	}
  public boolean isAdjacent(int i, int j) {
		ArrayList<Edge> e = vertices[i];
		for (int k = 0; k < e.size(); k++)
			if (e.get(k).to == j)
				return true;
		return false;
	}

	public void dfs(int v) {
		boolean[] visited = new boolean[vertices.length];
		dfs(v, visited);
	}
	private final void dfs(int v, boolean[] visited) {
		System.out.print(v + " ");
		visited[v] = true;
		for (int i = 0; i < vertices[v].size(); i++) {
			Edge e = vertices[v].get(i);
			if (!visited[e.to])
				dfs(e.to, visited);
		}
	}

	public void dfsIterativeWrong(int v) {
		boolean [] visited = new boolean[vertices.length];
		Stack<Integer> todo = new Stack<>();
    todo.push(v);

		while (!todo.isEmpty()) {
			v = todo.pop();
      visited[v] = true;
			System.out.println(v + " ");

      for (int i = 0; i < vertices[v].size(); i++) {
				Edge e = vertices[v].get(i);
				if (!visited[e.to])
					todo.push(e.to);
			}	
		}
	}

	public void dfsIterativeRight(int v) {
		boolean [] visited = new boolean[vertices.length];
		Stack<Integer> todo = new Stack<>();
    todo.push(v);
		visited[v] = true;

		while (!todo.isEmpty()) {
			v = todo.pop();
			System.out.print(v + " ");
      for (int i = 0; i < vertices[v].size(); i++) {
				Edge e = vertices[v].get(i);
				if (!visited[e.to]) {
					todo.push(e.to);
					visited[e.to] = true; // do not push this again
				}
			}	

		}
	}

	public static void main(String[]args) throws IOException {
		ListGraph2018S g = new ListGraph2018S("listgraph.dat");
		g.dfs(0);
		
	}
}
