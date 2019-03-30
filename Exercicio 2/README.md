# Exercício 1

Implemente um tipo abstrato de dados (TAD) que ofereça os serviços para a manipulação de uma pilha encadeada de caracteres. Deverão ser implementadas pelo menos as seguintes funções: 

-   criar pilha
-   empilhar e desempilhar elementos da pilha 
-   destruir a estrutura de dados criada

Você pode implementar esta estrutura de dados utilizando vetor ou lista encadeada.

## Solução

A implementação foi feita com lista encadeada:

*   Criar pilha:

    ```C
    Pilha* criaPilha() {
        Pilha* p = (Pilha*) malloc(sizeof(Pilha));
        
        if (p == NULL) {
            printf("Memoria cheia.");
            exit(1);
        }
        
        p->topo = NULL;
        printf("Memoria da pilha criada.\n");
        return p;
    }
    ```

*   Empilhar
    
    Quando um elemento é inserido na pilha: 

    `elemento->prox` passa a ser o `pilha->topo`.
    
    `pilha->topo` passa a ser o `elemento` inserido.

    código:

    ```C
    void empilha(Pilha* p) {
        Elemento* e = (Elemento*) malloc(sizeof(Elemento));
        
        if (e == NULL) {
            printf("Memoria cheia.");
            exit(1);
        }
        
        printf("Digite o valor do elemento:\n");
        scanf("%d", &e->valor);
        
        e->prox = p->topo;
        p->topo = e;
    }
    ```

*   Desempilhar

    Para excluir um elemento da pilha, utilizamos um elemento auxiliar na qual vai ser o responsável por dar o `free(elemento)`

    código:

    ```C
    void desempilha(Pilha* p) {
	    Elemento* e = p->topo;
	    p->topo = p->topo->prox;
	    free(e);
    }
    ```

*   Destruir pilha

    Faz um looping chamando a função desempilha.

    código:

    ```C
    void destroiPilha(Pilha* p) {
        while(p->topo != NULL) {
            desempilha(p);
        }
    }
    ```
