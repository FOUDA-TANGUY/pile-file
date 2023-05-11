#include <stdlib.h>
#include <element.h>
#include <file.h>

void init_file(File* Fi)
{
    Fi->nombre = 0;
    Fi->tete = NULL;
    Fi->queue = NULL;
}
bool file_vide(File* Fi)
{
    if(Fi->tete == NULL && Fi->queue == NULL)
        return TRUE;
    return FALSE;
}
int nombre_file(File* Fi)
{
    return Fi->nombre;
}
void emfiler(File* Fi, info x)
{
    element* nouv = (element*)malloc(sizeof(element));

    nouv->prev = Fi->queue;
    nouv->value = x;
    nouv->suiv = NULL;

    Fi->nombre = Fi->nombre + 1;
    

    if(file_vide(Fi))
        Fi->tete = nouv;
    else
        Fi->queue->suiv = nouv;
    
    Fi->queue = nouv;

    return ;

}
info defiler(File* Fi)
{
    if(file_vide(Fi))
        return NULL;
    
    Fi->nombre = Fi->nombre - 1;
    info x = Fi->tete->value;
    element* elmt = Fi->tete;
    Fi->tete = elmt->suiv;
    if(Fi->tete != NULL)
        Fi->tete->prev = NULL;
    else
        Fi->queue = NULL;
    free(elmt);
    return x;
}
void vide_file(File* Fi)
{
    info x;
    while(!file_vide(Fi))
    {
        x = defiler(Fi);
        if(x != NULL)
            free(x);
    }
        
}
