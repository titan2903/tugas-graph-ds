#include <iostream>
#include <vector>
#include <queue>

// ===================================================================
// IMPLEMENTASI 1: ADJACENCY MATRIX
// ===================================================================
class GraphMatrix {
private:
    int V; // Jumlah simpul
    int** adjMatrix; // Pointer ke pointer untuk matriks 2D

    // Fungsi utilitas untuk DFS
    void DFSUtil(int u, bool visited[]) {
        visited[u] = true;
        std::cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] == 1 && !visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

public:
    // Konstruktor
    GraphMatrix(int vertices) {
        V = vertices;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; // Inisialisasi dengan 0
            }
        }
    }

    // Menambah sisi (untuk graf tidak berarah)
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Traversal BFS
    void BFS(int startNode) {
        bool* visited = new bool[V](); // Inisialisasi semua elemen ke false
        std::queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << " ";

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        delete[] visited;
    }

    // Traversal DFS
    void DFS(int startNode) {
        bool* visited = new bool[V](); // Inisialisasi semua elemen ke false
        DFSUtil(startNode, visited);
        delete[] visited;
    }

    // Destruktor untuk membersihkan memori
    ~GraphMatrix() {
        for (int i = 0; i < V; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

// ===================================================================
// IMPLEMENTASI 2: ADJACENCY LIST
// ===================================================================
class GraphList {
private:
    int V; // Jumlah simpul
    std::vector<int>* adjList; // Pointer ke array vector

    // Fungsi utilitas untuk DFS
    void DFSUtil(int u, bool visited[]) {
        visited[u] = true;
        std::cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

public:
    // Konstruktor
    GraphList(int vertices) {
        V = vertices;
        adjList = new std::vector<int>[V];
    }

    // Menambah sisi (untuk graf tidak berarah)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Traversal BFS
    void BFS(int startNode) {
        bool* visited = new bool[V]();
        std::queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << " ";

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        delete[] visited;
    }

    // Traversal DFS
    void DFS(int startNode) {
        bool* visited = new bool[V]();
        DFSUtil(startNode, visited);
        delete[] visited;
    }
    
    // Destruktor untuk membersihkan memori
    ~GraphList() {
        delete[] adjList;
    }
};


// ===================================================================
// FUNGSI MAIN UNTUK Execute
// ===================================================================
int main() {
    int numVertices = 6;

    // --- Execute Adjacency Matrix ---
    std::cout << "*** Implementasi Adjacency Matrix ***" << std::endl;
    GraphMatrix g_matrix(numVertices);
    g_matrix.addEdge(0, 1);
    g_matrix.addEdge(0, 2);
    g_matrix.addEdge(1, 3);
    g_matrix.addEdge(1, 4);
    g_matrix.addEdge(2, 4);
    g_matrix.addEdge(4, 5);

    std::cout << "Hasil BFS (mulai dari 0): ";
    g_matrix.BFS(0);
    std::cout << std::endl;

    std::cout << "Hasil DFS (mulai dari 0): ";
    g_matrix.DFS(0);
    std::cout << std::endl;

    std::cout << "\n----------------------------------------\n" << std::endl;

    // --- Execute Adjacency List ---
    std::cout << "*** Implementasi Adjacency List ***" << std::endl;
    GraphList g_list(numVertices);
    g_list.addEdge(0, 1);
    g_list.addEdge(0, 2);
    g_list.addEdge(1, 3);
    g_list.addEdge(1, 4);
    g_list.addEdge(2, 4);
    g_list.addEdge(4, 5);

    std::cout << "Hasil BFS (mulai dari 0): ";
    g_list.BFS(0);
    std::cout << std::endl;

    std::cout << "Hasil DFS (mulai dari 0): ";
    g_list.DFS(0);
    std::cout << std::endl;

    return 0;
}