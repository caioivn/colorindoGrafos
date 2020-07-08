Problema:

Seja G um grafo simples com N vértices coloridos e M arestas. Nós desejamos saber se é possível adicionar exatamente P arestas em G de tal forma que o grafo resultante seja simples, conexo e nenhuma aresta conecte dois vértices da mesma cor.

Entrada:

A entrada contém múltiplos casos testes. A primeira linha contém a quantidade de casos testes T (T < 70). Cada caso teste começa com 4 inteiros na seguinte ordem: o número de vértices N (1 <= N <= 10 3 ), o número de arestas no grafo original M (0 <= M <= 10 5 ), o número de arestas a serem inseridas P (0 <= P <= 10 6 ) e o número de cores K (1 <= K <= 10 3 ). A linha seguinte contém N números X i indicando a cor do i-ésimo vértice (1 <= X i <= K). As M seguintes linhas contém um par de inteiros (V i , V j ) indicando a presença de uma aresta entre os vértices V i e V j . (1 <= V i ,V j <= N).

Saída:

Para cada caso teste, imprima uma única lina com "Y" (sem aspas) se é possível construir tal grafo ou "N" caso contrário.
