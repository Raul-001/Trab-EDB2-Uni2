#include "ArvoreAVL.h"
#include <iostream>
#include <queue>

/**
 * @brief Percorre a arvore em nivel.
 */
void emNivel(NodoAVL *raiz)
{
    std::queue<NodoAVL*> fila;
    fila.push(raiz);

    while (!fila.empty())
    {
        NodoAVL* atual = fila.front();
        fila.pop();

        std::cout << atual->chave << " ";

        if (atual->esq != nullptr)
        {
            fila.push(atual->esq);
        }
        if (atual->dir != nullptr)
        {
            fila.push(atual->dir);
        }        
    }
}

/**
 * @brief Testa a inserção com arvores usadas nos exemplos vistos em sala.
 */
void testarInsercao() {
    std::vector exemplo = {30, 20, 50, 15, 25, 40, 60, 35, 45};
    std::cout << "===> Testando insercoes...\n";

    // Teste 1
    NodoAVL* arvore1 = nullptr;

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore1 = inserir(arvore1, exemplo[i]);
    }

    std::cout << "Teste 1:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore1);

    std::cout << "\nInserindo 32: ";
    arvore1 = inserir(arvore1, 32);
    emNivel(arvore1);

    // Teste 2
    NodoAVL* arvore2 = nullptr;

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore2 = inserir(arvore2, exemplo[i]);
    }

    std::cout << "\n\n";
    std::cout << "Teste 2:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore2);

    std::cout << "\nInserindo 42: ";
    arvore2 = inserir(arvore2, 42);
    emNivel(arvore2);

    // Teste 3
    NodoAVL* arvore3 = nullptr;

    exemplo = {30, 20, 50, 15, 25, 40, 60, 27, 35, 45, 70};

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore3 = inserir(arvore3, exemplo[i]);
    }

    std::cout << "\n\n";
    std::cout << "Teste 3:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore3);

    std::cout << "\nInserindo 28: ";
    arvore3 = inserir(arvore3, 28);
    emNivel(arvore3);

    // Teste 4
    NodoAVL* arvore4 = nullptr;

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore4 = inserir(arvore4, exemplo[i]);
    }

    std::cout << "\n\n";
    std::cout << "Teste 4:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore4);

    std::cout << "\nInserindo 26: ";
    arvore4 = inserir(arvore4, 26);
    emNivel(arvore4);
}

/**
 * @brief Testa a remocao com arvores usadas nos exemplos vistos em sala.
 */
void testarRemocao() {
    std::vector exemplo = {50, 35, 70, 25, 40, 65, 90, 30, 80};

    std::cout << "\n\n";
    std::cout << "===> Testando remocoes...\n";

    // Teste 1 (removendo folha)
    NodoAVL* arvore1 = nullptr;

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore1 = inserir(arvore1, exemplo[i]);
    }

    std::cout << "Teste 1:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore1);

    std::cout << "\nRemovendo 40 (folha): ";
    arvore1 = remover(arvore1, 40);
    emNivel(arvore1);

    // Teste 2 (uma subarvore vazia)
    std::cout << "\n\n";
    std::cout << "Teste 2:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore1);

    std::cout << "\nRemovendo 35 (possui uma subarvore vazia): ";
    arvore1 = remover(arvore1, 35);
    emNivel(arvore1);

    // Teste 3 (duas subarvores nao vazias)
    NodoAVL* arvore2 = nullptr;

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore2 = inserir(arvore2, exemplo[i]);
    }

    std::cout << "\n\n";
    std::cout << "Teste 3:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore2);

    std::cout << "\nRemovendo 50: ";
    arvore2 = remover(arvore2, 50);
    emNivel(arvore2);

    // Teste 4
    NodoAVL* arvore3 = nullptr;

    exemplo = {50, 25, 75, 15, 35, 60, 120, 10, 68, 90, 125, 83, 99};

    // Criando a arvore exemplo
    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore3 = inserir(arvore3, exemplo[i]);
    }
    
    std::cout << "\n\n";
    std::cout << "Teste 4:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore3);

    std::cout << "\nRemovendo 120: ";
    arvore3 = remover(arvore3, 120);
    emNivel(arvore3);

    // Teste 5    
    std::cout << "\n\n";
    std::cout << "Teste 5:\n";
    std::cout << "Arvore inicial: ";
    emNivel(arvore3);

    std::cout << "\nRemovendo 10: ";
    arvore3 = remover(arvore3, 10);
    emNivel(arvore3);
}

/**
 * @brief Testa a busca em uma arvore AVL
 */
void testarBusca() {
    std::cout << "\n\n";
    std::cout << "===> Testando busca...\n";

    std::vector exemplo = {50, 35, 70, 25, 40, 65, 90, 30, 80};

    NodoAVL* arvore = nullptr;

    for (int i = 0; i < exemplo.size(); i++)
    {
        arvore = inserir(arvore, exemplo[i]);
    }
    std::cout << "Arvore: ";
    emNivel(arvore);

    std::cout << "\n\n";
    std::cout << "Buscando 25...\n";
    arvore = busca(arvore, 25);

    std::cout << "\nBuscando 100...\n";
    arvore = busca(arvore, 100);
}

/**
 * @brief Executa os testes das funções básicas, que imprimem os resultados em nivel.
 * 
 * Os testes são feitos em arvores predefinidas, exatamente como estão nos slides vistos em sala, abrangendo as funções de rotação necessárias.
 */
int main(int argc, char const *argv[]) {
    testarInsercao();

    testarRemocao();

    testarBusca();
    
    return 0;
}
