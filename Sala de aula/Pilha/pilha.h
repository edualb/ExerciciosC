typedef struct pilha Pilha;

typedef struct elemento Elemento;

Pilha* criar(void);

int push(Pilha* p, char c);

int pop(Pilha* p, char* c);

int vazia(Pilha* p);

void libera(Pilha* p);

void imprimir(Pilha* p);
