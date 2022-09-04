#include "header.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"

int init_suite(void)
{
	return 0;
}

int clean_suite(void)
{
	return 0;
}

void test_strike(void)
{
	CU_ASSERT(strike_condition(1,10) == 1);  // (int balls, int current_score)
	CU_ASSERT(strike_condition(2,10) == 0);
}

void test_spare(void)
{
	CU_ASSERT(spare_condition(1,9) == 1);   // (int previous_score, int current_score)
	CU_ASSERT(spare_condition(2,8) == 1);
	CU_ASSERT(spare_condition(3,7) == 1);
	CU_ASSERT(spare_condition(4,6) == 1);
	CU_ASSERT(spare_condition(5,5) == 1);
}

void test_extra_balls(void)
{
	CU_ASSERT(extra_balls(1) == 2); // (ball_number)
	CU_ASSERT(extra_balls(2) == 1);
}

int main(void)
{
	CU_pSuite pSuite1,pSuite2,pSuite3 = NULL;
	if(CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	pSuite1=CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
	if(pSuite1 == NULL)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//add test1 to suite1
	
	if((NULL == CU_add_test(pSuite1, "\n\n----------Testing Strike Function----------\n\n", test_strike)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//add test2 to suite2
	
	if((NULL == CU_add_test(pSuite1, "\n\n--------Testing Spare Function----------\n\n",test_spare)))
	{
		CU_cleanup_registry();
		return CU_get_error();
        }

	//add test3 to suite3

        if((NULL == CU_add_test(pSuite1, "\n\n ----------Testing for Extra balls-------\n\n",test_extra_balls)))
         {
		 CU_cleanup_registry();
		 return CU_get_error();
	 }
	 CU_basic_run_tests(); //Output to the screen

	 CU_cleanup_registry(); // cleaning the Registry

}


	


	



