#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;   

vector<vector<pair<int, int>>> grafo;

int n;               // número de nós
int m;
int dis[150000];

 
void inf(){                          //infinitar as distâncias
	for(int i = 0; i < n; ++i){
		dis[i] = INF;
	}
}
 
void adicionar_aresta(int v1, int v2, int peso){    //aresta com peso
	grafo[v1].push_back({v2,peso});
}
 
void dijkstra(int s){               //algoritmo de dijkstra
	inf(); 
	dis[s] = 0;
	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({0, s});
 
	while(!pq.empty()){
		auto f = pq.top();
		pq.pop();
		if(dis[f.second] < f.first) continue;    //dis[node] < dis[atual sendo checada] (para aprimoramento),i.e se esse no ja tiver uma distancia menor  
		for(auto e : grafo[f.second]){               //checar arestas 
			if(f.first + e.second < dis[e.first]){   //e.second = c (peso da aresta) | e.first = próximo nó 
				dis[e.first] = f.first + e.second;   //atualizando a distanca minima do próximo nó (aprimoramento)
				pq.push({dis[e.first], e.first});    
			}
		}
	}
	printf("Algoritmo de Dijkistra para o vertice %d",s);
	for (int i=0; i<n; i++)
	{
		printf("%d: %d",i,dis[i]);
	}
	
}

bool checkFileExistence(string filename) {
    ifstream f(filename);
    return f.is_open();
}

bool getFile(int argc, char *argv[], ifstream& file) {   
    
    if (argc <= 1) {
        cout << "Argumentos Incorretos" << endl;
        return false;
    } else if (!checkFileExistence(argv[1])) {
        cout << "Arquivo " << argv[1] << " Nao Encontrado" << endl;
        return false;
    }

    file.open(argv[1]);
    return true;
}


int main(int argc, char *argv[]){
	ifstream file;
	if(!getFile(argc, argv, file)) {
        exit(0);
    }
	file >> n;
	file >> m;
	int v1,v2,peso;
	for(int i = 0; i < m; i++){
		file >> v1;
		file >> v2;
		file >> peso;
		adicionar_aresta(v1,v2,peso);
	}
	int s = 0;
	dijkstra(s);
	file.close();
	return 0;
}
