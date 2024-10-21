#include <stdint.h>
#include "Arbre.h"
#include <stdlib.h>

void CreerFeuille(struct noeud * arbre[256], uint32_t tab[256]){
	uint32_t j=0;
	for(uint32_t i = 0; i<255;i++ ){
		if (tab[i] != 0){
			  arbre[j] = malloc(sizeof(struct noeud));
			  arbre[j]->occurence = tab[i];
			  arbre[j]->c = (char)i;
			  j++;
		}
	}
}

void afficherTabArbreHuffman(struct noeud* arbre[256], uint32_t taille){
	printf("Début de Tableau \r\n");
	for(uint32_t i = 0; i<taille;i++ ){
			if (arbre[i] != 0){
				printf("c = %c \r\n",arbre[i]->c);
				printf("occurence = %d \r\n",arbre[i]->occurence);
				printf("code = %d \r\n",arbre[i]->code);
				printf("tailleCode = %d \r\n",arbre[i]->tailleCode);
				printf("gauche = %X \r\n",arbre[i]->gauche);
				printf("droite = %X \r\n",arbre[i]->droite);
				printf("	\r\n");
			}
		}
	printf("Fin de Tableau \r\n");
	printf("	\r\n");
	printf("	\r\n");
	printf("	\r\n");
}

void triArbre(struct noeud* arbre[256], uint32_t taille){
	for(uint32_t j = 0; j<taille;j++ ){
		for(uint32_t i = 0; i<taille;i++ ){
			if (arbre[i]->occurence > arbre[i+1]->occurence){
				struct noeud * temp;
				temp = arbre[i+1];
				arbre[i+1] = arbre[i];
				arbre[i] = temp;
			}
		}
	}
}

void FaireArbre(struct noeud* arbre[256], uint32_t taille){
	struct noeud * temp;

	while(taille>1){
		for(uint32_t i = 0; i<taille;i++ ){

			temp = malloc(sizeof(struct noeud));
			temp->c = '!';
			temp->occurence = arbre[i]->occurence + arbre[i+1]->occurence;
			temp->code = 0;
			temp->tailleCode = 0;
			temp->gauche = arbre[0];
			temp->droite = arbre[1];
			arbre[0] = temp;
			}
		for(uint32_t i = 1; i<taille;i++ ){
				arbre[i] = arbre[i+1];
		}
		taille--;
	}
	afficherTabArbreHuffman(arbre, 4);
}


void parcourirArbre(struct noeud* ptrNoeud){
	if(ptrNoeud ->droite==NULL && ptrNoeud ->gauche==NULL){
		printf("Je suis une feuille\r\n");
	}
	else{
		printf("Je suis un nœud\r\n");
		parcourirArbre(ptrNoeud ->droite); // On va a droite
		parcourirArbre(ptrNoeud ->gauche); // On va a gauche
	}
}


