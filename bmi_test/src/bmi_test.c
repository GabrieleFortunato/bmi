/*
 ============================================================================
 Name        : bmi_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <CUnit/basic.h>
#include "print_results/bmi/bmi.h"

int init_suite_default(){
	return 0;
}

int clear_suite_default(){
	return 0;
}

void test_bmi(){
	CU_ASSERT_EQUAL((int)bmi(1.68,88),31);
	CU_ASSERT_EQUAL((int)bmi(1.68,82),29);
	CU_ASSERT_EQUAL((int)bmi(1.68,72),25);
}

void test_corporature(){
	CU_ASSERT_STRING_EQUAL(corporature(1.68,88,'M'),"Soggetto in forte sovrappeso");
	CU_ASSERT_STRING_EQUAL(corporature(1.68,84,'F'),"Soggetto in forte sovrappeso");
	CU_ASSERT_STRING_EQUAL(corporature(1.68,84,'M'),"Soggetto in leggero sovrappeso");
	CU_ASSERT_STRING_EQUAL(corporature(1.68,66,'F'),"Soggetto in leggero sovrappeso");
}

int main(void) {
	CU_initialize_registry();
	CU_pSuite pSuite_A = CU_add_suite("SUITE BMI",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_A,"test of bmi()",test_bmi);
	CU_pSuite pSuite_B = CU_add_suite("SUITE CORP",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_B,"test of corporature()",test_corporature);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
