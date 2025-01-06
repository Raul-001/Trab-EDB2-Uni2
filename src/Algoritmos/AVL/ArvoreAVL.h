#ifndef AVL_H
#define AVL_H

struct NodoAVL {
    public:
    int chave;               
    int altura;               
    NodoAVL* esq;            
    NodoAVL* dir;            

    NodoAVL(int valor) : chave(valor), altura(1), esq(nullptr), dir(nullptr) {}
};

int calcularAltura(NodoAVL* raiz);
int calcularBalanceamento(NodoAVL* raiz);
NodoAVL* busca(NodoAVL* raiz, int valor);

NodoAVL* rotacaoEsquerda(NodoAVL* raiz);
NodoAVL* rotacaoDireita(NodoAVL* raiz);
NodoAVL* rotacaoDuplaEsquerda(NodoAVL* raiz);
NodoAVL* rotacaoDuplaDireita(NodoAVL* raiz);

NodoAVL* inserir(NodoAVL* raiz, int valor);
NodoAVL* remover(NodoAVL* raiz, int valor);

#endif