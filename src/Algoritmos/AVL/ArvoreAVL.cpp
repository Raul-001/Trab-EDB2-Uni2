#include "ArvoreAVL.h"
#include <bits/algorithmfwd.h>
#include <iostream>

/**
 * @brief Calcula a altura de um nó em uma árvore AVL.
 * 
 * @param raiz Ponteiro para o nó cuja altura será calculada.
 * @return A altura do nó ou 0 se o nó for nulo.
 */
int calcularAltura(NodoAVL *raiz)
{
    return raiz == nullptr ? 0 : raiz->altura; //Ponteiros nulos com altura 0
}

/**
 * @brief Calcula o fator de balanceamento de um nó em uma árvore AVL.
 * 
 * @param raiz Ponteiro para o nó cuja balanceamento será calculado.
 * @return A diferença entre as alturas das subárvores esquerda e direita.
 */
int calcularBalanceamento(NodoAVL *raiz)
{
    return calcularAltura(raiz->esq) - calcularAltura(raiz->dir);
}

/**
 * @brief Busca um valor em uma árvore AVL (iterativo).
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser buscado na árvore.
 * @return Ponteiro para o nó que contém o valor buscado ou nullptr se não encontrado.
 */
NodoAVL *busca(NodoAVL *raiz, int valor)
{
    while (raiz != nullptr && raiz->chave != valor)
    {
        if (valor < raiz->chave)
        {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    
    if (raiz == nullptr)
    {
        std::cout << "Chave nao encontrada \n";
        return nullptr;
    }
    
    std::cout << "Achou " << raiz->chave <<"\n";
    return raiz;
}

/**
 * @brief Realiza uma rotação simples para a esquerda em uma árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da subárvore a ser rotacionada.
 * @return Ponteiro para a nova raiz após a rotação.
 */
NodoAVL *rotacaoEsquerda(NodoAVL *raiz)
{
    NodoAVL* novaRaiz = raiz->dir;  // Nova raiz será o filho direito da raiz atual 
    NodoAVL* subArvoreEsquerda = novaRaiz->esq;

    novaRaiz->esq = raiz;           // Raiz atual passa a ser o filho esquerdo da nova raiz
    raiz->dir = subArvoreEsquerda;  // A subárvore esquerda do novo nó raiz se torna o filho direito da raiz original

    // Atualiza as alturas com base na altura dos filhos
    raiz->altura = std::max(calcularAltura(raiz->esq), calcularAltura(raiz->dir)) + 1;
    novaRaiz->altura = std::max(calcularAltura(novaRaiz->esq), calcularAltura(novaRaiz->dir)) + 1;

    return novaRaiz;
}

/**
 * @brief Realiza uma rotação simples para a direita em uma árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da subárvore a ser rotacionada.
 * @return Ponteiro para a nova raiz após a rotação.
 */
NodoAVL *rotacaoDireita(NodoAVL *raiz)
{
    NodoAVL* novaRaiz = raiz->esq;
    NodoAVL* subArvoreDireita = novaRaiz->dir;

    novaRaiz->dir = raiz;           // Raiz atual passa a ser o filho direito da nova raiz
    raiz->esq = subArvoreDireita;   // A subárvore direita do novo nó raiz se torna o filho esquerdo da raiz original

    raiz->altura = std::max(calcularAltura(raiz->esq), calcularAltura(raiz->dir)) + 1;
    novaRaiz->altura = std::max(calcularAltura(novaRaiz->esq), calcularAltura(novaRaiz->dir)) + 1;

    return novaRaiz;
}

/**
 * @brief Realiza uma rotação dupla para a esquerda em uma árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da subárvore a ser rotacionada.
 * @return Ponteiro para a nova raiz após a rotação dupla.
 */
NodoAVL *rotacaoDuplaEsquerda(NodoAVL *raiz)
{
    raiz->dir = rotacaoDireita(raiz->dir);

    return rotacaoEsquerda(raiz);
}

/**
 * @brief Realiza uma rotação dupla para a direita em uma árvore AVL.
 * 
 * @param raiz Ponteiro para o nó raiz da subárvore a ser rotacionada.
 * @return Ponteiro para a nova raiz após a rotação dupla.
 */
NodoAVL *rotacaoDuplaDireita(NodoAVL *raiz)
{
    raiz->esq = rotacaoEsquerda(raiz->esq);

    return rotacaoDireita(raiz);
}

/**
 * @brief Insere um valor em uma árvore AVL e ajusta o balanceamento se necessário.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser inserido na árvore.
 * @return Ponteiro para a nova raiz da árvore após a inserção.
 */
NodoAVL *inserir(NodoAVL *raiz, int valor)
{
    if (raiz == nullptr)
    {
        return new NodoAVL(valor);
    }
    
    if (valor < raiz->chave)
    {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->chave)
    {
        raiz->dir = inserir(raiz->dir, valor);
    } else {
        return raiz;
    }
    
    raiz->altura = 1 + std::max(calcularAltura(raiz->esq), calcularAltura(raiz->dir)); // Atualiza a altura

    int bl = calcularBalanceamento(raiz); // Calcula o balanceamento

    // Desbalanceamento para esquerda
    if (bl > 1 && valor < raiz->esq->chave)
    {
        return rotacaoDireita(raiz);
    }
    
    // Desbalanceamento para direita
    if (bl < -1 && valor > raiz->dir->chave)
    {
        return rotacaoEsquerda(raiz);
    }
    
    // Desbalanceamento para esquerda-direita
    if (bl > 1 && valor > raiz->esq->chave)
    {
        return rotacaoDuplaDireita(raiz);
    }
    
    // Desbalanceamento para direita-esquerda
    if (bl < -1 && valor < raiz->dir->chave)
    {
        return rotacaoDuplaEsquerda(raiz);
    }
    
    return raiz;
}

/**
 * @brief Remove um valor de uma árvore AVL e ajusta o balanceamento se necessário.
 * 
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param chave Valor a ser removido da árvore.
 * @return Ponteiro para a nova raiz da árvore após a remoção.
 */
NodoAVL *remover(NodoAVL *raiz, int chave)
{
    if(raiz == nullptr) {
        return nullptr;
    }
    if(chave < raiz->chave) {
        raiz->esq = remover(raiz->esq, chave);
    }
    else if(chave > raiz->chave) {
        raiz->dir = remover(raiz->dir, chave);
    }
    else {
        if(raiz->esq != nullptr && raiz->dir != nullptr) { //Nó com dois filhos
            NodoAVL* maiorEsq = raiz->esq; 
            while (maiorEsq->dir != nullptr) //Procura o maior elemento da subarvore esquerda da raiz
            {
                maiorEsq = maiorEsq->dir;
            }
            raiz->chave = maiorEsq->chave; //Sobrescreve a chave da raiz com a maior chave da subarvore esquerda da raiz
            raiz->esq = remover(raiz->esq, raiz->chave); //Volta a fazer a remoção na subarvore esquerda com a chave trocada

            raiz->altura = 1 + std::max(calcularAltura(raiz->esq), calcularAltura(raiz->dir)); // Atualiza altura
        }
        if(raiz->esq != nullptr && raiz->dir == nullptr) { //A chave removida possui subárvore direita vazia
            NodoAVL* temp = raiz->esq;
            delete raiz;
            return temp;
        }   
        if(raiz->esq == nullptr && raiz->dir != nullptr) { //A chave removida possui subárvore esquerda vazia
            NodoAVL* temp = raiz->dir;
            delete raiz;
            return temp;
        }   
        if(raiz->esq == nullptr && raiz->dir == nullptr) { //A chave está em uma folha
            delete raiz;
            return nullptr; //Retorna nullptr para que o ponteiro do pai seja atualizado
        }
    }

    raiz->altura = 1 + std::max(calcularAltura(raiz->esq), calcularAltura(raiz->dir)); // Atualiza a altura
    int bl = calcularBalanceamento(raiz); // Calcula o balanceamento

    // Desbalanceamento para esquerda
    if (bl > 1 && calcularBalanceamento(raiz->esq) >= 0)
    {
        return rotacaoDireita(raiz);
    }
    
    // Desbalanceamento para direita
    if (bl < -1 && calcularBalanceamento(raiz->dir) <= 0)
    {
        return rotacaoEsquerda(raiz);
    }
    
    // Desbalanceamento para esquerda-direita
    if (bl > 1 && calcularBalanceamento(raiz->esq) < 0)
    {
        return rotacaoDuplaDireita(raiz);
    }
    
    // Desbalanceamento para direita-esquerda
    if (bl < -1 && calcularBalanceamento(raiz->dir) > 0)
    {
        return rotacaoDuplaEsquerda(raiz);
    }

    return raiz; //Retorna a raiz atualizada
}
