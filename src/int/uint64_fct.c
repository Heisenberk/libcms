/**
 * \file uint64_fct.c 
 * \brief Représente les fonctions concernant la manipulation de le type uint64_t. 
 * \author Clément CAUMES
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cmsint.h>

/**
 * \fn uint8_t get_bit_uint64_t (uint64_t elem, uint8_t i)
 * \brief Fonction qui permet d'obtenir le i ème bit de elem en sachant
 * que le bit de poids faible est à la position i=1.
 *
 * \param i numéro du bit à obtenir.
 * \param elem uint64_t dont l'on cherche le i ème bit. 
 * \return renvoie 0, 1, (ou 2 en cas d'erreur) en fonction du 
 * i ème bit de elem. 
 */
uint8_t get_bit_uint64_t (uint64_t elem, uint8_t i){
	if(i<0) return 2;
	if(i>64) return 2;
	return (elem>>(i-1))%2;
}


/**
 * \fn uint8_t get_bit_uint64_t_reverse (uint64_t elem, uint8_t i)
 * \brief Fonction qui permet d'obtenir le i ème bit de elem en sachant
 * que le bit de poids fort est à la position i=1.
 *
 * \param i numéro du bit à obtenir.
 * \param elem uint64_t dont l'on cherche le i ème bit. 
 * \return renvoie 0, 1, (ou 2 en cas d'erreur) en fonction du 
 * i ème bit de elem. 
 */
uint8_t get_bit_uint64_t_reverse (uint64_t elem, uint8_t i){
	if(i<0) return 2;
	if(i>64) return 2;
	return (elem>>(64-i))%2;
}


/**
 * \fn int set_bit_uint64_t (uint64_t* elem, uint8_t bit, uint8_t pos)
 * \brief Fonction qui initialise le bit à la position pos de elem. 
 * Le bit de poids faible a la position pos=1. 
 * \param elem élément à modifier
 * \param bit valeur du futur bit à changer. 
 * \param pos position du bit à changer. 
 * \return renvoie 0 en cas de réussite et 1 en cas d'échec
 * (change la valeur de l'erreur).
 */
int set_bit_uint64_t (uint64_t* elem, uint8_t bit, uint8_t pos){
	if(bit==1){
		uint64_t mask=1ULL;
		mask <<= (pos-1);
		(*elem)|=mask;
	}
	else if(bit==0){
		uint64_t mask1=0xFFFFFFFFFFFFFFFF;
		uint64_t mask2=1ULL;
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
 * \fn void printf_uint64_t_binary(uint64_t key);
 * \brief Fonction qui affiche en binaire un uint64_t. 
 *
 * \param key uint64_t à afficher. 
 */
void printf_uint64_t_binary(uint64_t key){
	char* chain; int i; uint8_t bit;
	chain=malloc(65*sizeof(char));
	
	for(i=0;i<64;i++){
		bit=key%2;
		if(bit==0) chain[63-i]='0';
		else chain[63-i]='1';
		key>>=1;
	}
	chain[64]='\0';
	printf("%s\n", chain);
	free(chain);
}


/**
 * \fn void printf_uint64_t_hexa(uint64_t key)
 * \brief Fonction qui affiche en hexa un uint64_t. 
 *
 * \param key uint64_t à afficher. 
 */
void printf_uint64_t_hexa(uint64_t key){
	printf("%016llX", key);
}


