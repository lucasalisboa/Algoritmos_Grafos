BELLMAN_FORD = "bellmanFord.cpp"
KRUSKAL = "kruskal.cpp"
DIJKSTRA = "dijkstra.cpp"
PRIM = "prim.cpp"

bellmanFord:
	g++ 	$(BELLMAN_FORD)	 -o		bellmanFord

kruskal:
	g++ 	$(KRUSKAL)	 -o		kruskal

dijkstra:
	g++ 	$(DIJKSTRA)	 -o		dijkstra

prim:
	g++ 	$(PRIM)	 -o		prim

