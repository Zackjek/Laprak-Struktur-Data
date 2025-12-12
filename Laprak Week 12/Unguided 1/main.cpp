#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // 1. Insert Node A sampai H
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    // 2. Connect Node (Undirected)
    
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');

   
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');

    
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    // Tampilkan Graph
    cout << "=== TAMPILAN GRAPH (Undirected) ===" << endl;
    printGraph(G);

    return 0;
}