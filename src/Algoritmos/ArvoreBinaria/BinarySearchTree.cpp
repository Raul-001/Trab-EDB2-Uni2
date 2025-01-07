#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
    root = NULL; 
}

node*& BinarySearchTree::GetRoot() {
    return root;
}

void BinarySearchTree::insert(int item) {
    //Cria um novo nó e define seu valor
    node* newNode = new node();
    newNode->item = item;
    newNode->esq = nullptr;
    newNode->dir = nullptr;

    if (root == nullptr) {
        //Se a Árvore estiver vazia o novo nó se torna raiz
        root = newNode; 
        return;
    }

    node* currentNode = root;
    while (currentNode != nullptr) {
        if (item < currentNode->item) {
            // Se o item for menor, vai para a subárvore esquerda
            if (currentNode->esq == nullptr) {
                currentNode->esq = newNode;
                return;
            }
            currentNode = currentNode->esq;
        } else if (item > currentNode->item) {
            // Se o item for maior, vai para a subárvore direita
            if (currentNode->dir == nullptr) {
                currentNode->dir = newNode;
                return;
            }
            currentNode = currentNode->dir;
        }
    }
}

node* BinarySearchTree::search(node* currentRoot, int item){
    while (currentRoot != NULL && currentRoot->item != item){
        // Enquanto o nó atual não for nulo e o item não for encontrado
        if(item < currentRoot->item){
            // Vai para a subárvore esquerda
            currentRoot = currentRoot->esq;
        } else {
            // Vai para a subárvore direita
            currentRoot = currentRoot->dir;
        }
    }
    return currentRoot;
}

void BinarySearchTree::remove(node*& currentNode, int item) {
    if (currentNode == NULL) {
        return; // Item não encontrado
    }

    if (item < currentNode->item) {
        // Procura na subárvore esquerda
        remove(currentNode->esq, item);
    } else if (item > currentNode->item) {
        // Procura na subárvore direita
        remove(currentNode->dir, item);
    } else {
        // Item encontrado
        // Caso 1: Nó sem filhos
        if (currentNode->esq == NULL && currentNode->dir == NULL) {
            delete currentNode;
            currentNode = NULL;
        }
        // Caso 2: Nó com apenas um filho (direito)
        else if (currentNode->esq == NULL) {
            node* temp = currentNode;
            currentNode = currentNode->dir;
            delete temp;
        }
        // Caso 2: Nó com apenas um filho (esquerdo)
        else if (currentNode->dir == NULL) {
            node* temp = currentNode;
            currentNode = currentNode->esq; 
            delete temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            // Encontra o sucessor in-order (menor valor na subárvore direita)
            node* temp = successor(currentNode->dir);
            // Substitui o valor
            currentNode->item = temp->item; 
            // Remove o sucessor in-order da subárvore direita
            remove(currentNode->dir, temp->item);
        }
    }
}

node* BinarySearchTree::successor(node* currentNode){
    while (currentNode->esq != nullptr) {
        // Navega para o nó mais à esquerda
        currentNode = currentNode->esq;
    }
    return currentNode;
}

void BinarySearchTree::preOrder(node* current){
    if(current != NULL){
        // Visita o nó atual
        std::cout << current->item << " "; 
        // Recursivamente visita a subárvore a esquerda
        preOrder(current->esq);
        // Recursivamente visita a subárvore a direita
        preOrder(current->dir);
    }
}

void BinarySearchTree::symmetricalOrder(node* current){
    if(current != NULL){
        // Visita a subárvore esquerda
        symmetricalOrder(current->esq);
        // Visita o nó atual
        std::cout << current->item << " ";
        // Visita a subárvore direita
        symmetricalOrder(current->dir);
    }
}

void BinarySearchTree::posOrder(node* current){
    if(current != NULL){
        // Visita a subárvore esquerda
        posOrder(current->esq);
        // Visita a subárvore direita
        posOrder(current->dir);
        // Visita o nó atual
        std::cout << current->item << " ";
    }
}

void BinarySearchTree::levelOrder(node* current){
    //Vector usado como fila para armazenar os itens por nivel
    std::vector<node*> queue;
    //Insere primeiro elemento
    queue.push_back(current);

    if(current == NULL){
        return;
    }

    while(!queue.empty()){
        // Primeiro nó do vector 
        node* temp = queue.front();
        // Remove primeiro nó do vector
        queue.erase(queue.begin());
        // Imprime
        std::cout << temp->item << " ";

        // Adiciona os filhos a fila 
        if(temp->esq != NULL){
            queue.push_back(temp->esq);
        }
        if(temp->dir != NULL){
            queue.push_back(temp->dir);
        }
    }

}

node* BinarySearchTree::BalancedTree(std::vector<int>& item, int first, int last) {
    if (first > last) {
        return nullptr;
    }

    // Calcula o índice do elemento central
    int mid = first + (last - first) / 2;
    // novo nó
    node* newNode = new node();
    newNode->item = item[mid];
    // Cria as subárvores da esquerda e direita
    newNode->esq = BalancedTree(item, first, mid - 1);
    newNode->dir = BalancedTree(item, mid + 1, last);

    return newNode;
}

void BinarySearchTree::createBalancedTree(std::vector<int> item) {
    //Ordena lista de entrada
    std::sort(item.begin(), item.end());
    // Cria a Árvore balanceada recursivamente
    root = BalancedTree(item, 0, item.size() - 1);
}

void BinarySearchTree::generateDotFile(const std::string& filename) {
    //Arquivo para escrita
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

    file << "digraph BST {\n";
    file << "    node [fontname=\"Arial\"];\n";

    // Caso a Árvore seja vazia não gera o arquivo
    if (root == NULL) {
        file << "\n";
    } else {
        generateDotNodes(root, file);
    }

    file << "}\n";
     // Fecha o arquivo
    file.close();

    std::cout << "Arquivo .dot gerado com sucesso: " << filename << "\n";
}

void BinarySearchTree::generateDotNodes(node* currentNode, std::ofstream& file) {
    if (currentNode != NULL) {
        // Se o nó atual possui filho a esquerda, ele é ligado no .dot
        if (currentNode->esq != NULL) {
            file << "    " << currentNode->item << " -> " << currentNode->esq->item << ";\n";
            generateDotNodes(currentNode->esq, file);
        }

        // Se o nó atual possui filho a direita, ele é ligado no .dot
        if (currentNode->dir != NULL) {
            file << "    " << currentNode->item << " -> " << currentNode->dir->item << ";\n";
            generateDotNodes(currentNode->dir, file);
        }
    }
}