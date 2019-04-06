typedef struct fila Fila;

Fila* cria(void);

void insere(Fila* f, float v);

float retira(Fila* f);

int vazia(Fila* f);

void libera(Fila* f);

int tamanho(Fila* f);

void imprime(Fila *f);
