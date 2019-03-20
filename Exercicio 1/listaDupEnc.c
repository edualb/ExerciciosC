#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

struct lista {
	Agenda* prim;
};

struct agenda {
	char nome[30];
	char telefone[11];
	Agenda* prox;
	Agenda* ant;
};

Lista* criaLista () {
	Lista* l = (Lista*) malloc(sizeof(Lista));
	
	if (l == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	l->prim = NULL;
	printf("Memoria da Lista alocada.\n");
	return l;
}

void inserir (Lista* l) {
	Agenda* agendaAux = (Agenda*) malloc(sizeof(Agenda));
	
	if(agendaAux == NULL) {
		printf("MEmoria cheia.");
		exit(1);
	}
	
	agendaAux->prox = NULL;
	agendaAux->ant = NULL;
	
	printf("Digite o nome:\n");
	scanf("%[^\n]", agendaAux->nome);

	printf("Digite o telefone:\n");
	scanf(" %[^\n]", agendaAux->telefone);
	
	l->prim = agendaAux;	
}

void imprimir (Lista* l) {
	printf(" \n");
	printf("----------------\n");
	printf("-----Agenda-----\n");
	printf("----------------\n");
	printf(" \n");
	
	printf("Nome: %s\n", l->prim->nome);
	printf("Telefone: %s\n", l->prim->telefone);
	
}
