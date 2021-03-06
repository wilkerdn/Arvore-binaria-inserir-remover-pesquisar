#include "arvore_binaria.h"

No* cria_no(int num){
	No *tree;
	tree = (No*) malloc(sizeof(No));
	
	tree->esq = NULL;
	tree->dir = NULL;
	tree->num = num;
	
	return tree;
}

Arvore* cria_arvore(int num){
	Arvore *tree;
	tree = (Arvore*) malloc(sizeof(Arvore));
	tree->raiz = cria_no(num);
	
	return tree;
}

void pesquisa_no(No *tree, int num) {
	if(tree == NULL) {
		printf("Numero %d NAO esta presente na arvore\n",num);
	} else if(num < tree->num) {
		pesquisa_no(tree->esq, num); /* busca no filho esquerdo */
	} else if(num > tree->num) {
		pesquisa_no(tree->dir, num); /* busca no filho direito */
	} else {
		printf("Numero %d esta presente na arvore\n",num);
	}
}

void pesquisa_no_NR(No *tree, int num) {
	int p=1;
	while(p!=0){
	if(tree->num==num){
	printf("Elemento encontrado: %d\n",num);
	p = 0;
	}else if(num > tree->num){
		if(tree->dir==NULL){
		printf("O elemento %d nao esta presente na arvore\n",num);
		p=0;
		}else{
		tree = tree->dir;
		}
	}else{
		if(tree->esq==NULL){
		printf("O elemento %d nao esta presente na arvore\n",num);
		p=0;
		}else{
		tree = tree->esq;
		}
	}
	}
}

No* acha_menor(No *tree) {
	if(tree->esq == NULL) {
		return tree;
	}
	return acha_menor(tree->esq);
}

void insere_no(No *tree, int num) {
	if(num < tree->num) { /* num menor */
		if(tree->esq) {
			insere_no(tree->esq, num);
		} else { /* achou local de inserção */
			No *novo = cria_no(num);
			tree->esq = novo;
		}
	} else { /* num maior ou igual ao nodo atual */
		if(tree->dir) {
			insere_no(tree->dir, num);
		} else {
			No *novo = cria_no(num);
			tree->dir = novo;
		}
	}
}

void insere_no_NR(No *tree, int num){
	int ins=1;
	while(ins!=0){
	if(num > tree->num||num == tree->num){
		if(tree->dir==NULL){
		No *novo = cria_no(num);
		tree->dir = novo;
		ins=0;
		}else{
		tree = tree->dir;
		}
	}else{
		if(tree->esq==NULL){
		No *novo = cria_no(num);
		tree->esq = novo;
		ins=0;
		}else{
		tree = tree->esq;
		}
	}
	}
}

No *remove_no(No *tree, int num){
	No *aux;
	
	if(tree == NULL) {
		printf("Elemento ausente\n");
	} else if(num < tree->num){
		tree->esq = remove_no(tree->esq, num);		// busca elemento a esquerda da arvore
	} else if(num > tree->num){
		tree->dir = remove_no(tree->dir, num);		// busca elemento a direita da arvore
	} else if(tree->esq == NULL && tree->dir == NULL) {
		free(tree);
		return NULL; /* zero filhos */
	} else if(tree->esq == NULL) {
		aux = tree->dir;
		free(tree);
		return aux; /* 1 filho direita */
	} else if(tree->dir == NULL) {
		aux = tree->esq;
		free(tree);
		return aux; /* 1 filho esquerda */
	} else { /* 2 filhos */
		No *menor = acha_menor(tree->dir);
		tree->num = menor->num;
		tree->dir = remove_no(tree->dir, menor->num);
		return tree;
	}
	
	return tree;
	
}

void deletar_arvore(No *tree){
	No *esquerda;
	No *direita;
	while(tree->esq!=NULL){
	esquerda = tree->esq;
	remove_no(tree,esquerda->num);
	}
	while(tree->dir!=NULL){
	direita = tree->dir;
	remove_no(tree,direita->num);
	}
	free(tree);
}
