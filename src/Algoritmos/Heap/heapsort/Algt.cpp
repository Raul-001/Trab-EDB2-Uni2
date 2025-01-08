#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "Algt.h"


// Método auxiliar para criar a heap
void Algt::criarHeap(std::vector<int>& v, int inicio, int final) {
    int aux = v[inicio];
    int filho = 2 * inicio + 1;
    inicio = criarHeapRecursao(v, inicio, aux, filho, final);
    v[inicio] = aux; // pai troca com filho mais abaixo à direita
}

int Algt::criarHeapRecursao(std::vector<int>& v, int inicio, int aux, int filho, int final) {
    if (filho > final) return inicio;

    // pai tem 2 filhos? Se sim, qual é o maior?
    if (filho < final && filho + 1 <= final && v[filho] < v[filho + 1]) {
        filho++;
    }

    // troca o filho com o pai se o filho for maior
    if (aux < v[filho]) {
        v[inicio] = v[filho];
        inicio = filho;
        filho = 2 * inicio + 1;
    } else {
        filho = final + 1;
    }
    return criarHeapRecursao(v, inicio, aux, filho, final);
}

// Construir a heap máxima (iterativo)
void Algt::HeapSortIterativo(std::vector<int>& list) {
    int tam = list.size();
    for (int i = (tam - 1) / 2; i >= 0; i--) {
        criarHeap(list, i, tam - 1);
    }
    for (int i = tam - 1; i >= 1; i--) {
        int aux = list[0];
        list[0] = list[i];
        list[i] = aux;
        criarHeap(list, 0, i - 1);
    }
}

// Construir a heap máxima (recursivo)
void Algt::heapSort1(std::vector<int>& v, int i, int tam) {
    if (i < 0) return;
    criarHeap(v, i, tam - 1);
    heapSort1(v, i - 1, tam);
}

void Algt::heapSort2(std::vector<int>& v, int i, int tam) {
    if (i <= 0) return;

    // troca da raiz com o último elemento
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;

    criarHeap(v, 0, i - 1); // cria o heap sem o maior elemento anterior
    heapSort2(v, i - 1, tam);
}

void Algt::HeapSortRecursivo(std::vector<int>& list) {
    int tam = list.size();
    heapSort1(list, (tam - 1) / 2, tam); // construir a heap máxima
    heapSort2(list, tam - 1, tam);       // ordenar o vetor
}

void Algt::BubbleSortIterative(std::vector<int> &list){
    // Armazena o tamanho da lista
    int size = list.size();
    int temp;
    // For para percorrer o número de passagens
    for (int i = 0; i < size - 1; i++){
        bool swapped = false;
        //For para realizar trocas
        for (int j = 0; j < (size - i - 1); j++){
            if (list[j] > list[j + 1]){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = true;
            }
        }
        // Se não houver troca, a lista já está ordenada
        if (swapped == false){
            break;
        }
    }
}

void Algt::BubbleSortRecursive(std::vector<int>& list, int size){
    // Se o tamanho for menor que 2, não há nada para ordenar.
    if(size < 2){
        return;
    }
    // verifica se houver troca
    bool swapped = false;
    // percorre a lista e troca os elementos caso necessário
    for (int i = 0; i < size - 1; i++){
        if (list[i] > list[i + 1]){
            int temp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = temp;
            swapped = true; 
        }
    }
    //Se não houve troca, a lista está ordenada
    if (swapped == false){
        return;
    }
    // Recursão para o restante da lista
    BubbleSortRecursive(list, size - 1);
}

void Algt::MergeSortIterative(std::vector<int> &list, int size)
{
    int curr_size;  // controlador do tamanho da sublista
    int left_start; // indíce da sublista a esquerda 

    // aumenta o tamanho da sublista começando de 1
    for (curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size) {
        // percorre as sublistas de tamanho 'curr_size'
        for (left_start = 0; left_start < size - 1; left_start += 2 * curr_size) {
            // Calcula o meio da sublista
            int mid = std::min(left_start + curr_size - 1, size - 1);
            // Calcula o final da sublista à direita
            int right_end = std::min(left_start + 2 * curr_size - 1, size - 1);
            Merge(list, left_start, mid, right_end);
        }
    }
}

void Algt::Merge(std::vector<int>& list, int first, int mid, int last) {
    int n1 = mid - first + 1; // Tamanho do subvetor da esquerda
    int n2 = last - mid;      // Tamanho do subvetor da direita

    std::vector<int> leftArray(n1), rightArray(n2);

    // Copia os elementos do subvetor da esquerda
    for (int i = 0; i < n1; i++) {
        leftArray[i] = list[first + i];
    }
    // Copia os elementos do subvetor da direita
    for (int j = 0; j < n2; j++) {
        rightArray[j] = list[mid + 1 + j];
    }

    int i = 0, j = 0, k = first;

    // Mescla os subvetores de volta na lista inicial
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            list[k] = leftArray[i];
            i++;
        } else {
            list[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copia elementos restantes do subvetor da esquerda (se houver)
    while (i < n1) {
        list[k] = leftArray[i];
        i++;
        k++;
    }

    // Copia elementos restantes do subvetor da direita (se houver)
    while (j < n2) {
        list[k] = rightArray[j];
        j++;
        k++;
    }
}


void Algt::MergeSortRecursive(std::vector<int>& list, int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        MergeSortRecursive(list, first, mid);
        MergeSortRecursive(list, mid + 1, last);
        Merge(list, first, mid, last);
    }
}

void Algt::QuickSortIterative(std::vector<int>& list, int size){
    // Cria uma pilha para armazenar os índices
    std::stack<int> pilha;

    // Coloca os índices iniciais (esquerda e direita) da primeira chamada na pilha
    pilha.push(0);
    pilha.push(size - 1);

    // Continua enquanto houver elementos na pilha
    while (!pilha.empty()) {
        // Remove os índices do topo da pilha
        int direita = pilha.top();
        pilha.pop();
        int esquerda = pilha.top();
        pilha.pop();

        // Particiona o array e encontra o pivô
        int pivo = partition(list, esquerda, direita);

        // Adiciona as subpartes à esquerda e à direita do pivô na pilha, se necessário
        if (pivo - 1 > esquerda) {
            pilha.push(esquerda);
            pilha.push(pivo - 1);
        }
        if (pivo + 1 < direita) {
            pilha.push(pivo + 1);
            pilha.push(direita);
        }
    }
}

int Algt::partition(std::vector<int>& list, int first, int last) {
    int i = first - 1;
    int pivot = list[last]; // O pivô é o último elemento

    for (int j = first; j < last; j++) {
        if (list[j] <= pivot) { // Condição para mover os elementos menores ou iguais ao pivô
            i++;
            std::swap(list[i], list[j]); // Troca os elementos
        }
    }
    // Coloca o pivô na posição correta
    std::swap(list[i + 1], list[last]);
    return i + 1; // Retorna a posição do pivô
}

void Algt::QuickSortRecursive(std::vector<int>& list, int first, int last){
    if(first < last){
        // Obtém a posição do pivô por meio da função de particionamento
        int pivo = partition(list, first, last);
        // Recursão para ordenar a parte da esquerda
        QuickSortRecursive(list, first, pivo - 1);
        // Recursão para ordenar a parte da direita
        QuickSortRecursive(list, pivo + 1, last);
    }
}

