#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> bellmanFord(int vertices, const vector<Edge>& edges){
    vector<int> distance(vertices, INT_MAX);
    distance[0] = 0;

    for (int i = 0; i < vertices - 1; i++){
        for (const Edge& edge : edges){
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]){
                distance[edge.v] = distance[edge.u] + edge.weight;
            }
        }
    }
    return distance;
}

bool negativeCycle(int vertices, const vector<Edge>& edges){
    vector<int> distance(vertices, 0);
    
    for(int i = 0; i < vertices; i++){
        for (const Edge& edge : edges){
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]){
                distance[edge.v] = distance[edge.u] + edge.weight;

                if (i == vertices - 1){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int vertices, edgesCount;
    cin >> vertices >> edgesCount;

    vector<Edge> edges(edgesCount);
    for (int i = 0; i < edgesCount; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    if (negativeCycle(vertices, edges)){
        cout << "FALSE" << endl;
    } else {
        vector<int> distances = bellmanFord(vertices, edges);
        cout << "TRUE" << endl;
        for (int i = 0; i < vertices; i++){
            if (distances[i] == INT_MAX){
                cout << "INFINITY" << endl;
            } else {
                cout << distances[i] << endl;
            }
        }
    }
    return 0;
}
