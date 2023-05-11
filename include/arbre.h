#ifndef __ABR__H__
#define __ABR__H__

    typedef struct noeud
    {
        struct noeud* parent;
        info valeur;
        element* fils;
    }noeud;

    noeud* new_noeud(info);
    void init_noeud(noeud*);
    bool est_feuille(noeud*);
    bool est_racine(noeud*);
    bool est_interne(noeud*);
    void add_fils(noeud*,info);
    void free_noeud(noeud*);

    typedef struct abr
    {
        noeud* racine;
    }abr;

    void init_abr(abr*);
    bool abr_vide(abr*);
    int nombre_noeud(abr*);
    void arb_bin(abr*,info*,int);
    


#endif