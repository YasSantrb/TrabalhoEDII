#include <stdio.h>
#include <stdlib.h>

struct no {
    char conteudo;
    struct no *sae;
    struct no *sad;
};
typedef struct no No;

No *criar(char c, No *e, No *d){
    No *arv = malloc(sizeof(No));
    arv -> conteudo = c;
    arv -> sae = e;
    arv -> sad = d;
    return arv;
}

int buscar(No *a, char c){
    if(a == NULL){
        return 0;
    } else {
        return a -> conteudo == c || buscar(a -> sae, c) || buscar(a -> sad, c);
    }
}

int alturaNivel (No *a){
    if (a == NULL) {
        return -1;
    } else{
        int esq = alturaNivel(a -> sae);
        int dir = alturaNivel(a -> sad);
        return (esq > dir ? esq : dir) + 1;
    }
}

int alturaNo (No *a){
    if (a == NULL){
        return 0;
    } else {
        int esq = alturaNo(a -> sae);
        int dir = alturaNo(a -> sad);
        return (esq > dir ? esq : dir) + 1;
    }
}

void liberar(No *a){
    if(a != NULL){
        liberar(a->sae);
        liberar(a->sad);
        printf("\nLiberando nó com conteudo: %c\n", a->conteudo);
        free(a);
    }
}

int main()
{
    No *a1 = criar('d', NULL, NULL);
    No *a2 = criar('e', NULL, NULL);
    No *a3 = criar('f', NULL, NULL);
    No *a4 = criar('b', NULL, a1);
    No *a5 = criar('c', a2, a3);
    No *a6 = criar('a', a4, a5);
    
    printf("Arvore criada com raiz: %c\n", a6->conteudo);
    
    char letra = 'e';
    int resultado = buscar(a6, letra);
    if (resultado) {
        printf("Elemento '%c' encontrado!\n", letra);
    } else {
        printf("Elemento '%c' nao encontrado!\n", letra);
    }

    
    int n = alturaNivel(a6);
    printf("A altura da árvore por níveis é: %d", n);
    
    int y = alturaNo(a6);
    printf("\nA altura da árvore por quantidade de nós é: %d", y);
    
    liberar(a1);
}