# O que foi feito?

Nesta seção implementamos a ADT redBlackTree, proporcionando uma interface que provê os seguintes métodos inserção, busca, remoção e rotação à esquerda e à direita.

# Como rodar?

Verifique se o compilador gcc está instalado na sua máquina.

Em seguida, dentro da pasta [./Rubro-negra] compile o o código com:
```
g++ main.cpp -o [nome_do_executável]
```

e rode com:

```
./[nome_do_executável]
```

obs.: os colchetes "[]" não devem entrar no código, são apenas exemplos de placeholder.

# Hardware, IDE e tecnicismos

Fora utilizado a linguagem de programação C++ 17 com o compilador gcc 13.3.0.

Especificações da máquina:

8,0 GiB RAM, Intel® Core™ i7-7500U × 4, Intel® HD Graphics 620 (KBL GT2), 64-bit

Editor de texto VSCODE

SO Ubuntu 24.04.1 LTS "noble"
Kernel: Linux 6.8.0-51-generic

# Funções principais presentes no código:

Implementação de uma árvore rubro-negra em C++ com operações de inserção, remoção e busca. A seguir as principais funções presentes e um resumo delas.

### Estratégia de balanceamento:
O balanceamento da redBlackTree se dá através das funções de rotações e fix.

### insert(T value):

Insere um valor na árvore. Cria um novo nó e chama a função ```insertNode``` para adicioná-lo à árvore e balanceá-la.

### remove(T value):

Remove o nó que contém o valor ```value```. Localiza o nó com a função ```searchNode``` e, em seguida, chama ```removeNode``` para removê-lo de forma balanceada.

### search(T value):

Busca um valor na árvore. Retorna ```true``` se o valor for encontrado e ```false``` caso contrário.

### printTree(std::shared_ptr<Node<T>> root, std::string indent = "", bool last = true):

Exibe a estrutura da árvore de forma visual, mostrando os valores dos nós e suas cores.

### fixInsert(std::shared_ptr<Node<T>> k):

Corrige a árvore após a inserção de um nó, garantindo que as propriedades da árvore rubro-negra sejam mantidas.

### fixRemove(std::shared_ptr<Node<T>> x):

Corrige a árvore após a remoção de um nó, garantindo o balanceamento da árvore rubro-negra.
