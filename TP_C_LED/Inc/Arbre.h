#include <stdint.h>

struct noeud{
uint8_t c; // Caractère initial
uint32_t occurence; // Nombre d'occurrences
uint32_t code; // Code binaire dans l'arbre
uint32_t tailleCode; // Nombre de bits du code
struct noeud *gauche, *droite;// Lien vers les nœuds suivants
};

void CreerFeuille(struct noeud * arbre[256], uint32_t tab[256]);
