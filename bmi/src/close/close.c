/*
 * close.c
 *
 *  Created on: 23 lug 2018
 *      Author: gabriele
 */

#include "close.h"

static const char* CLEAR_SCREEN = "CLS";

void close(){
	system(CLEAR_SCREEN);
}
