typedef struct pilha Pilha;

typedef struct elemento Elemento;

Pilha* criaPilha(void);

void empilha(Pilha* p, char c);
void desempilha(Pilha* p);
void destroiPilha(Pilha* p);
void imprimePilha(Pilha* p);
int vazia(Pilha* p);
