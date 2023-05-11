#include <stdlib.h>
#include <element.h>
#include <file.h>
#include <arbre.h>

noeud* new_noeud(info x)
{
    noeud* nd = (noeud*)malloc(sizeof(noeud));
    init_noeud(nd);
    nd->valeur = x;
    return nd;
}
void init_noeud(noeud* nd)
{
    nd->parent = NULL;
    nd->valeur = NULL;
    nd->fils = NULL;
}
bool est_feuille(noeud* nd)
{
    if(nd->fils == NULL)
        return TRUE;
    return FALSE;
}
bool est_racine(noeud* nd)
{
    if(nd->parent == NULL)
        return TRUE;
    return FALSE;
}
bool est_interne(noeud* nd)
{
    if(!est_racine(nd) && !est_feuille(nd))
        return TRUE;
    return FALSE;
}

void init_abr(abr* ab)
{
    ab->racine = NULL;
}
bool abr_vide(abr* ab)
{
    if(ab->racine == NULL)
        return TRUE;
    return FALSE;
}
    