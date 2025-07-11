#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int conteudo;
    struct celula *prox;
}Celula;

typedef struct celGrafo {
    int conteudoCelGrafo;
    Celula *adj;
    struct celGrafo *prox;
}CelGrafo;

Celula *criarCelula (int n, Celula *p) {
    Celula *x;
    x = malloc(sizeof(Celula));
    x->conteudo = n;
    x->prox = p;
    return x;
};

CelGrafo *criarCelGrafo (int n, Celula *p, CelGrafo *g) {
    CelGrafo *x;
    x = malloc(sizeof(CelGrafo));
    x->conteudoCelGrafo = n;
    x->adj = p;
    x->prox = g;
    return x;
};

void addAresta(CelGrafo *g, int origem, int d){
    CelGrafo *p = g;
    while(p != NULL && p->conteudoCelGrafo != origem){
        p = p->prox;
    }
    Celula *l = p->adj;
    p->adj = criarCelula(d, l);
};

void percorrerListaAdj(CelGrafo *g){
    while (g!=NULL){
        printf("\n\n Vertice: %d", g->conteudoCelGrafo);
        while (g->adj != NULL){
            printf("\n De %d para %d", g->conteudoCelGrafo, g->adj->conteudo);
            g->adj = g->adj->prox;
        }
        g=g->prox;
    }
};

int main()
{
    CelGrafo *g = NULL;
    
    g= criarCelGrafo(1, NULL, g);
    g= criarCelGrafo(2, NULL, g);
    g= criarCelGrafo(3, NULL, g);
    
    addAresta(g, 1, 2);
    addAresta(g, 1, 3);
    addAresta(g, 2, 3);
    addAresta(g, 3, 1);
    
    percorrerListaAdj(g);
}