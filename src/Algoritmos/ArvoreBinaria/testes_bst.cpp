#include <iostream>
#include <vector>
#include "BinarySearchTree.h" // Inclua sua implementação da árvore aqui

void printOrder(BinarySearchTree& bst) {
    std::cout << "Percurso em pré-ordem: ";
    bst.preOrder(bst.GetRoot());
    std::cout << "\nPercurso ordem simétrica: ";
    bst.symmetricalOrder(bst.GetRoot());
    std::cout << "\nPercurso pós-ordem: ";
    bst.posOrder(bst.GetRoot());
    std::cout << "\nPercurso por nível: ";
    bst.levelOrder(bst.GetRoot());
    std::cout << "\n";
}

void testInsert() {
    std::vector<int> exemplo = {50, 35, 70, 25, 40, 65, 90, 30, 80};
    std::cout << "===> Testando inserções <===\n\n";

    // Teste 1
    BinarySearchTree bst1;
    for (int valor : exemplo) {
        bst1.insert(valor);
    }

    std::cout << "Teste 1: Árvore inicial:\n\n";
    printOrder(bst1);

    bst1.generateDotFile("tree_insert_T1.dot"); // Gera o arquivo .dot 

    std::cout << "Inserindo 42:\n\n";
    bst1.insert(42);
    printOrder(bst1);

    bst1.generateDotFile("tree_insert_T1_42.dot"); // Gera o arquivo .dot após a inserção do 42

    // Teste 2
    BinarySearchTree bst2;
    for (int valor : exemplo) {
        bst2.insert(valor);
    }

    std::cout << "\nTeste 2: Árvore inicial:\n\n";
    printOrder(bst2);

    bst2.generateDotFile("tree_insert_T2.dot"); // Gera o arquivo .dot

    std::cout << "Inserindo 32:\n\n";
    bst2.insert(32);
    printOrder(bst2);
    bst2.generateDotFile("tree_insert_T2_32.dot"); // Gera o arquivo .dot após a inserção do 32

    // Teste 3
    BinarySearchTree bst3;
    std::vector<int> exemplo2 = {30, 20, 50, 15, 25, 40, 60, 27, 35, 45, 70};
    for (int valor : exemplo2) {
        bst3.insert(valor);
    }

    std::cout << "\nTeste 3: Árvore inicial:\n\n";
    printOrder(bst3);
    bst3.generateDotFile("tree_insert_T3.dot"); // Gera o arquivo .dot

    std::cout << "Inserindo 28:\n\n";
    bst3.insert(28);
    printOrder(bst3);
    bst3.generateDotFile("tree_insert_T3_28.dot"); // Gera o arquivo .dot após a inserção do 28

    // Teste 4: Lista em ordem inversa com balanceamento
    BinarySearchTree bst4;
    std::vector<int> exemploInvertido = {80, 70, 65, 60, 50, 40, 35, 30, 25}; // Ordem inversa de exemplo
    for (int valor : exemploInvertido) {
        bst4.insert(valor);
    }

    std::cout << "\nTeste 4: Árvore inicial com lista inversa:\n\n";
    printOrder(bst4);
    bst4.generateDotFile("tree_insert_T4.dot"); // Gera o arquivo .dot antes de balancear a árvore

    std::cout << "Balanceando a árvore:\n\n";
    bst4.createBalancedTree(exemploInvertido); // Balanceia a árvore
    printOrder(bst4);
    bst4.generateDotFile("tree_insert_T4_balanced.dot"); // Gera o arquivo .dot após o balanceamento
}

void testRemove() {
    std::vector<int> exemplo = {50, 35, 70, 25, 40, 65, 90, 30, 80};
    std::cout << "===> Testando remoções <===\n";

    // Teste 1: Remoção de nó folha
    BinarySearchTree bst1;
    for (int valor : exemplo) {
        bst1.insert(valor);
    }

    std::cout << "Teste 1: Árvore inicial:\n\n";
    printOrder(bst1);
    bst1.generateDotFile("tree_remove_T1.dot"); 

    std::cout << "Removendo nó folha (40):\n\n";
    bst1.remove(bst1.GetRoot(), 40);
    printOrder(bst1);
    bst1.generateDotFile("tree_remove_T1_40.dot"); 
    // Teste 2: Remoção de nó com um filho
    std::vector<int> exemplo2 = {50, 35, 70, 25, 65, 90, 30, 80};
    BinarySearchTree bst2;
    for (int valor : exemplo2) {
        bst2.insert(valor);
    }

    std::cout << "\nTeste 2: Árvore inicial:\n\n";
    printOrder(bst2);
    bst2.generateDotFile("tree_remove_T2.dot"); 

    std::cout << "Removendo nó com um filho (35):\n\n";
    bst2.remove(bst2.GetRoot(), 35);
    printOrder(bst2);
    bst2.generateDotFile("tree_remove_T2_35.dot"); 

    // Teste 3: Remoção de nó com dois filhos
    BinarySearchTree bst3;
    for (int valor : exemplo) {
        bst3.insert(valor);
    }

    std::cout << "\nTeste 3: Árvore inicial:\n\n";
    printOrder(bst3);
    bst3.generateDotFile("tree_remove_T3.dot"); 

    std::cout << "Removendo nó com dois filhos (50):\n\n";
    bst3.remove(bst3.GetRoot(), 50);
    printOrder(bst3);
    bst3.generateDotFile("tree_remove_T3_50.dot"); 
}

void testSearch() {
    std::vector<int> exemplo = {20, 10, 40, 15, 30, 50, 60};
    BinarySearchTree bst;
    for (int valor : exemplo) {
        bst.insert(valor);
    }

    std::cout << "===> Testando buscas <===\n\n";
    std::cout << "Árvore inicial:\n\n";
    printOrder(bst);
    bst.generateDotFile("tree_search.dot"); 
    std::cout << "\n";

    int valores[] = {15, 35, 50};
    for (int valor : valores) {
        std::cout << "Buscando " << valor << ":\n\n";
        auto* result = bst.search(bst.GetRoot(), valor);
        if (result) {
            std::cout << "Valor " << valor << " encontrado!\n\n";
        } else {
            std::cout << "Valor " << valor << " não encontrado!\n\n";
        }
    }
}

int main() {
    std::cout << "\n---------------------------------------\n";
    testInsert();
    std::cout << "\n---------------------------------------\n";
    testRemove();
    std::cout << "\n---------------------------------------\n";
    testSearch();
    std::cout << "\n---------------------------------------\n";

    return 0;
}
