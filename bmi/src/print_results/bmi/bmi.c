/*
 * bmi.c
 *
 *  Created on: 20 lug 2018
 *      Author: gabriele
 */

#include <print_results/bmi/bmi.h>

static const char M = 'M';
static const char* EXTRA_UNDER_WEIGHT = "Soggetto in forte sottopeso";
static const char* UNDER_WEIGHT = "Soggetto in leggero sottopeso";
static const char* OK_WEIGHT = "Soggetto in peso forma";
static const char* EXTRAWEIGHT = "Soggetto in leggero sovrappeso";
static const char* EXTRA_OVERWEIGHT = "Soggetto in forte sovrappeso";
static const int EXTRA_MIN_BMI_F = 16;
static const int MIN_BMI_F = 18;
static const int EXTRA_MIN_BMI_M = 18;
static const int MIN_BMI_M = 20;
static const int MAX_BMI_F = 22;
static const int MAX_BMI_M = 24;
static const int EXTRA_MAX_BMI_F = 28;
static const int EXTRA_MAX_BMI_M = 30;

float bmi(float height, float weight){
	return weight / height / height;
}

static const char* corporature_M(float height, float weight){
	return (bmi(height, weight) > EXTRA_MAX_BMI_M) ? EXTRA_OVERWEIGHT :
			(bmi(height, weight) > MAX_BMI_M) ? EXTRAWEIGHT :
			(bmi(height, weight) > MIN_BMI_M) ? OK_WEIGHT :
			(bmi(height, weight) > EXTRA_MIN_BMI_M) ?
					UNDER_WEIGHT :
					EXTRA_UNDER_WEIGHT;
}

static const char* corporature_F(float height, float weight){
	return (bmi(height, weight) > EXTRA_MAX_BMI_F) ? EXTRA_OVERWEIGHT :
			(bmi(height, weight) > MAX_BMI_F) ? EXTRAWEIGHT :
			(bmi(height, weight) > MIN_BMI_F) ? OK_WEIGHT :
			(bmi(height, weight) > EXTRA_MIN_BMI_F) ?
						UNDER_WEIGHT :
						EXTRA_UNDER_WEIGHT;
}

const char* corporature(float height, float weight, char sex){
	assert(is_valid_sex(sex));
	return (sex == M) ?
			corporature_M(height, weight) : corporature_F(height, weight);
}

static float overweight_M(float height, float weight){
	assert(bmi(height, weight) > MAX_BMI_M);
	return (bmi(height, weight) - MAX_BMI_M) * height * height;
}

static float overweight_F(float height, float weight){
	assert(bmi(height, weight) > MAX_BMI_F);
	return (bmi(height, weight) - MAX_BMI_F) * height * height;
}

float overweight(float height, float weight, char sex){
	assert(is_valid_sex(sex));
	return (sex == M) ?
			overweight_M(height, weight) : overweight_F(height, weight);
}

static float underweight_M(float height, float weight){
	assert(bmi(height, weight) < MIN_BMI_M);
	return (MIN_BMI_M - bmi(height, weight) ) * height * height;
}

static float underweight_F(float height, float weight){
	assert(bmi(height, weight) < MIN_BMI_F);
	return (MIN_BMI_F - bmi(height, weight)) * height * height;
}

float underweight(float height, float weight, char sex){
	assert(is_valid_sex(sex));
	return (sex == M) ?
			underweight_M(height, weight) : underweight_F(height, weight);
}
