#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip> 
#include <random>
#include <ctime>
#include "Algt.h"


/**
 * @brief Escreve o resultado da medição dos tempos em um arquivo .txt de saída.
 * 
 * @param times Vetor de tempos medidos (em milissegundos) para cada tamanho da lista.
 * @param sizes Vetor de tamanhos das intâncias dos testes.
 * @param algorithmName Nome do algoritmo a ser testado.
 * @param outputFile Arquivo de saída onde os resultado serão registrados.
 * 
 * Formato de saída: 
 * Cada linha contém o tamanho e o tempo médio de execução para aquela instância.
 */
void escrever(const std::vector<std::chrono::duration<double, std::milli>> &times,
           const std::vector<int> &sizes, const std::string &algorithmName, std::ofstream &outputFile) {
    outputFile << "# Mediçao de tempo do algoritmo " << algorithmName << " (WORST)\n";
    outputFile << "# Tamanho       Tempo (ms)\n";

    // Percorre os tempos e tamanhos para escrever cada linha com o tempo correspondente
    for (size_t i = 0; i < times.size(); ++i) {
        outputFile << std::setw(7) << sizes[i]  
                   << std::setw(20) << std::setprecision(8) << std::fixed << times[i].count()
                   << "\n";
    }
}

/**
 * @brief Salva os elementos de um vetor de inteiros em um arquivo.
 * 
 * Esta função grava cada elemento do vetor `lista` em um arquivo de texto.
 * 
 * @param lista Vetor de inteiros a ser salvo no arquivo.
 * @param fileName Nome do arquivo onde a lista será salva.
 */
void escreveLista(const std::vector<int> &lista, const std::string &fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (int num : lista) {
            file << num << "\n";
        }
        file.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << fileName << std::endl;
    }
}

/**
 * @brief Executa os testes para os algoritmos e calcula o tempo médio de execução para diferentes tamanhos de lista.
 * 
 * @param algoritmo Objeto da classe Algt que contém a implementação dos algoritmos.
 * @param list Vetor de interios a ser ordenado.
 * @param funcName Nome da função a ser testada.
 * @param fileName Nome do arquivo onde os resultados serão salvos.
 * 
 * Cada algoritmo é executado 2 vezes para cada tamanho de lista e o tempo médio é armazenado.
 * 
 */
void executarTeste(Algt algoritmo, const std::vector<int> &list, const std::string &funcName, const std::string &fileName) {
    // Tamanhos das listas de teste
    //std::vector<int> sizes = {10000, 20000, 50000, 100000, 200000, 500000, 1000000};
    std::vector<int> sizes = {1000000};
    std::vector<std::chrono::duration<double, std::milli>> durations;
    int alvo = -1;

    escreveLista(list, "lista_entrada.txt");

    // Percorre os tamanhos da lista
    for (int size : sizes) {
        std::chrono::duration<double, std::milli> total_duration{0};

        // Repete 2 vezes para obter a média dos tempos
        for (int j = 0; j < 2; ++j) {
            std::vector<int> lista_copia(list.begin(), list.begin() + size);
            int tamanho = lista_copia.size();
            // Inicia contagem do tempo

            auto start_time = std::chrono::steady_clock::now();

            // Chama a função de ordenação com base no nome
            if (funcName == "bubblesort_iterativo") {
                algoritmo.BubbleSortIterative(lista_copia);
            } else if (funcName == "bubblesort_recursivo") {
                algoritmo.BubbleSortRecursive(lista_copia, lista_copia.size());
            } else if (funcName == "mergesort_iterativo") {
                algoritmo.MergeSortIterative(lista_copia, tamanho);
            } else if (funcName == "mergesort_recursivo") {
                algoritmo.MergeSortRecursive(lista_copia, 0, tamanho - 1);
            } else if (funcName == "quicksort_iterativo") {
                algoritmo.QuickSortIterative(lista_copia, tamanho);
            } else if (funcName == "quicksort_recursivo") {
                algoritmo.QuickSortRecursive(lista_copia, 0, tamanho - 1);
            } else if (funcName == "HeapSort_iterativo") {
                algoritmo.QuickSortIterative(lista_copia, tamanho);
            } else if (funcName == "HeapSort_Recursivo") {
                algoritmo.QuickSortRecursive(lista_copia, 0, tamanho - 1);
            } 
            // Termina a contagem do tempo
            auto end_time = std::chrono::steady_clock::now();
            total_duration += (end_time - start_time);

            // Imprime a lista de saída após a ordenação
            if (j == 0 && (size == 1000000)) {
                escreveLista(lista_copia, "saida_" + funcName + "_" + std::to_string(size) + ".txt");
            }
        }

        // calcula a média do tempo 
        std::chrono::duration<double, std::milli> average_duration = total_duration / 2;
        durations.push_back(average_duration); // Armazena a média para cada tamanho de lista
    }

    // Abre o arquivo de saída para registrar os resultados
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        escrever(durations, sizes, funcName, outputFile);
        outputFile.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de saída." << std::endl;
    }
}

/**
 * @brief Função principal que inicializa um vetor com dados aleatórios e executa os algoritmos.
 * 
 * Esta função cria um vetor contendo 100.000 elementos e realiza testes para diferentes algoritmos.
 * Para a busca binária, o vetor é ordenado, para a verificação de idades repetidas, o vetor contém 
 * valores variando de 0 a 100, e para os algoritmos de ordenação, o vetor é preenchido com valores aleatórios.
 * 
 * @return int Retorna 0 ao finalizar a execução.
 */
int main() {
    Algt algoritmo;

    std::vector<int> lista;

    // Semente para o gerador rand()
    std::srand(std::time(nullptr));

    for (int i = 0; i < 1000000; ++i) {
        lista.push_back(std::rand() % 10001); // números entre 0 e 1000
    }

    // Executa os testes de ordenação para medição de tempo
    //executarTeste(algoritmo, lista, "HeapSort_iterativo", "HeapSort_iterativo.txt");
    //executarTeste(algoritmo, lista, "HeapSort_Recursivo", "HeapSort_Recursivo.txt");
    //executarTeste(algoritmo, lista, "mergesort_iterativo", "mergesort_iterativo.txt");
    //executarTeste(algoritmo, lista, "mergesort_recursivo", "mergesort_recursivo.txt");
    //executarTeste(algoritmo, lista, "quicksort_iterativo", "quicksort_iterativo.txt");
    //executarTeste(algoritmo, lista, "quicksort_recursivo", "quicksort_recursivo.txt");
    //executarTeste(algoritmo, lista, "bubblesort_iterativo", "bubblesort_iterativo.txt");
    executarTeste(algoritmo, lista, "bubblesort_recursivo", "bubblesort_recursivo.txt");

    return 0;
}