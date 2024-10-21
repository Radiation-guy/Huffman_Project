#include "occurence.h"
#include <stdint.h>

void occurance (uint8_t* chaine, uint32_t tab[256]){
	while((*chaine) != ('\0')){
		tab[*chaine] ++;
		chaine ++;
	}
}
