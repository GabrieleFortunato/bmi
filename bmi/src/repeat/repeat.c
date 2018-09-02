/*
 * repeat.c
 *
 *  Created on: 23 lug 2018
 *      Author: gabriele
 */

#include "repeat.h"

static const int TWO = 2;
static const int ONE = 1;
static const char* SPEC_INT = "%d";
static const char* ASK_REPEAT =
		"\n\nCalcolare un altro indice di massa corporea?\n(1=si, 2=no) ";

int get_repeat() {
	int repeat;
	do {
		printf(ASK_REPEAT);
		scanf(SPEC_INT, &repeat);
	} while (repeat != ONE && repeat != TWO);
	return repeat;
}

bool repeat(){
	return get_repeat() == ONE;
}
