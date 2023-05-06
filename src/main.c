#include <stdio.h>
#include <stdlib.h>
#include <element.h>
#include <pile.h>

int main(void)
{
	Pile pi;
	init_pile(&pi);
	float* x;
	int i;
	
	for(i = 16; i < 64; i++)
	{
		x = (float*)malloc(sizeof(float));
		*x = i + 0.525;
		empiler(&pi,x);
	}
	while(!est_vide(&pi))
	{
		x = (float*)depiler(&pi);
		printf("%.3f\n",*x);
		free(x);
	}
	return 0;
}