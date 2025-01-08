#include <iostream>
#include <vector>
#include "Algt.h"

// Função para imprimir o vetor
void imprimirLista(const std::vector<int>& lista) {
    std::cout << "[ ";
    for (int num : lista) {
        std::cout << num << " ";
    }
    std::cout << "]\n";
}

void imprimirDivisao() {
    std::cout << "-------------------------------------------------\n";
}

int main() {
    Algt sorter;
    std::vector<int> listaOriginal = {64, 22, 34, 25, 12, 22, 11, 90};

    std::cout << "\n********************* LISTA ORIGINAL *********************\n\n";
    std::cout << "Lista: ";
    imprimirLista(listaOriginal);

    std::cout << "\n********************* TESTES DE ORDENAÇÃO *********************\n\n";

    // Teste Heap Sort Iterativo
    imprimirDivisao();
    std::cout << "Teste 1: Heap Sort Iterativo\n";
    std::vector<int> listaHeapIter = listaOriginal;  // Cópia da lista original
    sorter.HeapSortIterativo(listaHeapIter);
    imprimirLista(listaHeapIter);

    // Teste Heap Sort Recursivo
    imprimirDivisao();
    std::cout << "Teste 2: Heap Sort Recursivo\n";
    std::vector<int> listaHeapRec = listaOriginal;  // Cópia da lista original
    sorter.HeapSortRecursivo(listaHeapRec);
    imprimirLista(listaHeapRec);

    // Teste Bubble Sort Iterativo
    imprimirDivisao();
    std::cout << "Teste 3: Bubble Sort Iterativo\n";
    std::vector<int> listaBubbleIter = listaOriginal;  // Cópia da lista original
    sorter.BubbleSortIterative(listaBubbleIter);
    imprimirLista(listaBubbleIter);
    
    // Teste Bubble Sort Recursivo
    imprimirDivisao();
    std::cout << "Teste 4: Bubble Sort Recursivo\n";
    std::vector<int> listaBubbleRec = listaOriginal;  // Cópia da lista original
    sorter.BubbleSortRecursive(listaBubbleRec, listaBubbleRec.size());
    imprimirLista(listaBubbleRec);

    // Teste Merge Sort Iterativo 
    imprimirDivisao();
    std::cout << "Teste 5: Merge Sort Iterativo\n";
    std::vector<int> listaMergeIter = listaOriginal;  // Cópia da lista original
    sorter.MergeSortIterative(listaMergeIter, listaMergeIter.size());
    imprimirLista(listaMergeIter);


    // Teste Merge Sort Recursivo 
    imprimirDivisao();
    std::cout << "Teste 6: Merge Sort Recursivo\n";
    std::vector<int> listaMergeRec = listaOriginal;  // Cópia da lista original
    sorter.MergeSortRecursive(listaMergeRec, 0, listaMergeRec.size() - 1);
    imprimirLista(listaMergeRec);
    
    
    // Teste Quick Sort Iterativo 
    imprimirDivisao();
    std::cout << "Teste 7: Quick Sort Iterativo\n";
    std::vector<int> listaQuickIter = listaOriginal;  // Cópia da lista original
    sorter.QuickSortIterative(listaQuickIter, listaQuickIter.size());
    imprimirLista(listaQuickIter);

    // Teste Quick Sort Recursivo 
    imprimirDivisao();
    std::cout << "Teste 8: Quick Sort Recursivo\n";
    std::vector<int> listaQuick = listaOriginal;  // Cópia da lista original
    sorter.QuickSortRecursive(listaQuick, 0, listaQuick.size() - 1);
    imprimirLista(listaQuick);
    
    imprimirDivisao();
    
    std::cout << "\n********************* FIM DOS TESTES *********************\n";
    
    return 0;
}
