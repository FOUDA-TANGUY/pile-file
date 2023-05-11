#include <stdio.h>
#include <stdlib.h>
#include <element.h>
#include <file.h>
#include <pile.h>
#include <arbre.h>

int main(void)
{
	noeud* nd = new_noeud(NULL);
	abr ab;
	init_noeud(nd);
	init_abr(&ab);

	ab.racine = nd;
	add_fils(nd,NULL);
	add_fils(nd,NULL);
	printf("nombre element %d\n",nombre_noeud(&ab));
	add_fils(nd,NULL);
	add_fils(nd,NULL);
	printf("nombre element %d\n",nombre_noeud(&ab));
	free_noeud(nd);

	return 0;
}