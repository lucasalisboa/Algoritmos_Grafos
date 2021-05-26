#include <iostream>
#include <vector>
#include <queue>

const int INF = 1000000000;  
int n;               // número de nós
int m;               // número de arestas

using namespace std;

int bfs(int source, int sink, vector<int>& parent, vector<vector<int>>& residualgrafo) {
    fill(parent.begin(), parent.end(), -1);
    int V = residualgrafo.size();
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int u = q.front().first;
        int capacidade = q.front().second;
        q.pop();
        for (int av=0; av < V; av++) {
            if (u != av && parent[av] == -1 && residualgrafo[u][av] != 0) {
                parent[av] = u;
                int min_cap = min(capacidade, residualgrafo[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({av, min_cap});
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>>& grafo, int s, int t) {
    vector<int> parent(grafo.size(), -1);
    vector<vector<int>> residualgrafo = grafo;
    int min_cap = 0, fluxo_maximo = 0;

    //Calcula Fluxo Máximo
    while (min_cap = bfs(s, t, parent, residualgrafo)) {
        fluxo_maximo += min_cap;
        int u = t;
        while (u != s) {
            int v = parent[u];
            residualgrafo[u][v] += min_cap;
            residualgrafo[v][u] -= min_cap;
            u = v;
        }
    }
    return fluxo_maximo;
}

void adicionar_aresta(vector<vector<int>> &grafo, int v1, int v2, int peso){    
	grafo[v1][v2] = peso;
}

int main(int argc, char *argv[]){

    FILE *file;
	file = fopen(argv[1], "r");

	if (file == NULL){
   		printf("Arquivo nao Encontrado\n");
   		return 0;
	}

	fscanf(file,"%d %d\n",&n,&m);
    
    vector<vector<int>> grafo(n, vector<int> (n, 0));

	int v1,v2,peso;
	for(int i = 0; i < m; i++){
		fscanf(file,"%d %d %d\n",&v1,&v2,&peso);
		adicionar_aresta(grafo,v1,v2,peso);
	}
	int s = 0;
    int t = n-1;
    printf("Algoritmo de FordFulkerson para o vertice %d e %d\n",s,t);
	printf("Fluxo Maximo: %d", ford_fulkerson(grafo, s,t));
	fclose(file);

	return 0;
    }
