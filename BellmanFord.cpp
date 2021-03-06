#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

const int INF = 1000000000;   

vector<vector<pair<int, int>>> grafo;

int n;               // número de nós
int m;				// número de arestas
int dis[150000];

 
void inf(){                          //infinitar as distâncias
	for(int i = 0; i < n; ++i){
		dis[i] = INF;
	}
}
 
void adicionar_aresta(int v1, int v2, int peso){    
	grafo[v1].push_back({v2,peso});
}
 
void bellmanFord(int s){              //algoritmo de BellmanFord
	inf(); 
	dis[s] = 0;
	
	// Calcula menor caminho
	for (int i = 0; i < n - 1; i ++){
    for (int u = 0; u < n; u ++){
      for (auto &v: grafo[u]){
        if (dis[u] + v.second < dis[v.first]){
          dis[v.first] = dis[u] + v.second; 
        }
      }
    }
  }

  // Verifica se há ciclo negativo
  for (int u = 0; u < n; u ++){
    for (auto &v: grafo[u]){
      if (dis[u] + v.second < dis[v.first]){
         printf("Tem ciclo negativo\n");
		 return;
      }
    }
}
	printf("Algoritmo de BellmanFord para o vertice %d\n",s);
	for (int i=0; i<n; i++)
	{
		printf("%d: %d\n",i,dis[i]);
	}
}

int main(int argc, char *argv[]){
	FILE *file;
	file = fopen(argv[1], "r");

	if (file == NULL){
   		printf("Arquivo nao Encontrado\n");
   		return 0;
	}

	fscanf(file,"%d %d\n",&n,&m);
	vector<pair<int, int>> iniciar;
	for(int i = 0; i < n; i++){
		grafo.push_back(iniciar);
	}

	int v1,v2,peso;
	for(int i = 0; i < m; i++){
		fscanf(file,"%d %d %d\n",&v1,&v2,&peso);
		adicionar_aresta(v1,v2,peso);
	}
	int s = 0;
	bellmanFord(s);
	fclose(file);

	return 0;
}