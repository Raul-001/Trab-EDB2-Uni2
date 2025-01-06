#include "ArvoreAVL.h"
#include <fstream>
#include <vector>

/**
 * @brief Gera as conexões de um arquivo DOT representando uma árvore binária.
 * 
 * Esta função percorre a árvore e escreve no arquivo DOT as arestas que
 * conectam os nós pai aos seus respectivos filhos (esquerda e direita).
 * 
 * @param raiz Ponteiro para o nó raiz da árvore binária.
 * @param arquivo Referência para o objeto de saída do arquivo onde os dados serão escritos.
 */
void gerarArquivoDot(NodoAVL* raiz, std::ofstream& arquivo) {
    if (raiz) {
        if (raiz->esq) {
            arquivo << raiz->chave << " -> " << raiz->esq->chave << ";\n";
            gerarArquivoDot(raiz->esq, arquivo);
        }
        if (raiz->dir) {
            arquivo << raiz->chave << " -> " << raiz->dir->chave << ";\n";
            gerarArquivoDot(raiz->dir, arquivo);
        }
    }
}

/**
 * @brief Exporta uma árvore binária para um arquivo DOT.
 * 
 * Esta função cria um arquivo DOT com a representação gráfica da árvore binária.
 * O arquivo gerado pode ser utilizado por ferramentas como Graphviz para visualizar a árvore.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore binária.
 */
void exportarArvore(NodoAVL* raiz, std::string nome) {
    std::ofstream arquivo(nome + ".dot");
    arquivo << "digraph G {\n";
    arquivo << "node [shape=circle];\n";
    gerarArquivoDot(raiz, arquivo);
    arquivo << "}\n";
    arquivo.close();
}

/**
 * @brief Cria uma árvore AVL usando a função de inserção, com valores inteiros de uma lista L e a exporta para um arquivo .dot
 * 
 * O arquivo gerado pode ser utilizado por ferramentas como Graphviz para visualizar a árvore.
 */
int main(int argc, char const *argv[])
{
    std::vector L = {15, 18, 20, 35, 32, 38, 30, 40, 32, 45, 48, 52, 60, 50};
    NodoAVL* arvore = nullptr;

    for (int i = 0; i < L.size(); i++)
    {
        arvore = inserir(arvore, L[i]);
    }
    
    exportarArvore(arvore, "fromVector");

    return 0;
}
