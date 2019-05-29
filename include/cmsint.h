#ifndef CMSINT_H
#define CMSINT_H

/**
 * \file cmsint.h
 * \brief Représente les signatures des fonctions de la librairie. 
 * \author Clément CAUMES
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t get_bit_uint64_t (uint64_t elem, uint8_t i);
uint8_t get_bit_uint64_t_reverse (uint64_t elem, uint8_t i);
int set_bit_uint64_t (uint64_t* elem, uint8_t bit, uint8_t pos);
void printf_uint64_t_binary(uint64_t key);
void printf_uint64_t_hexa(uint64_t key);

uint8_t get_bit_uint32_t (uint32_t elem, uint8_t i);
uint8_t get_bit_uint32_t_reverse (uint32_t elem, uint8_t i);
int set_bit_uint32_t (uint32_t* elem, uint8_t bit, uint8_t pos);
void printf_uint32_t_binary(uint32_t key);
void printf_uint32_t_hexa(uint32_t key);

uint8_t get_bit_uint8_t (uint8_t elem, uint8_t i);
int set_bit_uint8_t (uint8_t* elem, uint8_t bit, uint8_t pos);
void printf_uint8_t_binary(uint8_t key);
void printf_uint8_t_hexa(uint8_t key);

#endif
