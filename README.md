# Graph Cycle Detection

This repository contains a C++ implementation for solving the following problem:

**Problem Statement:**
Given a connected undirected graph and a specific edge \(e\), determine whether \(e\) is part of a cycle. The solution has a time complexity of \(O(m + n)\), where \(m\) is the number of edges and \(n\) is the number of vertices in the graph.

## Approach
The solution involves the following steps:

1. **Remove the Edge**:
   Remove the given edge \(e\) (connecting vertices \(v\) and \(w\)) from the graph.

2. **Breadth-First Search (BFS):**
   Start BFS from one of the vertices of the edge (e.g., \(v\)). Check if there exists a path to the other vertex \(w\). If such a path exists, then the edge \(e\) is part of a cycle; otherwise, it is not.

   BFS is implemented using a queue to store open vertices and a visited array to mark visited vertices. The time complexity is achieved as described in the book *Introduction to Algorithms* by Cormen et al.

## Files
The implementation is split into three files for clarity and modularity:

- **`graph.h`**: Interface for the graph data structure.
- **`graph.cpp`**: Implementation of the graph interface.
- **`main.cpp`**: Client program for loading a graph, parsing input, and determining if an edge is part of a cycle.

Additionally, a PowerPoint presentation explaining the solution is included.

## Input Format
Graphs are read from a `data.txt` file with the following format:

- The first line contains an integer \(V\), representing the number of vertices in the graph. Vertices are indexed from 0 to \(V-1\).
- Each subsequent line contains two integers, separated by a space, representing an edge between two vertices.

### Example `data.txt` File
```
5
0 1
1 2
2 3
3 4
4 0
```

## Compilation
Compile the program using the following command:

```bash
g++ -o cycle_detection main.cpp graph.cpp
```

## Running the Program
Provide the edge to be checked as a command-line argument:

```bash
./cycle_detection edge_start edge_end
```

### Example
To check if the edge `(0, 1)` is part of a cycle:

```bash
./cycle_detection 0 1
```

## Notes
- The file `data.txt` must not contain duplicate edges. This limitation is not explicitly handled in the current implementation.
- An alternative, direct way of initializing the graph (via hardcoding) is available in `main.cpp`, but it is commented out for simplicity.

## Testing
To test the program:
1. Prepare a `data.txt` file in the specified format.
2. Compile and run the program with various edge inputs to observe the results.

---

Feel free to explore the implementation and provide feedback or suggestions.
