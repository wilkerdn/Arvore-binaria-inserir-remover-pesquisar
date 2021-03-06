#include "arvore_binaria.h"

int main(){
	Arvore *tree = cria_arvore(5);
	insere_no_NR(tree->raiz,15);
	insere_no_NR(tree->raiz,4);
	insere_no_NR(tree->raiz,2);
	insere_no_NR(tree->raiz,22);
	insere_no_NR(tree->raiz,16);
	pesquisa_no_NR(tree->raiz, 100);
	pesquisa_no(tree->raiz, 4);
	pesquisa_no_NR(tree->raiz, 16);
	deletar_arvore(tree->raiz);
	free(tree);
	return 0;
}
