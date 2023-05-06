#include <stdlib.h>
#include <element.h>
#include <pile.h>

void init_pile(Pile* pi)
{
	pi->nombre = 0;
	pi->sommet = NULL;
}
bool est_vide(Pile* pi)
{
	if(pi->sommet == NULL)
		return TRUE;
	return FALSE;
}
int nombre_element(Pile* pi)
{
	return pi->nombre;
}
void empiler(Pile* pi,info x)
{
	element* nouv = new_element();
	nouv->prev = NULL;
	nouv->value = x;
	nouv->suiv = pi->sommet;
	if(est_vide(pi))
	{
		pi->sommet = nouv;
		return ;
	}
	pi->sommet->prev = nouv;
	pi->sommet = nouv;
	pi->nombre = pi->nombre + 1;

	return;
}
info depiler(Pile* pi)
{
	if(est_vide(pi))
		return NULL;
	pi->nombre = pi->nombre - 1;
	info x = pi->sommet->value;
	element* elmt = pi->sommet;
	pi->sommet = elmt->suiv;
	if(pi->sommet != NULL)
		pi->sommet->prev = NULL;
	free_element(elmt);
	return x;
}
void vide_pile(Pile* pi)
{
	while(!est_vide(pi))
		depiler(pi);

	return;
}