/*
 * print_result.c
 *
 *  Created on: 23 lug 2018
 *      Author: gabriele
 */


#include <print_results/print_results.h>

static const char M = 'M';
static const char* PRINT_UNDERWEIGHT = "\nEntita' del sottoppeso: kg %.1f";
static const char* PRINT_OVERWEIGHT = "\nEntita' del sovrappeso: kg %.1f";
static const char* PRINT_CORPORATURE = "\n%s";
static const char* PRINT_BMI = "\nIndice di massa corporea: %.2f";

static void print_bmi_corporature(float height, float weight, char sex) {
	printf(PRINT_BMI, bmi(height, weight));
	printf(PRINT_CORPORATURE, corporature(height, weight, sex));
}

static void print_overweight(float height, float weight, char sex) {
	printf(PRINT_OVERWEIGHT,
			overweight(height, weight, sex));
}

static void print_underweight(float height, float weight, char sex) {
	printf(PRINT_UNDERWEIGHT,
			underweight(height, weight, sex));
}

static void print_results_M(float height, float weight, char sex) {
	print_bmi_corporature(height, weight, sex);
	if (bmi(height, weight) > 24 || bmi(height, weight) < 20)
			(bmi(height, weight) > 24) ? print_overweight(height, weight, sex) : print_underweight(height, weight, sex);
}

static void print_results_F(float height, float weight, char sex) {
	print_bmi_corporature(height, weight, sex);
	if (bmi(height, weight) > 22 || bmi(height, weight) < 18)
		(bmi(height, weight) > 22) ? print_overweight(height, weight, sex) : print_underweight(height, weight, sex);
}

void print_results(char sex, float weight, float height){
	(sex == M) ?
			print_results_M(height, weight, sex) :
			print_results_F(height, weight, sex);
}
