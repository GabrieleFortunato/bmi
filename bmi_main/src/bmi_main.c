/*
 ============================================================================
 Name        : bmi_main.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <close/close.h>
#include <get_data/get_data.h>
#include <intro/intro.h>
#include <print_results/print_results.h>
#include <repeat/repeat.h>

static void calculate_bmi() {
	do {
		intro();
		print_results(get_sex(), get_weight(), get_height());
	} while (repeat());
}

int main(void) {
	calculate_bmi();
	close();
	return EXIT_SUCCESS;
}
