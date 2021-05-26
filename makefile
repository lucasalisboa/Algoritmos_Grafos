BELLMAN_FORD = "BellmanFord.cpp"
KRUSKAL = "Kruskal.cpp"
DIJKSTRA = "Dijkstra.cpp"
Ford_Fulkerson = "FordFulkerson.cpp"

bellmanFord:
	g++ 	$(BELLMAN_FORD)	 -o		bellmanFord.exe

kruskal:
	g++ 	$(KRUSKAL)	 -o		kruskal.exe

dijkstra:
	g++ 	$(DIJKSTRA)	 -o		dijkstra.exe

fordFulkerson:
	g++ 	$(Ford_Fulkerson)	 -o		fordFulkerson.exe

