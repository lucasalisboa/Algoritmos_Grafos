BELLMAN_FORD = "BellmanFord.cpp"
KRUSKAL = "Kruskal.cpp"
DIJKSTRA = "Dijkstra.cpp"
Ford_Fulkerson = "FordFulkerson.cpp"

bellmanFord:
	g++ 	$(BELLMAN_FORD)	 -o		bellmanFord

kruskal:
	g++ 	$(KRUSKAL)	 -o		kruskal

dijkstra:
	g++ 	$(DIJKSTRA)	 -o		dijkstra

FordFulkerson:
	g++ 	$(Ford_Fulkerson)	 -o		fordFulkerson

