#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class grafo{
    
public:
    
    int cor;
    short visitado;
    
    grafo(){
        cor = -1;
        visitado = 0;
    }
    
};

/*
 *Método que percorre vértices e seus adjacentes ainda não visitados
 */
void visitaVertice(int v, grafo vertices[], int **adjacencia, int n){
    //visitado = 1 (este vértice foi visitado, mas pode conter adjacentes ainda não visitados)
    vertices[v].visitado = 1;
    /*
     *Visita cada vértice adjacente ainda não visitado
     */
    for(int i = 0; i < n; i++){
        if(adjacencia[v][i] == 1){ 
            if(vertices[i].visitado == 0){
                visitaVertice(i,vertices, adjacencia,n);
            }
        }
    }
    //visitado = 2 (todos seus adjacentes já foram visitados)
    vertices[v].visitado = 2;
}

/*
 *Método para verificar se é possível adicionar p arestas no grafo, de modo que o grafo
  seja simples, conexo e nehuma aresta conecte dois vértices da mesma cor
 */
bool consultaPossibilidade(int n, int p, grafo vertices[], int **adjacencia){
    int componentes = 0;
    for(int i = 0; i < n; i++){
        /*
         *Atribui-se adjacencia nos vértices que possuem cores distintas
         */
        for(int j = 0; j < n; j++){
            if((p > 0) && (i != j) && (adjacencia[i][j] == 0) && (vertices[i].cor != vertices[j].cor)){
                adjacencia[i][j] = 1;
                p--;
            }
        }
    }
    /*
     *Calcula o número de componentes do grafo.
     */
    for(int i = 0; i < n; i++){
        if(vertices[i].visitado == 0){ 
            visitaVertice(i,vertices,adjacencia,n);
            componentes++;
        }
    }
    /*
     *Para que o grafo seja simples, o número de componentes deve ser igual a 1.
      Caso p seja maior que 0, há pelo menos um vértice conectado a outro com a mesma cor.
     */
    if(p > 0 || componentes > 1){
        return false;
    }else{
        return true;
    }
}

int main() {
    int t, n, m, p, k, vertice1, vertice2;
    bool possibilidade;
    cin >> t;
    while(t > 0){
        cin >> n;
        cin >> m;
        cin >> p;
        cin >> k;
        grafo vertices[n];
        int **adjacencia;
        /*
         *Alocação da matriz de adjacencia
         */
        adjacencia = (int **) malloc(n * sizeof(int *));
        for(int i = 0; i < n; i++){
            adjacencia[i] = (int *)malloc(n * sizeof(int));
            for(int j = 0; j < n; j++){
                adjacencia[i][j] = 0;
            }
        }
        //Lê a cor de cada vértice
        for(int i = 0; i < n; i++){
            cin >> vertices[i].cor;
        }
        /*
         *Atribui adjacencia entre os vértices
         */
        for(int i = 0; i < m; i++){
            cin >> vertice1;
            cin >> vertice2;
            adjacencia[vertice1-1][vertice2-1] = 1;
            adjacencia[vertice2-1][vertice1-1] = 1;
        }
        possibilidade = consultaPossibilidade(n,p,vertices,adjacencia);
        if(possibilidade){
            cout << "Y" << endl << endl;
        }else{
            cout << "N" << endl << endl;
        }
        t--;
    }
    return 0;
}