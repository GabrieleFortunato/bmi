/*
 * get_data.h
 *
 *  Created on: 19 lug 2018
 *      Author: gabriele
 */

#ifndef GET_DATA_GET_DATA_H_
#define GET_DATA_GET_DATA_H_

#include <ctype.h>
#include <stdio.h>
#include "is_valid_sex/is_valid_sex.h"

/**
 * Inserimento da tastiera dell'altezza
 * @return
 */
float get_height();

/**
 * Inserimento da tastiera del peso
 * @return
 */
float get_weight();

/**
 * Inserimento da tastiera del sesso
 * @return
 */
char get_sex();

#endif /* GET_DATA_GET_DATA_H_ */
