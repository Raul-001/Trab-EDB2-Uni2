# Heap

Este projeto implementa as seguintes funções de Heap e testa o algoritmo de ordenação HeapSort com diferentes tamanhos, além de compará-lo com outros algoritmos:

- **Alteração de prioridade**
- **Inserção**
- **Remoção (da raiz)**
- **Construção das heaps**

- **Implementação das funções**:
    - `funcoesHeap.cpp` - Implementação das funções Heap

---

## Ambiente Computacional

- **Linguagem utilizada**: C++ com o compilador gcc 13.3.0.
- **Hardware**:
  - 16 GB RAM DDR4
  - AMD® Ryzen 7 5700X3D (8 núcleos, 16 threads)
  - GeForce RTX™ 4060 Ti (8 GB GDDR6)
- **Sistema Operacional**: Ubuntu 22.04.5 LTS (64 bits)
- **Editor de código**: Visual Studio Code

---

## Pseudocódigo do HeapSort

    FUNÇÃO criarHeap(vetor, inicio, final)
    aux ← vetor[inicio]
    filho ← (inicio * 2) + 1

    ENQUANTO filho ≤ final FAÇA
        SE filho < final E (filho + 1) ≤ final ENTÃO
            SE vetor[filho] < vetor[filho + 1] ENTÃO
                filho ← filho + 1
            FIM_SE
        FIM_SE

        SE aux < vetor[filho] ENTÃO
            vetor[inicio] ← vetor[filho]
            inicio ← filho
            filho ← (2 * inicio) + 1
        SENÃO
            filho ← final + 1
        FIM_SE
    FIM_ENQUANTO

    vetor[inicio] ← aux
    FIM_FUNÇÃO

    FUNÇÃO heapSort(vetor, tamanho)
    PARA i ← (tamanho - 1) / 2 ATÉ 0 PASSO -1 FAÇA
        criarHeap(vetor, i, tamanho - 1)
    FIM_PARA

    PARA i ← tamanho - 1 ATÉ 1 PASSO -1 FAÇA
        aux ← vetor[0]
        vetor[0] ← vetor[i]
        vetor[i] ← aux
        criarHeap(vetor, 0, i - 1)
    FIM_PARA
    FIM_FUNÇÃO


## Análise de Desempenho de Algoritmos

![Comparação](img_comparativa/desempenhoAlgoritmos.pdf)

## Comparações

### **BubbleSort x HeapSort**

Em comparação com o Bubble Sort, o Heap Sort apresenta tempos de execução consideravelmente menores. Para 10.000 elementos, o Heap Sort leva cerca de 2,07 ms no modo iterativo e 1,52 ms no recursivo. Quando o tamanho da entrada é aumentado para 100.000, os tempos são de aproximadamente 29,89 ms (iterativo) e 21,94 ms (recursivo). Para 1.000.000 de elementos, o tempo de execução é de 722,95 ms no modo iterativo e 631,08 ms no recursivo. Esses números mostram que, mesmo para listas muito grandes, o Heap Sort continua com um desempenho muito eficiente.

A principal vantagem do Heap Sort em relação ao Bubble Sort é sua escalabilidade. Enquanto o Bubble Sort se torna impraticável para entradas grandes, o Heap Sort mantém um desempenho razoável e bastante consistente, mesmo quando o número de elementos aumenta consideravelmente. 

---

### **MergeSort x HeapSort**

Em comparação com o Merge Sort, o Heap Sort tem a vantagem de não exigir memória extra além da memória necessária para armazenar os dados, o que o torna mais eficiente em termos de espaço. Isso é particularmente vantajoso em sistemas com recursos limitados, já que o Heap Sort utiliza apenas o espaço da entrada original para ordenar os dados. No entanto, embora o Heap Sort tenha uma complexidade semelhante à do Merge Sort, ele tende a ser mais lento na prática, principalmente devido à constante troca de elementos dentro da heap, que pode resultar em um número maior de operações de leitura e escrita na memória.

Quando observamos os tempos de execução do Heap Sort para os diferentes tamanhos de entrada, vemos que ele é muito eficiente em comparação com o Merge Sort. Para 10.000 elementos, o Heap Sort leva cerca de 2,07 ms no modo iterativo e 1,52 ms no recursivo. Para 100.000 elementos, os tempos são de aproximadamente 29,89 ms no iterativo e 21,94 ms no recursivo. Já para 1.000.000 de elementos, o tempo de execução é de 722,95 ms no iterativo e 631,08 ms no recursivo. Esses tempos são bastante rápidos, especialmente para listas grandes, mas o Heap Sort pode ser ligeiramente mais lento que o Merge Sort, que leva 474,68 ms para 1.000.000 de elementos.

---

### **QuickSort x HeapSort**

Em termos de desempenho, o HeapSort é mais eficiente em termos de uso de memória, pois não requer a pilha de chamadas recursivas do QuickSort, que pode ser um problema quando se lida com grandes volumes de dados e pode até levar a um estouro de pilha se o algoritmo não for bem implementado (exemplo: não utilizando a versão de partição aleatória). O HeapSort também não exige memória extra para armazenar subarrays, enquanto o QuickSort pode precisar de espaço adicional para armazenar os subarrays durante a execução recursiva.

Para 10.000 elementos, o HeapSort leva cerca de 2,07 ms (iterativo) e 1,52 ms (recursivo), enquanto para 100.000 elementos, os tempos aumentam para 29,89 ms (iterativo) e 21,94 ms (recursivo). Para 1.000.000 de elementos, o tempo chega a 722,95 ms (iterativo) e 631,08 ms (recursivo). Embora os tempos de execução do HeapSort sejam razoáveis, ele tende a ser mais lento do que o QuickSort, especialmente em entradas maiores.

Um ponto importante a se considerar é que, embora o HeapSort seja mais eficiente em termos de uso de memória e complexidade de tempo no pior caso, o QuickSort ainda é geralmente mais rápido na prática, especialmente em listas grandes. O QuickSort tem um desempenho superior devido à sua eficiência de cache e menor número de comparações e trocas em média.

---

### **Estrutura do projeto**

Os arquivos e códigos da implementação estão dentro da pasta "heapsort". 
O projeto é composto pelo arquivo principal (`main.cpp`), que é responsável por realizar os testes dos algoritmos, 
que estão implementados em (`Algt.cpp`), e um cabeçalho (`Algt.h`) onde os algoritmos estão definidos. 

### **Principais Funcionalidades**
- **Medição de tempo**: O projeto mede o tempo de execução de cada algoritmo, realiza testes para cada instância,
calcula a média e registra o resultado em um arquivo .txt.
- **Algoritmos Implementados**:
  - Algoritmos de Ordenação:
    - Bubble Sort (Iterativo e Recursivo)
    - Merge Sort (Iterativo e Recursivo)
    - Quick Sort (Iterativo e Recursivo)
    - Heap Sort (Iterativo e Recursivo)

---

### **Como usar:**

1. **Compilar**:
- para compilar os testes de tempo, use: g++ main.cpp Algt.cpp -o main

2. **Executar**:
- Para executar os testes: ./[nome_do_executavel]

3. **Resultado**
- Os resultados da medição dos tempos de execução serão salvos em arquivos .txt, com o formato:
    ```
    # Medição de tempo do algoritmo [nome do algoritmo] (WORST)
    # Tamanho       Tempo (ms)
    [tamanho]      [tempo]
    ```
- Os resultados dos testes de verificação são exibidos no terminal.


 

