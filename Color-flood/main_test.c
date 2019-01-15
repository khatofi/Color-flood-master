#include "grid_color.h"
#include "solveur_rapide.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

int main(){
    CU_initialize_registry();

	CU_pSuite suite1 = CU_add_suite("solveur", 0, 0);

	CU_add_test(suite1, "copy", test_copy);
	CU_add_test(suite1, "compteur", test_compteur);
	CU_add_test(suite1, "choixpertinent", test_choixpertinent);
	CU_add_test(suite1, "size_tache", test_size_tache);
	CU_add_test(suite1, "solution_rapide", test_solution_rapide);

   	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}
