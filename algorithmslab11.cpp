#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

void DFS(vector<int>* graph, bool* visited, vector<int>& f, int v);
void DFS2(vector<int>* gt, bool* visited, vector<int>& scc, int v);

void findSCC(int vertices, int edges){
    vector<int> * graph = new vector<int>[vertices];
    for (int i = 0; i < edges; i++){
        int u;
        int vert;
        cin >> u >> vert;
        graph[u].push_back(vert);
    }

    vector<int> * gt = new vector<int>[vertices];
    for(int i = 0; i < vertices; i++){
        for (int j = 0; j < graph[i].size(); j++){
            int u = i;
            int vert = graph[i][j];
            gt[vert].push_back(u);
        }
    }

    bool* visited = new bool[vertices];
    vector<int> f;
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    for (int i = 0; i < vertices; i++){
        if(!visited[i]){
            DFS(graph, visited, f, i);
        }
    }

    reverse(f.begin(), f.end());

    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    vector<int> scc;
    int sccid = 0;
    int* res = new int[vertices];
    for(int i = 0; i < vertices; i++){
        int vert = f[i];
        if(!visited[vert]){
            scc.clear();
            DFS2(gt, visited, scc, vert);
            sccid = *min_element(scc.begin(), scc.end());
            for(int j = 0; j < scc.size(); j++){
                res[scc[j]] = sccid;
            }
        }
    }

    for (int i = 0; i < vertices; i++){
        cout << res[i] << endl;
    }

    delete[] graph;
    delete[] gt;
    delete[] visited;
    delete[] res;
}

void DFS(vector<int>* graph, bool* visited, vector<int>& f, int v){
    visited[v] = true;
    for(int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i];
        if(!visited[u]){
            DFS(graph, visited, f, u);
        }
    }
    f.push_back(v);
}

void DFS2(vector<int>* gt, bool* visited, vector<int>& scc, int v){
    visited[v] = true;
    scc.push_back(v);
    for (int i = 0; i < gt[v].size(); i++){
        int u = gt[v][i];
        if(!visited[u]){
            DFS2(gt, visited, scc, u);
        }
    }
}

int main(){
    int vertices;
    int edges;
    
    cin >> vertices;
    cin >> edges;
    findSCC(vertices, edges);

    return 0;
}
