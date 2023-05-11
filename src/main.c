#include <stdio.h>
#include <stdlib.h>
#include <element.h>
#include <file.h>
#include <pile.h>
#include <arbre.h>

void afficher_arb_bin(abr* ab);

int main(void)
{
	abr ab;
	char tab[] = {'a','b','c','e','f','g','h','i','j','k'};
	arb_bin(&ab,(info*)tab,10);	
	printf("nombre element %d\n",nombre_noeud(&ab));
	afficher_arb_bin(&ab);
	return 0;
}

void afficher_arb_bin(abr* ab)
{
    File fi;
    if(!abr_vide(ab))
    {
        noeud* x;
        emfiler(&fi,(info)ab->racine);
        while(!file_vide(&fi))
        {
            x = (noeud*)defiler(&fi);
            printf("%c\n",*((char*)(x->valeur)));
            if(x->fils != NULL)
            {
                emfiler(&fi,(info)x->fils->value);
                if(x->fils->prev != NULL)
                    emfiler(&fi,(info)x->fils->prev->value);
            }
        }
    }
}