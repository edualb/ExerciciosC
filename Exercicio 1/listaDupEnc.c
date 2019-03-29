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
	ordenaAlfabeticamenteRecursiva(percorreAgenda, agendaAux);
	reposicionarInicioLista(l);
}

void ordenaAlfabeticamenteRecursiva(Agenda* agendaAtual, Agenda* agendaInsere) {
	if (agendaAtual == NULL || agendaInsere == NULL) {
		printf("entrou aqui\n");
		return;
	}
	if (strcmp(agendaInsere->nome, agendaAtual->nome) < 0) {
		printf("Troca a posicao\n");
		agendaInsere->prox = agendaAtual;
		agendaInsere->ant = agendaAtual->ant;
		
		if (agendaAtual->ant != NULL) {
			agendaAtual->ant->prox = agendaInsere;
		}
		
		agendaAtual->ant = agendaInsere;
		return;
	} else {
		if (agendaAtual->prox == NULL) {
			printf("Insere na ultima\n");
			agendaAtual->prox = agendaInsere;
			agendaInsere->ant = agendaInsere;
			return;
		}
		ordenaAlfabeticamenteRecursiva(agendaAtual->prox, agendaInsere);
	}
}

void reposicionarInicioLista(Lista* l) {
	Agenda* agenda = l->prim;
	while (agenda->ant != NULL) {
		l->prim = agenda->ant;
		agenda = agenda->ant;
	}
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
