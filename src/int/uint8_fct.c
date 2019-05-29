/**
 * \file uint8_fct.c 
 * \brief Représente les fonctions concernant la manipulation de le type uint8_t. 
 * \author Clément CAUMES
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cmsint.h>

/**
 * \fn uint8_t get_bit_uint8_t (uint8_t elem, uint8_t i)
 * \brief Fonction qui permet d'obtenir le i ème bit de elem en sachant
 * que le bit de poids faible est à la position i=1.
 *
 * \param i numéro du bit à obtenir.
 * \param elem uint8_t dont l'on cherche le i ème bit. 
 * \return renvoie 0, 1, (ou 2 en cas d'erreur) en fonction du 
 * i ème bit de elem. 
 */
uint8_t get_bit_uint8_t (uint8_t elem, uint8_t i){
	if(i<0) return 2;
	if(i>8) return 2;
	return (elem>>(i-1))%2;
}


/**
 * \fn int set_bit_uint8_t (uint8_t* elem, uint8_t bit, uint8_t pos)
 * \brief Fonction qui initialise le bit à la position pos de elem. 
 * Le bit de poids faible a la position pos=1. 
 * \param elem élément à modifier
 * \param bit valeur du futur bit à changer. 
 * \param pos position du bit à changer. 
 * \return renvoie 0 en cas de réussite et 1 en cas d'échec
 * (change la valeur de l'erreur).
 */
int set_bit_uint8_t (uint8_t* elem, uint8_t bit, uint8_t pos){
	if(bit==1){
		uint32_t mask=1ULL;
		mask <<= (pos-1);
		(*elem)|=mask;
	}
	else if(bit==0){
		uint32_t mask1=0xFF;
		uint32_t mask2=1ULL;
		mask2 <<= (pos-1);
		mask1 ^= mask2;
		(*elem)&=mask1;
	}
	else {
		return 1;
	}
	return 0;
}


/**
 * \fn void printf_uint8_t_binary(uint8_t key)
 * \brief Fonction qui affiche en binaire un uint8_t. 
 *
 * \param key uint8_t à afficher. 
 */
void printf_uint8_t_binary(uint8_t key){
	char* chain; int i; uint8_t bit;
	chain=malloc(9*sizeof(char));
	for(i=0;i<8;i++){
		bit=key%2;
		if(bit==0) chain[7-i]='0';
		else chain[7-i]='1';
		key>>=1;
	}
	chain[8]='\0';
	printf("%s", chain);
	free(chain);
}


/**
 * \fn void printf_uint8_t_hexa(uint8_t key)
 * \brief Fonction qui affiche en hexa un uint8_t. 
 *
 * \param key uint8_t à afficher. 
 */
void printf_uint8_t_hexa(uint8_t key){
	printf("%x", key);
}
