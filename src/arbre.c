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

void add_fils(noeud* nd, info x)
{
    noeud* nouv = new_noeud(x);
    nouv->parent = nd;
    element* elmt = new_element();
    elmt->value = (info)nouv;
    elmt->suiv = NULL;

    elmt->prev = nd->fils;
    
    if(!est_feuille(nd))
        nd->fils->suiv = elmt;
    nd->fils = elmt;
}

void free_noeud(noeud* nd)
{
    element* elmt;
    element* temp = nd->fils;
    elmt = temp;
    while(temp != NULL)
    {
        elmt=elmt->prev;
        if(((noeud*)(temp->value))->valeur != NULL)
            free(((noeud*)(temp->value))->valeur);
        free(temp->value);
        free(temp);
        temp = elmt; 
    }
    free(nd);
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

int nombre_noeud(abr *ab)
{
    int nombre = 0;
    File fi;
    noeud* x;
    element* fils;
    init_file(&fi);
    if(!abr_vide(ab))
    {
        emfiler(&fi,(info)ab->racine);

        while(!file_vide(&fi))
        {
            nombre++;
            x = (noeud*)defiler(&fi);
            fils = x->fils;
            while(fils != NULL)
            {
                emfiler(&fi,fils->value);
                fils = fils->prev;
            }
        }
    }
    
    return nombre;
}

void arb_bin(abr* ab,info* tab,int n)
{
    init_abr(ab);
    if(n < 1)
        return;
    File fi;
    int i = 0;
    noeud* x = new_noeud((tab + i));
    ab->racine = x;
    
    init_file(&fi);
    emfiler(&fi,(info)x);
    i++;
    while(i < n)
    {
        x = (noeud*)defiler(&fi);
        add_fils(x,(info)(tab));
        i++;
        emfiler(&fi,x->fils->value);
        if(i < n)
        {
            add_fils(x,(info)(tab + i));
            emfiler(&fi,x->fils->value);
            i++;
        }
    }
}
