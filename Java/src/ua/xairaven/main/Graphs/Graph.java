package ua.xairaven.main.Graphs;

import edu.princeton.cs.algs4.In;
import ua.xairaven.main.DataStructures.Bags.Bag;

public class Graph {
    private final int V;
    private int E;
    private Bag<Integer>[] adjacency;

    // Constructor. V vertices, 0 edges
    public Graph(int V) {
        if (V < 0) throw new IllegalArgumentException("number ov vertices have to be >= 0");
        this.V = V;
        this.E = 0;
        adjacency = (Bag<Integer>[]) new Bag[V];
        for (int v = 0; v < V; v++) {
            adjacency[v] = new Bag<>();
        }
    }

    // Constructor. Initialise graph from input
    public Graph(In in) {
        this(in.readInt());
        int E = in.readInt();
        if (E < 0) throw new IllegalArgumentException("number of edges have to be >= 0");
        for (int i = 0; i < E; i++) {
            int v = in.readInt();
            int w = in.readInt();
            addEdge(v, w);
        }
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    public void addEdge(int v, int w) {
        if (v < 0 || v >= V) throw new IndexOutOfBoundsException("vertex " + v + " is not between 0 and " + (V-1));
        if (w < 0 || w >= V) throw new IndexOutOfBoundsException("vertex " + v + " is not between 0 and " + (V-1));
        adjacency[v].add(w);
        adjacency[w].add(v);
        E++;
    }
}