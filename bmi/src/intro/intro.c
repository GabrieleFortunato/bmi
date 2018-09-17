/*
 * intro.c
 *
 *  Created on: 19 lug 2018
 *      Author: gabriele
 */

#include "intro.h"

static const char* CLS = "CLS";
static const char* INTRO =
		"\n"
		"=================================\n"
		"PROGRAMMA DI ANALISI E DI CALCOLO\n"
		"DELL'INDICE DI MASSA CORPOREA\n"
		"=================================\n"
		"a cura di Gabriele Fortunato\n";

void intro(){
	system(CLS);
	puts(INTRO);
}
