#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;               // número de nós
int m;               // número de arestas


void make_set(vector<int>& parent){

    for (int i=0; i < parent.size(); i++)
        parent[i] = i;
}

int find(vector<int>& parent, int x){

    if(x != parent[x])
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void union_set(vector<int>& parent, vector<int>& rank, int x, int y){

    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX == rootY)
        return;
    if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else{
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
            rank[rootY]++;
    }
}

bool comp(const tuple<int,int,int>& a, const tuple<int,int,int>& b){

    int first = get<2>(a);
    int second = get<2>(b);
    if (first < second)
        return true;
    
    return false;
}

vector<tuple<int,int,int>> kruskal(vector<vector<pair<int,int>>>& grafo,vector<tuple<int,int,int>>& arestas){
    
    vector<int> parent(grafo.size());
    vector<int> rank(grafo.size());

    vector<tuple<int,int,int>> result;
    make_set(parent);

    sort(arestas.begin(), arestas.end(), comp);
    
    for (tuple<int,int,int> t : arestas){
        int u = get<0>(t);
        int v = get<1>(t);
        int weight = get<2>(t);
        if (find(parent,u) != find(parent,v)){
            result.emplace_back(make_tuple(u,v, weight));
            union_set(parent, rank, u, v);
        }
    }
    return result;
}

void adicionar_aresta(vector<vector<pair<int,int>>>& grafo, vector<tuple<int,int,int>>& arestas,int u, int v, int w){
    
    grafo[u].push_back(make_pair(v, w));
    grafo[v].push_back(make_pair(u, w));
    arestas
    .emplace_back(make_tuple(u,v,w));
}

int main(int argc, char *argv[]){

    FILE *file;
	file = fopen(argv[1], "r");

	if (file == NULL){
   		printf("Arquivo nao Encontrado\n");
   		return 0;
	}

	fscanf(file,"%d %d\n",&n,&m);   
    vector<vector<pair<int,int>>> grafo(n, vector<pair<int,int>>(n));
    
    vector<tuple<int,int,int>> arestas;
    int v1,v2,peso;
	
    for(int i = 0; i < m; i++){
		fscanf(file,"%d %d %d\n",&v1,&v2,&peso);
		adicionar_aresta(grafo,arestas,v1,v2,peso);
	}


    vector<tuple<int,int,int>> res = kruskal(grafo, arestas);
    cout << "Algoritmo de Kruskal: " << endl;
    int result = 0;
    for (tuple<int,int,int> t : res){
        cout << "(" << get<0>(t) << "-" << get<1>(t) << ") - " << get<2>(t) << endl;
        result += get<2>(t);
    }
    printf("Peso Total - %d\n", result);
    return 0;
}
