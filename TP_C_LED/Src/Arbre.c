#include <stdint.h>
#include "Arbre.h"

void CreerFeuille(struct noeud * arbre[256], uint32_t tab[256]){
	uint32_t j=0;
	for(uint8_t i = 0; i<255;i++ ){
		if (tab[i] != 0){
			  arbre[j] = malloc(sizeof(struct noeud));
			  arbre[j]->occurence = tab[i];
			  arbre[j]->c = (char)i;
			  j++;
		}
	}
}
