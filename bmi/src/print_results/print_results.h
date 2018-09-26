/*
 * print_result.h
 *
 *  Created on: 23 lug 2018
 *      Author: gabriele
 */

#ifndef SRC_PRINT_RESULTS_PRINT_RESULTS_H_
#define SRC_PRINT_RESULTS_PRINT_RESULTS_H_

#include <stdio.h>
#include "print_results/bmi/bmi.h"

/**
 * Stampa a video i risultati
 * @param sex
 * @param weight
 * @param height
 */
void print_results(float height, float weight, char sex);

#endif /* SRC_PRINT_RESULTS_PRINT_RESULTS_H_ */
