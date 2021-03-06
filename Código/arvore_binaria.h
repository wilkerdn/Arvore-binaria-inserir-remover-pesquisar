#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   struct no *esq;
   struct no *dir;
   int num;
}No;

typedef struct arvore {
   No *raiz;
}Arvore;

No* cria_no(int num);
Arvore* cria_arvore(int num);
void pesquisa_no(No *tree, int num);
void pesquisa_no_NR(No *tree, int num);
No* acha_menor(No *tree);
void insere_no(No *tree, int num);
void insere_no_NR(No *tree, int num);
No *remove_no(No *tree, int num);
void deletar_arvore(No *tree);