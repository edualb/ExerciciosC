#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		if (strcmp(agendaAux->nome, percorreAgenda->nome) > 0 && strcmp(agendaAux->nome, percorreAgenda->prox->nome) < 0) {
			agendaAux->prox = percorreAgenda->prox;
			agendaAux->ant = percorreAgenda;
			
			percorreAgenda->prox->ant = agendaAux;
			percorreAgenda->prox = agendaAux;
			return;
		} else {
			percorreAgenda = percorreAgenda->prox;
		}
	}
	
	// condicao caso seja o primeiro
	if (percorreAgenda == l->prim && strcmp(agendaAux->nome, percorreAgenda->nome) < 0) {
		printf("entrou no primeiro\n");
		agendaAux->prox = percorreAgenda;
		percorreAgenda->ant = agendaAux;
		l->prim = agendaAux;
		return;
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
