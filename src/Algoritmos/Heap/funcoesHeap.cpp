#include <iostream>
#include <vector>
#include <stdexcept> // biblioteca usada para tratar erros, como o "runtime_error" e o "out_of_range"
#include <functional> // biblioteca usada para definir o comparador no construtor (heap máx ou mín)

class Heap {
private:
    std::vector<int> dados; //vetor para armazenar os elementos da heap
    std::function<bool(int, int)> comparar; //função comparadora (maximo ou minimo)

    //calcular o índice do filho esquerdo de um nó
    int filhoEsquerdo(int indice) { return 2 * indice + 1; }

    //calcular o índice do filho direito de um nó
    int filhoDireito(int indice) { return 2 * indice + 2; }

    //calcular o índice do pai de um nó
    int pai(int indice) { return (indice - 1) / 2; }

    //ajusta a heap para baixo a partir de um índice, garantindo que a propriedade da heap seja mantida
    void ajustarAbaixo(int indice) {
        int tamanho = dados.size();
        int maiorOuMenor = indice; //assume que o índice atual é o maior (ou menor)

        int esquerdo = filhoEsquerdo(indice); //indice do filho esquerdo
        int direito = filhoDireito(indice);  //indice do filho direito

        //verifica se o filho esquerdo tem maior ou menor prioridade que o nó atual
        if (esquerdo < tamanho && comparar(dados[esquerdo], dados[maiorOuMenor])) {
            maiorOuMenor = esquerdo;
        }

        //verifica se o filho direito tem maior ou menor prioridade que o nó atual
        if (direito < tamanho && comparar(dados[direito], dados[maiorOuMenor])) {
            maiorOuMenor = direito;
        }

        //se um dos filhos tem maior prioridade, troca e continua ajustando
        if (maiorOuMenor != indice) {
            std::swap(dados[indice], dados[maiorOuMenor]); // Troca os elementos
            ajustarAbaixo(maiorOuMenor); // Continua ajustando para baixo
        }
    }

    //ajusta a heap para cima a partir de um índice
    void ajustarAcima(int indice) {
        //enquanto o nó não for a raiz e tiver maior prioridade que o pai
        while (indice > 0 && comparar(dados[indice], dados[pai(indice)])) {
            std::swap(dados[indice], dados[pai(indice)]); //troca com o pai
            indice = pai(indice); //atualiza o índice para o pai
        }
    }

public:
    //recebe a função comparadora
    Heap(std::function<bool(int, int)> compararFunc) : comparar(compararFunc) {}

    //constroi a heap a partir de um vetor inicial
    void construirHeap(const std::vector<int>& vetor) {
        dados = vetor; 

        //ajustar todos os nós
        for (int i = dados.size() / 2 - 1; i >= 0; --i) {
            ajustarAbaixo(i);
        }
    }

    //inserir um novo elemento na heap
    void inserir(int valor) {
        dados.push_back(valor); //adicionando no final do vetor
        ajustarAcima(dados.size() - 1); //ajustando a heap pra cima
    }

    //remove e retorna a raiz da heap
    int removerRaiz() {
        if (dados.empty()) {
            throw std::runtime_error("Heap vazia"); //erro se a heap estiver vazia
        }

        int raiz = dados[0]; //salvar a raiz para retorno
        dados[0] = dados.back(); //substituir a raiz pelo último elemento
        dados.pop_back(); //remover o último elemento

        if (!dados.empty()) {
            ajustarAbaixo(0); //ajustando a heap para baixo
        }

        return raiz; //retorna a raiz removida
    }

    //altera a prioridade de um elemento e ajusta a heap
    void alterarPrioridade(int indice, int novoValor) {
        if (indice < 0 || indice >= dados.size()) {
            throw std::out_of_range("Índice fora do intervalo"); //erro para índice inválido
        }

        int valorAntigo = dados[indice]; //salva o valor antigo para comparar
        dados[indice] = novoValor; // 

        //ajustar para cima ou para baixo
        if (comparar(novoValor, valorAntigo)) {
            ajustarAcima(indice);
        } else {
            ajustarAbaixo(indice);
        }
    }

    //exibir os elementos da heap
    void exibirHeap() const {
        for (int valor : dados) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    //heap inicial fornecida pelo slide para testes
    std::vector<int> vetor = {50, 48, 45, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};
    Heap heapMax([](int a, int b) { return a > b; }); //cria uma heap máxima

    //construir a heap máxima
    heapMax.construirHeap(vetor);
    std::cout << "Heap inicial: ";
    heapMax.exibirHeap();

    //alteração de prioridade: raiz (50 para 10)
    heapMax.alterarPrioridade(0, 10);
    std::cout << "Após alterar a prioridade da raiz do número 50 para o número 10: ";
    heapMax.exibirHeap();

    //alteração de prioridade: nó (21 para 36)
    int indice_21 = 15; //indice do nó 21
    heapMax.alterarPrioridade(indice_21, 36);
    std::cout << "Após alterar a prioridade do nó 21 para o nó 36: ";
    heapMax.exibirHeap();

    //inserir: nó 47
    heapMax.inserir(47);
    std::cout << "Após inserir o nó 47: ";
    heapMax.exibirHeap();

    //remoção: nó 50 (raiz antes de alterações)
    int raizRemovida = heapMax.removerRaiz();
    std::cout << "Raiz removida: " << raizRemovida << std::endl;
    std::cout << "Após remover a raiz: ";
    heapMax.exibirHeap();

    return 0;
}
