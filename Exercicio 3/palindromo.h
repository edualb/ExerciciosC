typedef struct pilha Pilha;

typedef struct letra Letra;

Pilha* criaPilha(void);

void empilha(Pilha* p, char letra);
void desempilha(Pilha* p, char* sNova);
void palindromo(Pilha* p, char* s);
