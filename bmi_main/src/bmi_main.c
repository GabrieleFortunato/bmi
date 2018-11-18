/*
 ============================================================================
 Name        : bmi_main.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "access/access.h"
#include "close/close.h"
#include "get_data/get_data.h"
#include "intro/intro.h"
#include "print_results/print_results.h"
#include "repeat/repeat.h"

static const char* FILE_MODE = "a";
static const char* ACCESS_FILE_NAME = "accessi.txt";

void print_access(){
	FILE* access = fopen(ACCESS_FILE_NAME, FILE_MODE);
	print_access_on_file(access);
	fclose(access);
}

void calculate_bmi(){
		intro();
		float height = get_height();
		float weight = get_weight();
		char sex = get_sex();
		print_results(height,weight,sex);
		(repeat()) ? calculate_bmi() : close();
}

int main(void) {
	print_access();
	calculate_bmi();
	return EXIT_SUCCESS;
}
