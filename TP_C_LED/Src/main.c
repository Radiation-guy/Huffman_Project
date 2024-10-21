#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "occurence.h"

#define  DEBUG_LEVEL 2

#if DEBUG_LEVEL == 0
#define D1 0
#define D2 0
#endif

#if DEBUG_LEVEL == 1
#define D1 1
#define D2 0
#endif

#if DEBUG_LEVEL == 2
#define D1 1
#define D2 1
#endif

#define debug(level,...) do {if(level == 1){printf(__VA_ARGS__)};}while(0)

#define TAILLE_MAX_Compress 500

// Texte non compressé
uint8_t texte[]="aaaabbbccd";
// Texte compressé
uint8_t texteCompress[TAILLE_MAX_Compress];
// Tableau du nombre d’occurrence de chaque caractère
uint32_t tabCaractere[256]={0};
// Nombre de caractère total dans le texte non compressé
uint32_t nbrCaractereTotal = 0;
// Nombre de caractère différent dans le texte non compréssé
uint32_t nbrCaractereDifferent = 0;
// Arbre de Huffman
struct noeud* arbreHuffman[256];

uint32_t tabCaractere[256];

int main(void)
{
	GPIO_Init();
	USART2_Init();
	SYSTICK_Init();
	occurance(texte, tabCaractere);
	while(1){
	printf("occurance de a = %ld, b= %ld, c=%ld, d=%ld \r\n", tabCaractere[97], tabCaractere[98], tabCaractere[99], tabCaractere[100]);
	}
}