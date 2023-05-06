#ifndef __PILE__H__
#define __PILE__H__ 

	typedef struct Pile
	{
		int nombre;
		element* sommet;
	}Pile;

	void init_pile(Pile*);
	bool est_vide(Pile*);
	int nombre_element(Pile*);
	void empiler(Pile*,info);
	info depiler(Pile*);
	void vide_pile(Pile*);

#endif