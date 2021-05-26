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
 
void dijkstra(int s){              //algoritmo de Dijkstra
	inf(); 
	dis[s] = 0;
	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({0, s});
 
	//Calcula o menor Caminho
	while(!pq.empty()){
		auto f = pq.top();
		pq.pop();
		if(dis[f.second] < f.first) continue;    
		for(auto e : grafo[f.second]){               
			if(f.first + e.second < dis[e.first]){   
				dis[e.first] = f.first + e.second;   
				pq.push({dis[e.first], e.first});    
			}
		}
	}
	printf("Algoritmo de Dijkistra para o vertice %d\n",s);
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
	dijkstra(s);
	fclose(file);

	return 0;
}