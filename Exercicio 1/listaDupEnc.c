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
	char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
	char alfabetoUpperCase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};
	
	if(agendaAux == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	
	agendaAux->prox = NULL;
	agendaAux->ant = NULL;
	
	printf("Digite o nome:\n");
	scanf(" %[^\n]", agendaAux->nome);

	printf("Digite o telefone:\n");
	scanf(" %[^\n]", agendaAux->telefone);
	
	if (l->prim == NULL) {
		l->prim = agendaAux;
		return;	
	}
	
	Agenda* percorreAgenda = l->prim;
	while (percorreAgenda->prox != NULL) {
		percorreAgenda = percorreAgenda->prox;
	}
	
	percorreAgenda->prox = agendaAux;
	agendaAux->ant = percorreAgenda;
}

void imprimir (Lista* l) {
	printf(" \n");
	printf("----------------\n");
	printf("-----Agenda-----\n");
	printf("----------------\n");

	Agenda* percorreAgenda = l->prim;
	while (percorreAgenda->prox != NULL) {
		printf(" \n");
		printf("Nome: %s\n", percorreAgenda->nome);
		printf("Telefone: %s\n", percorreAgenda->telefone);
		percorreAgenda = percorreAgenda->prox;
	}
	
	printf(" \n");
	printf("Nome: %s\n", percorreAgenda->nome);
	printf("Telefone: %s\n", percorreAgenda->telefone);
}
