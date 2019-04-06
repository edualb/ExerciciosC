typedef struct lista Lista;

typedef struct elemento Elemento;

Lista* criaLista(void);

void inserir(Lista* p, int v);
void remover(Lista* p);
void destroiLista(Lista* p);
void imprimeLista(Lista* p);
void inserirFinal(Lista* l, int v);
