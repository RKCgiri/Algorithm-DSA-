#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  // A large value representing infinity
int graph[100][100];
int V;
int P[100][100];  // Path matrix

void APSP(int P[][100], int i, int j) {
    if (i == j) {
        cout << i << " ";
        return;
    } else if (P[i][j] == -1) {
        cout << "There is no path" << endl;
        return;
    } else {
        APSP(P, i, P[i][j]);
        cout << j << " ";
    }
}

void printGraph() {
    cout << "The graph is=" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void FloydWarshall() {
    int G[100][100];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                G[i][j] = 0;
                P[i][j] = i;
            } else if (graph[i][j] != 0) {
                G[i][j] = graph[i][j];
                P[i][j] = i;   //must set the parent previouly
            }
			// else {
//                G[i][j] = INF;
//                P[i][j] = -1;
//            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }

    cout << "The updated matrix is " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (G[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << G[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "All paths from source to ==>" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << "Path from " << i << " to " << j << ": ";
                if (P[i][j] == -1) {
                    cout << "No path" << endl;
                } else {
                    APSP(P, i, j);
                    cout << endl;
                }
            }
        }
    }
}

int main() {
    fstream file;
    file.open("Graph.txt");
    if (!file) {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    file >> V;
    cout << V << endl;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            file >> graph[i][j];
        }
    }
    printGraph();

    FloydWarshall();

    file.close();
    return 0;
}
