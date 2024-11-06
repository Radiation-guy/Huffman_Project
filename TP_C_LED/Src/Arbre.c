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
	uint8_t tri = 0;
	while(tri==0){
		tri = 1;
		for(uint32_t i = 0; i<taille-1;i++ ){
			if (arbre[i]->occurence > arbre[i+1]->occurence){
				struct noeud * temp;
				temp = arbre[i+1];
				arbre[i+1] = arbre[i];
				arbre[i] = temp;
				tri = 0;
			}
		}
	}
}


void triArbreHelene (struct noeud * arbre[256], uint32_t taille){

	struct noeud *ptr_mystruct_1;
	struct noeud *ptr_mystruct_2;
	uint8_t echange    = 0;         			// drapeau pour vÃ©rifier si il y a eu des echanges
	uint8_t nbrEchange = 0;					    // nbr d'Ã©changes dans la boucle for

	while( echange !=1){

		nbrEchange = 0;

		for (int index = 0; index < taille ; index++) {

			ptr_mystruct_1 = arbre[index];
			ptr_mystruct_2 = arbre[index+1];


			if ( (ptr_mystruct_2->occurence)  < (ptr_mystruct_1->occurence)) {
				arbre[index]   =  ptr_mystruct_2;
				arbre[index+1] =  ptr_mystruct_1;
				nbrEchange++;
			}
		}

		// on verifie qu'il n'y ait pas eu d'Ã©change sinon on recompare tout

		if( nbrEchange == 0){
			echange = 1;
		}
	}
}


void FaireNoeud(struct noeud* arbre[256], uint32_t taille){
	struct noeud * temp;
	temp = malloc(sizeof(struct noeud));
	temp->c = '!';
	temp->occurence = arbre[0]->occurence + arbre[1]->occurence;
	temp->code = 0;
	temp->tailleCode = 0;
	temp->gauche = arbre[0];
	temp->droite = arbre[1];
	arbre[0] = temp;
	for (int index = 1; index < taille-1 ; index++) {
		arbre[index]=arbre[index+1];
	}
}


void parcourirArbre(struct noeud* ptrNoeud){
	if(ptrNoeud ->droite==NULL && ptrNoeud ->gauche==NULL){
		printf("Je suis une feuille\r\n");
		printf("Mon code est : %d \r\n",ptrNoeud->code);
		printf("--------------------------\r\n");
	}
	else{
		printf("Je suis un nœud\r\n");
		parcourirArbre(ptrNoeud ->droite); // On va a droite
		parcourirArbre(ptrNoeud ->gauche); // On va a gauche
	}
}


void creerCode(struct noeud* ptrNoeud,uint32_t code,uint32_t taille){
	if(ptrNoeud ->droite==NULL && ptrNoeud ->gauche==NULL){
			ptrNoeud ->tailleCode=taille;
			ptrNoeud ->code=code;
			printf("%c \t code : %d \t taille :%d \r\n", ptrNoeud ->c, ptrNoeud->code, ptrNoeud->tailleCode);
		}
		else{
			//On va a droite (on injecte un 0 à droite dans le code)
			creerCode(ptrNoeud ->droite,code<<1,taille+1);
			// On va a gauche (On injecte un 1 à droite)
			creerCode(ptrNoeud ->gauche,(code<<1)+1,taille+1);
		}
}


struct noeud* getAddress(struct noeud* ptrNoeud, uint8_t caractere) {
    if (ptrNoeud == NULL) return NULL;

    // Si feuille, vérifier
    if (ptrNoeud->caractere == caractere) {
        return ptrNoeud;
    }

    // Sinon sous-arbres
    struct noeud* leftAddress = getAddress(ptrNoeud->gauche, caractere);
    if (leftAddress != NULL) return leftAddress;

    return getAddress(ptrNoeud->droit, caractere);
}


void ajouterCodeDansTexteCompress(uint8_t* texteCompress, uint8_t* code, uint8_t tailleCode, uint32_t* bitIndex) {
    for (uint8_t i = 0; i < tailleCode; i++) {
        // Placer tableau texteCompress
        uint8_t bit = (code[i / 8] >> (7 - i % 8)) & 1;
        uint32_t byteIndex = (*bitIndex) / 8;
        uint32_t bitPos = (*bitIndex) % 8;

        if (bit) {
            texteCompress[byteIndex] |= (1 << (7 - bitPos));
        } else {
            texteCompress[byteIndex] &= ~(1 << (7 - bitPos));
        }

        (*bitIndex)++;
    }
}
