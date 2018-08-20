/*
 * bmi.h
 *
 *  Created on: 20 lug 2018
 *      Author: gabriele
 */

#ifndef SRC_PRINT_RESULTS_BMI_BMI_H_
#define SRC_PRINT_RESULTS_BMI_BMI_H_

#include <assert.h>
#include <stdbool.h>
#include "is_valid_sex/is_valid_sex.h"

/**
 * Calcola l'indice di massa corporea
 * @param height
 * @param weight
 * @return
 */
float bmi(float height, float weight);

/**
 * Calcola se il soggetto è in sovrappeso, in normopeso o in sottopeso
 * @pre il carattere del sesso deve essere un F o una M
 * @param height
 * @param weight
 * @param sex
 * @return
 */
const char* corporature(float height, float weight, char sex);

/**
 * Calcola l'entità del sovrappeso
 * @pre il carattere del sesso deve essere un F o una M
 * @pre l'indice di massa corporea deve essere maggiore di 24 per gli uomini
 *      e maggiore di 22 per le donne
 * @param height
 * @param weight
 * @param sex
 * @return
 */
float overweight(float height, float weight, char sex);

/**
 * Calcola l'entità del sottopeso
 * @pre il carattere del sesso deve essere un F o una M
 * @pre l'indice di massa corporea deve essere minore di 20 per gli uomini
 * 		e minore di 18 per le donne
 * @param height
 * @param weight
 * @param sex
 * @return
 */
float underweight(float height, float weight, char sex);

#endif /* SRC_PRINT_RESULTS_BMI_BMI_H_ */
