/**
 * @file BinarySearchTree.h
 * @brief Declaração da classe BinarySearchTree e estrutura do nó para uma árvore binária de busca.
 * 
 * Este arquivo contém a definição da estrutura "node" e a declaração da classe "BinarySearchTree",
 * que implementa operações básicas em uma árvore binária de busca, como inserção, remoção, busca
 * e percursos em pré-ordem, ordem simétrica, pos-ordem e por nivel.
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

/**
 * @struct node
 * @brief Estrutura para representar um nó da árvore binária de busca.
 * 
 * Cada nó contém um valor inteiro (item) e dois ponteiros para seus filhos esquerdo (esq) e direito (dir).
 */
struct node {
    int item;
    node* esq = nullptr;
    node* dir = nullptr;
};

/**
 * @class BinarySearchTree
 * @brief Implementação de uma Árvore Binária de Busca.
 * 
 * Esta classe oferece métodos para realizar operações básicas em uma árvore binária de busca,
 * como inserção, remoção, busca e os percursos.
 */
class BinarySearchTree {
    private:
    node* root; ///< Ponteiro para o nó raiz da árvore.

    public:
    /**
     * @brief Construtor da classe BinarySearchTree.
     * 
     * Inicializa uma árvore binária de busca vazia, com a raiz definida como "NULL".
     */
    BinarySearchTree();

    /**
     * @brief Obtém a raiz da árvore.
     * @return Referência para o ponteiro da raiz da árvore.
     */
    node*& GetRoot();

    /**
     * @brief Insere um novo item na árvore.
     * @param item Valor inteiro a ser inserido na árvore.
     */
    void insert(int item);

    /**
     * @brief Remove um nó da árvore pelo seu valor.
     * @param currentRoot Ponteiro para o nó atual.
     * @param item Valor inteiro a ser removido da árvore.
     */
    void remove(node*& currentRoot, int item);

    /**
     * @brief Encontra o sucessor in-order de um nó.
     * @param currentNode Ponteiro para o nó atual.
     * @return Ponteiro para o nó sucessor in-order.
     */
    node* successor(node* currentNode);

    /**
     * @brief Busca um item na árvore.
     * @param currentRoot Ponteiro para o nó raiz da árvore ou subárvore.
     * @param item Valor inteiro a ser buscado.
     * @return Ponteiro para o nó que contém o valor, ou `nullptr` se não encontrado.
     */
    node* search(node* currentRoot, int item);

    /**
     * @brief Realiza o percurso em pré-ordem.
     * @param current Ponteiro para o nó raiz da árvore.
     */
    void preOrder(node* current);

    /**
     * @brief Realiza o percurso em ordem simétrica.
     * @param current Ponteiro para o nó raiz da árvore.
     */
    void symmetricalOrder(node* current);

    /**
     * @brief Realiza o percurso em pos-ordem.
     * @param current Ponteiro para o nó raiz da árvore.
     */
    void posOrder(node* current);

    /**
     * @brief Realiza o percurso em nivel.
     * @param current Ponteiro para o nó raiz da árvore.
     */
    void levelOrder(node* current);

    /**
     * @brief Função recursiva para construir uma árvore binária balanceada.
     * @param item Vetor de inteiros que contém os elementos a serem inseridos na árvore.
     * @param first Índice do primeiro elemento no vetor de entrada.
     * @param last Índice do último elemento no vetor.
     * @return Ponteiro para o nó raiz da árvore binária balanceada.
     */
    node* BalancedTree(std::vector<int>& item, int first, int last);

    /**
     * @brief Cria uma árvore binária balanceada a partir de um vetor de inteiros.
     * @param item Vetor de inteiros que contém os elementos a serem inseridos na árvore.
     */
    void createBalancedTree(std::vector<int> item);

    /**
     * @brief Gera um arquivo no formato DOT que representa a estrutura da árvore, utilizando Graphviz.
     * @param filename Nome do arquivo .dot a ser gerado.
     */
    void generateDotFile(const std::string& filename);

    /**
     * @brief Gera os nós da árvore para o arquivo DOT.
     * @param currentNode Ponteiro para o nó atual da árvore.
     * @param file Referência para o arquivo onde os dados em formato DOT serão escritos.
     */
    void generateDotNodes(node* currentNode, std::ofstream& file);

};

#endif // BINARYSEARCHTREE_H
