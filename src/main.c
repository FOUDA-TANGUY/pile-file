#include <stdio.h>
#include <stdlib.h>
#include <element.h>
#include <file.h>
#include <pile.h>

int main(void)
{
	Pile pi;
	File fi;

	// initialisation des elements
	init_pile(&pi);
	init_file(&fi);
	
	//fonction du nombre d'elements
	printf("Nombre element de (pile, file) -> (%d, %d)\n",nombre_element(&pi), nombre_file(&fi));

	//fonction d ajout d elements
	empiler(&pi,NULL);
	empiler(&pi,NULL);
	emfiler(&fi,NULL);
	emfiler(&fi,NULL);
	printf("Nombre element de (pile, file) -> (%d, %d)\n",nombre_element(&pi), nombre_file(&fi));

	//fonction de retrait d elements avec renvois d elements
	depiler(&pi);
	depiler(&pi);
	defiler(&fi);
	defiler(&fi);
	printf("Nombre element de (pile, file) -> (%d, %d)\n",nombre_element(&pi), nombre_file(&fi));

	//fonction de netoyage !!! a utiliser si les element on ete declare dynamiquement
	vide_pile(&pi);
	vide_file(&fi);
	return 0;
}