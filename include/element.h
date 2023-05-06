#ifndef __ELEMENT__H__
#define __ELEMENT__H__ 

	typedef enum bool
	{
		FALSE,TRUE
	}bool;
	typedef void* info;
	typedef struct element
	{
		struct element* prev;
		info value;
		struct element* suiv;
	}element;

	element* new_element(void);
	void free_element(element*);

#endif
