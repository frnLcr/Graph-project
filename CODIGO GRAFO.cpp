#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int n) {
        numNodes = n;
        adjacencyMatrix.resize(n, vector<int>(n, 0));  // Inicializar matriz con 0s
    }

    void addEdge(int fromNode, int toNode) {
        int op;
        int peso;
        // Añadir una arista entre fromNode y toNode (no dirigido)
        cout << "La conexion tiene peso? Si (1) - No (0)" << endl;
        cin >> op;
        if (op != 1)
        {
            adjacencyMatrix[fromNode][toNode] = 1;  // dirigido
            adjacencyMatrix[toNode][fromNode] = 1;  // Si es no dirigido


        }
        else
        {
            cout << "Ingrese el peso de la conexion" << endl;
            cin >> peso;
            adjacencyMatrix[fromNode][toNode] = peso;  // dirigido
            adjacencyMatrix[toNode][fromNode] = peso;  // Si es no dirigido
        }

    }
    void addEdgediriguido(int fromNode, int toNode) {
        int peso, op;
        cout << "La conexion tiene peso? Si (1) - No (0)" << endl;
        cin >> op;
        // Añadir una arista entre fromNode y toNode (no dirigido)
        if (op != 1) {

            adjacencyMatrix[fromNode][toNode] = 1;  // dirigido
        }
        else {
            cout << "Ingrese el peso de la conexion : " << endl;
            cin >> peso;
            adjacencyMatrix[fromNode][toNode] = peso;  // dirigido
        }


    }

    void printGraph() {
        system("cls");
        cout << "Matriz de Adyacencia:" << endl;
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void menunodirigido();
void dirigido();

void menunodirigido()
{
    int us1;
    int us2;
    int us3;
    int peso;
    int numNodes;
    cout << "Cuantos nodos son?" << endl;
    cin >> numNodes;
    Graph graph(numNodes);
    do
    {
        cout << "Que nodos se conectan?" << endl;
        cin >> us1;
        cout << "Con que nodo lo quiere conectar?" << endl;
        cin >> us2;
        graph.addEdge(us1, us2);
        cout << "Tiene mas conexiones? Si (1) - No (0)" << endl;
        cin >> us3;

    } while (us3 != 0);
    graph.printGraph();
}
void dirigido()
{
    int us1;
    int us2;
    int us3;
    int numNodes;

    cout << "Cuantos nodos son?" << endl;
    cin >> numNodes;
    Graph graph(numNodes);
    do
    {
        cout << "Que nodos se conectan?" << endl;
        cin >> us1;
        cout << "Con que nodo lo quiere conectar?" << endl;
        cin >> us2;
        graph.addEdgediriguido(us1, us2);
        cout << "Tiene mas conexiones? Si (1) - No (0)" << endl;
        cin >> us3;
    } while (us3 != 0);
    graph.printGraph();
}
int main() {
    int op;
    cout << "           GRAFO          " << endl;
    cout << "    --------------------- " << endl;
    cout << "   | 1  NO DIRIGIDO      |" << endl;
    cout << "   | 2  DIRIGIDO         |" << endl;
    cout << "    --------------------- " << endl;
    cout << "        Digite la opcion correspondiente: ";
    cin >> op;
    switch (op)
    {
    case 1:
        system("cls");
        cout <<"NO DIRIGIDO" << endl;
        menunodirigido();
        break;
    case 2:
        system("cls");
        cout << "DIRIGIDO" << endl;
        dirigido();
        break;
    }
    return 0;
}