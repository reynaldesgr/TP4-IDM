#include <check.h>
#include "../include/pile.h"

DECLARER_PILE(int)
IMPLEMENTER_PILE(int)

DECLARER_PILE(float)
IMPLEMENTER_PILE(float)

DECLARER_PILE(char)
IMPLEMENTER_PILE(char)

START_TEST(test_empiler)
{
    Pileint_t pile;
    pile.top = -1;

    empilerint(42, &pile);
    ck_assert_int_eq(pile.top, 0);
    ck_assert_int_eq(pile.pile[0], 42);
}
END_TEST

START_TEST(test_depiler)
{
    Pileint_t pile;
    pile.top = -1;

    empilerint(42, &pile);
    empilerint(36, &pile);

    int val = depilerint(&pile);
    ck_assert_int_eq(val, 36);
    ck_assert_int_eq(pile.top, 0);
    ck_assert_int_eq(pile.pile[pile.top], 42);
}
END_TEST

START_TEST(test_estVide)
{
    Pileint_t pile;
    pile.top = -1;

    ck_assert_int_eq(estVideint(&pile), true); 

    empilerint(42, &pile);
    ck_assert_int_eq(estVideint(&pile), false);
}
END_TEST

START_TEST(test_empiler_float)
{
    Pilefloat_t pile;
    pile.top = -1;

    empilerfloat(3.14, &pile);
    ck_assert_int_eq(pile.top, 0);
    ck_assert_float_eq(pile.pile[0], 3.14);
}
END_TEST

START_TEST(test_empiler_char)
{
    Pilechar_t pile;
    pile.top = -1;

    empilerchar('a', &pile);
    ck_assert_int_eq(pile.top, 0);
    ck_assert_int_eq(pile.pile[0], 'a');
}
END_TEST


START_TEST(test_multiple_operations)
{
    Pileint_t pile;
    pile.top = -1;

    empilerint(10, &pile);
    empilerint(20, &pile);
    empilerint(30, &pile);

    int val1 = depilerint(&pile);
    int val2 = depilerint(&pile);

    ck_assert_int_eq(val1, 30);
    ck_assert_int_eq(val2, 20);
    ck_assert_int_eq(pile.top, 0);
    ck_assert_int_eq(pile.pile[pile.top], 10);
}
END_TEST


START_TEST(test_pile_vide_apres_dépilement)
{
    Pileint_t pile;
    pile.top = -1;

    empilerint(1, &pile);
    empilerint(2, &pile);
    depilerint(&pile); 
    depilerint(&pile); 

    ck_assert_int_eq(estVideint(&pile), true); 
}
END_TEST


START_TEST(test_taille_pile)
{
    Pileint_t pile;
    pile.top = -1;

    empilerint(1, &pile);
    empilerint(2, &pile);
    empilerint(3, &pile);
    empilerint(4, &pile);
    
    ck_assert_int_eq(pile.top, 3); 
}
END_TEST

Suite *pile_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Pile");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_empiler);
    tcase_add_test(tc_core, test_depiler);
    tcase_add_test(tc_core, test_estVide);
    tcase_add_test(tc_core, test_empiler_float);
    tcase_add_test(tc_core, test_empiler_char);
    tcase_add_test(tc_core, test_multiple_operations);
    tcase_add_test(tc_core, test_pile_vide_apres_dépilement);
    tcase_add_test(tc_core, test_taille_pile);

    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = pile_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
