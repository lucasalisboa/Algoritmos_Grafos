# Algoritmos_Grafos
Repositório para algoritmos destinados à disciplina Teoria dos Grafos ministrada pelo professor Rian Gabriel Santos Pinheiro.

## Equipe
Lucas A. Lisboa e José Rubens da Silva Brito

## Algoritmos Implementados
* Dijkistra;
* Bellman-Ford;
* Ford-Fulkerson;
* Kruskal.

## Orientações para Execução
1. Compile a classe do algoritmo desejado. Para isto, utilize o comando:
  ```g++ nome_da_classe.cpp -o nome_do_executavel```
2. Execute o programa, passando como parâmetro o nome do arquivo de entrada. Para isto, utilize o comando:
  ```./nome_do_executavel arquivo_de_entrada```
  
## Modelo do Arquivo de Entrada
O arquivo deve estar no mesmo diratório (pasta) da classe a ser executada. A primeira linha do arquivo deve conter dois valores inteiros separados por espaço: _n_ e _m_, sendo _n_ o número de vértices e _m_ o número de arestas. Após isto, o arquivo deve conter _m_ linhas, tendo cada linha 3 valores inteiros separados por espaço: _v1_, _v2_ e _peso_, sendo _v1_ o vértice de origem, _v2_ o vértice de destino e _peso_ o peso ou capacidade da aresta. Para mais detalhes, consultar o arquivo _input.txt_.
