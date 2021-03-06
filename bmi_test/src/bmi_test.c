/*
 ============================================================================
 Name        : bmi_test.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <CUnit/basic.h>
#include "print_results/bmi/bmi.h"
#include "is_valid_sex/is_valid_sex.h"

int init_suite_default(){
	return 0;
}

int clear_suite_default(){
	return 0;
}

void test_is_valid_sex(){
	CU_ASSERT_TRUE(is_valid_sex('F'));
	CU_ASSERT_TRUE(is_valid_sex('M'));
	CU_ASSERT_FALSE(is_valid_sex('f'));
	CU_ASSERT_FALSE(is_valid_sex('m'));
	CU_ASSERT_FALSE(is_valid_sex('A'));
	CU_ASSERT_FALSE(is_valid_sex('C'));
	CU_ASSERT_FALSE(is_valid_sex('L'));
	CU_ASSERT_FALSE(is_valid_sex('N'));
	CU_ASSERT_FALSE(is_valid_sex('a'));
	CU_ASSERT_FALSE(is_valid_sex('c'));
	CU_ASSERT_FALSE(is_valid_sex('l'));
	CU_ASSERT_FALSE(is_valid_sex('n'));
}

void test_bmi(){
	CU_ASSERT_EQUAL((int)bmi(1.68,88),31);
	CU_ASSERT_EQUAL((int)bmi(1.68,82),29);
	CU_ASSERT_EQUAL((int)bmi(1.68,72),25);
	CU_ASSERT_EQUAL((int)bmi(2.00,64),16);
}

void test_corporature(){
	CU_ASSERT_STRING_EQUAL(corporature(1.68,88,'M'),"Soggetto in forte sovrappeso");
	CU_ASSERT_STRING_EQUAL(corporature(1.68,84,'F'),"Soggetto in forte sovrappeso");
	CU_ASSERT_STRING_EQUAL(corporature(1.68,84,'M'),"Soggetto in leggero sovrappeso");
	CU_ASSERT_STRING_EQUAL(corporature(1.68,66,'F'),"Soggetto in leggero sovrappeso");
}

void test_overweight(){
	CU_ASSERT_EQUAL((int)overweight(1.68,88,'M'),20);
	CU_ASSERT_EQUAL((int)overweight(1.68,88,'F'),25);
}

void test_underweight(){
	CU_ASSERT_EQUAL((int)underweight(1.68,50,'M'),6);
	CU_ASSERT_EQUAL((int)underweight(1.55,37,'F'),6);
}

int main(void) {
	CU_initialize_registry();
	CU_pSuite pSuite_A = CU_add_suite("SUITE VALID SEX",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_A,"test of is_valid_sex()",test_is_valid_sex);
	CU_pSuite pSuite_B = CU_add_suite("SUITE BMI",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_B,"test of bmi()",test_bmi);
	CU_pSuite pSuite_C = CU_add_suite("SUITE CORP",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_C,"test of corporature()",test_corporature);
	CU_pSuite pSuite_D = CU_add_suite("SUITE OVER-UNDERWEIGHT",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_D,"test of overweight()",test_overweight);
	CU_add_test(pSuite_D,"test of underweight()",test_underweight);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
