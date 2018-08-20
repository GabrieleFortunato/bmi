/*
 * is_valid_sex.c
 *
 *  Created on: 20 ago 2018
 *      Author: gabriele
 */

#include "is_valid_sex.h"

static const char F = 'F';
static const char M = 'M';

bool is_valid_sex(char sex){
	return sex == M || sex == F;
}
