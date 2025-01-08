#ifndef ALGT_H
#define ALGT_H

#include <vector>

/**
 * @class Algt
 * @brief Classe que contém algoritmos vistos em sala.
 *
 * Esta classe fornece métodos realizar buscas binárias e
 * ordenar vetores utilizando diferentes algoritmos de ordenação (HeapSort, Bubble Sort, Merge Sort, 
 * Quick Sort).
 */
class Algt {
    public:

    /**
     * @brief Ordena um vetor usando o Heap Sort Iterativo.
     *
     * @param list Vetor de inteiros que será ordenado.
     */
    void HeapSortIterativo(std::vector<int>& list);

    /**
     * @brief Ordena um vetor usando o Heap Sort Recursivo.
     *
     * @param list Vetor de inteiros que será ordenado.
     */
    void HeapSortRecursivo(std::vector<int>& list);

    // Métodos auxiliares para HeapSort
    void criarHeap(std::vector<int>& v, int inicio, int final);
    void heapSort1(std::vector<int>& v, int i, int tam);
    void heapSort2(std::vector<int>& v, int i, int tam);
    int criarHeapRecursao(std::vector<int>& v, int inicio, int aux, int filho, int final);

    /**
     * @brief Realiza uma busca binária iterativa em uma lista ordenada.
     * 
     * @param lista Vetor de inteiros onde a busca vai ser realizada, deve estar ordenada.
     * @param valor O alvo a ser buscado na lista.
     * @param taamnho O tamanho da lista.
     * @return O índicie que o alvo se encontra, ou -1 caso não esteja presente.
     */
    int busca_binaria(std::vector<int> lista, int valor, int tamanho);

    /**
     * @brief Realiza uma busca binária recursiva em uma lista ordenada.
     * 
     * @param lista Vetor de inteiros onde a busca vai ser realizada, deve estar ordenada.
     * @param valor O alvo a ser buscado na lista.
     * @param taamnho O tamanho da lista.
     * @return O índicie que o alvo se encontra, ou -1 caso não esteja presente.
     */
    int busca_binaria_recursiva(std::vector<int> lista, int valor, int inicio, int fim);

    /**
     * @brief Ordena um vetor usando o Bubble Sort Iterativo.
     * 
     * @param list Vetor de inteiros que será ordenado.
     */
    void BubbleSortIterative(std::vector<int>& list);

    /**
     * @brief Ordena um vetor usando o Bubble Sort Recursivo.
     * 
     * @param list Vetor de inteiros que será ordenado.
     * @param size tamanho do vetor a ser ordenado.
     */
    void BubbleSortRecursive(std::vector<int>& list, int size);

    /**
     * @brief Ordena um vetor usando o Merge Sort Iterativo.
     * 
     * @param list Vetor de inteiros que será ordenado.
     * @param size tamanho do vetor a ser ordenado.
     */
    void MergeSortIterative(std::vector<int>& list, int size);

    /**
     * @brief Combina as duas metades de um vetor em uma sequência ordenada.
     * 
     * @param list Vetor de inteiros que será ordenado.
     * @param first Índice inicial da primeira metade.
     * @param mid Índice final da primeira metade.
     * @param last índice final da segunda metade.
     */ 
    void Merge(std::vector<int>& list, int first, int mid, int last);

    /**
     * @brief Ordena um vetor usando o Merge Sort Recursivo.
     * 
     * @param list Vetor de inteiros que será ordenado.
     * @param first Índice inicial do vetor.
     * @param last Índice final do vetor. 
     */
    void MergeSortRecursive(std::vector<int>& list, int first, int last);

    /**
     * @brief Ordena um vetor usando o Quick Sort Iterativo.
     * 
     * @param list Vetor de inteiros que será ordenado.
     * @param size Tamanho do vetor a ser ordenado.
     */
    void QuickSortIterative(std::vector<int>& list, int size);

    /**
     * @brief Particiona um vetor por meio de um pivô escolhido com a mediana de 3 elementos.
     * 
     * @param list Vetor de inteiros a ser particionado.
     * @param first índice inicial da partição.
     * @param last índice final da partição.
     * 
     * @return O índice do pivô após a partição.
     */
    int partition(std::vector<int>& list, int first, int last);

    /**
     * @brief Ordena um vetor usando o Quick Sort Recursivo.
     * 
     * @param list Vetor de inteiros que será ordenado.
     * @param first Índice inicial do vetor.
     * @param last Índice final do vetor.
     */
    void QuickSortRecursive(std::vector<int>& list, int first, int last);
};

#endif // ALGT_H


