/*
 * get_data.c
 *
 *  Created on: 20 lug 2018
 *      Author: gabriele
 */

#include "get_data.h"

static const char EOS = '\0';
static const char* SPEC_CHAR = "%c";
static const char* INSERT_SEX = "Inserisci il sesso (M-F)> ";
static const char* SPEC_FLOAT = "%f";
static const char* INSERT_WEIGTH = "Inserisci il peso> kg ";
static const char* INSERT_HEIGHT = "\nInserisci l'altezza> cm ";
static const double HUNDRED = 100.0;
static const double ZERO = 0.0;

float get_height(){
	fflush(stdin);
	float height = ZERO;
	printf(INSERT_HEIGHT);
	scanf(SPEC_FLOAT, &height);
	height = height / HUNDRED;
	return height;
}

float get_weight(){
	fflush(stdin);
	float weight = ZERO;
	printf(INSERT_WEIGTH);
	scanf(SPEC_FLOAT, &weight);
	return weight;
}

static char insert_sex(char sex) {
	printf(INSERT_SEX);
	scanf(SPEC_CHAR, &sex);
	sex = toupper(sex);
	return sex;
}

char get_sex(){
	fflush(stdin);
	char sex = EOS;
	while (!is_valid_sex(sex))
		sex = insert_sex(sex);
	return sex;
}
