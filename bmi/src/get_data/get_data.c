/*
 * get_data.c
 *
 *  Created on: 20 lug 2018
 *      Author: gabriele
 */

#include "get_data.h"

static const char* INSERT_HEIGHT = "\nInserisci l'altezza> cm ";
static const double HUNDRED = 100.0;
static const double ZERO = 0.0;

/**
 * Inserimento da tastiera dell'altezza
 * @return
 */
float get_height(){
	fflush(stdin);
	float height = ZERO;
	printf(INSERT_HEIGHT);
	scanf("%f",&height);
	height = height / HUNDRED;
	return height;
}

const char* INSERT_WEIGHT() {
	return "Inserisci il peso> kg ";
}

/**
 * Inserimento da tastiera del peso
 * @return
 */
float get_weight(){
	fflush(stdin);
	float weight = ZERO;
	printf(INSERT_WEIGHT());
	scanf("%f",&weight);
	return weight;
}

/**
 * Inserimento da tastiera del sesso
 * @return
 */
char get_sex(){
	fflush(stdin);
	char sex='\0';
	while(sex!='M'&&sex!='F'){
		printf("Inserisci il sesso (M-F)> ");
		scanf("%c",&sex);
		sex = toupper(sex);
	}
	return sex;
}
