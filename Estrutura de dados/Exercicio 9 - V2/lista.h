typedef struct lista Lista;

typedef struct elemento Elemento;

int push(Lista* p, int v);

int pushOrdenado(Lista* l, int v);

int pop(Lista* p, int* v);

int vazia(Lista* p);

void libera(Lista* p);

void imprimir(Lista* p);

Lista *pushOrdenadoREC(Lista* l, int v);
