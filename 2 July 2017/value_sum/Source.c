#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CuTest by Asim Jalis
 * http://cutest.sourceforge.net/
 */
#include "CuTest.h"
#include "value_sum.h"

#define TEST_INTRO_MGS_FMT "Test #%d\nTesting for input: \"%s\" ...\n\n"

static void TestValueSum0(CuTest *tc);

static void TestValueSum1(CuTest *tc);

static void TestValueSum2(CuTest *tc);

static void TestValueSum3(CuTest *tc);

static void TestValueSum4(CuTest *tc);

static void TestValueSum5(CuTest *tc);

static void TestValueSum6(CuTest *tc);

static void TestValueSum7(CuTest *tc);

static void TestValueSum8(CuTest *tc);

static void TestValueSum9(CuTest *tc);

static void TestValueSum10(CuTest *tc);

static void TestValueSum11(CuTest *tc);

static void TestValueSum12(CuTest *tc);

static void TestValueSum13(CuTest *tc);

static void TestValueSum14(CuTest *tc);

static void TestValueSum15(CuTest *tc);

static void TestValueSum16(CuTest *tc);

static void TestValueSum17(CuTest *tc);

static void TestValueSum18(CuTest *tc);

static void TestValueSum19(CuTest *tc);

static void TestValueSum20(CuTest *tc);

static CuSuite *ValueSumSuiteNew(void);

static void RunAllTests(void);

int main(void)
{
    RunAllTests();

    (void)getchar();
    return 0;
}

static void TestValueSum0(CuTest *tc)
{
    const size_t      TEST_ID = 0;
    const char *const input   = "1";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 1;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum1(CuTest *tc)
{
    const size_t      TEST_ID = 1;
    const char *const input   = "Pompey1 Germanicus2Ca69esar";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 72;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum2(CuTest *tc)
{
    const size_t      TEST_ID = 2;
    const char *const input   = "H3ll0w0rlddd 1";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 4;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum3(CuTest *tc)
{
    const size_t      TEST_ID = 3;
    const char *const input   = "1 Claudius Germanicus 3Pompey";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 4;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum4(CuTest *tc)
{
    const size_t      TEST_ID = 4;
    const char *const input   = "  4v34m1cu8! ";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 47;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum5(CuTest *tc)
{
    const size_t      TEST_ID = 5;
    const char *const input   = "Th3 80ng 0f R0l4nd";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 87;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum6(CuTest *tc)
{
    const size_t      TEST_ID = 6;
    const char *const input   = "1+2+3+4+5+7";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 22;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum7(CuTest *tc)
{
    const size_t      TEST_ID = 7;
    const char *const input   = "";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 0;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum8(CuTest *tc)
{
    const size_t      TEST_ID = 8;
    const char *const input   = "1+2-3+4+5+7";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 16;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum9(CuTest *tc)
{
    const size_t      TEST_ID = 9;
    const char *const input   = "-42+42+1-13Germanicus1";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = -11;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum10(CuTest *tc)
{
    const size_t      TEST_ID = 10;
    const char *const input   = "Pompey the 1337";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 1337;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum11(CuTest *tc)
{
    const size_t      TEST_ID = 11;
    const char *const input   = "Dies Irae";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 0;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum12(CuTest *tc)
{
    const size_t      TEST_ID = 12;
    const char *const input   = "Qu1 d314t p4c3m, pr3p4ret b311um391.";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int         expected = 1031;
    const int         actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum13(CuTest *tc)
{
    const size_t      TEST_ID = 13;
    const char *const input   = "qu43 c4r3t 0r-4 cru03 n0str0?";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 49;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum14(CuTest *tc)
{
    const size_t      TEST_ID = 14;
    const char *const input   = 
        "more than 3000 m (9800 ft) thick scoured the landscape of Ireland";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 12800;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum15(CuTest *tc)
{
    const size_t      TEST_ID = 15;
    const char *const input   = "ca. 26000-19000 years ago";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 7000;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum16(CuTest *tc)
{
    const size_t      TEST_ID = 16;
    const char *const input   = 
        "During the period between 17500 and 12000 years ago";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 29500;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum17(CuTest *tc)
{
    const size_t      TEST_ID = 17;
    const char *const input   = "p-p5-6";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = -1;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum18(CuTest *tc)
{
    const size_t      TEST_ID = 18;
    const char *const input   = 
        "Sumer was first permanently settled between c. 5500 and 4000 BC.";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 9500;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum19(CuTest *tc)
{
    const size_t      TEST_ID = 19;
    const char *const input   = "00000";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 0;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static void TestValueSum20(CuTest *tc)
{
    const size_t      TEST_ID = 20;
    const char *const input   = "12.135";

    (void)printf(TEST_INTRO_MGS_FMT, TEST_ID, input);

    const int expected = 147;
    const int actual   = value_sum(input);

    CuAssertIntEquals(tc, expected, actual);
}

static CuSuite *ValueSumSuiteNew(void) 
{
    CuSuite *const suite = CuSuiteNew();

    assert(suite);

    SUITE_ADD_TEST(suite, TestValueSum0);
    SUITE_ADD_TEST(suite, TestValueSum1);
    SUITE_ADD_TEST(suite, TestValueSum2);
    SUITE_ADD_TEST(suite, TestValueSum3);
    SUITE_ADD_TEST(suite, TestValueSum4);
    SUITE_ADD_TEST(suite, TestValueSum5);
    SUITE_ADD_TEST(suite, TestValueSum6);
    SUITE_ADD_TEST(suite, TestValueSum7);
    SUITE_ADD_TEST(suite, TestValueSum8);
    SUITE_ADD_TEST(suite, TestValueSum9);
    SUITE_ADD_TEST(suite, TestValueSum10);
    SUITE_ADD_TEST(suite, TestValueSum11);
    SUITE_ADD_TEST(suite, TestValueSum12);
    SUITE_ADD_TEST(suite, TestValueSum13);
    SUITE_ADD_TEST(suite, TestValueSum14);
    SUITE_ADD_TEST(suite, TestValueSum15);
    SUITE_ADD_TEST(suite, TestValueSum16);
    SUITE_ADD_TEST(suite, TestValueSum17);
    SUITE_ADD_TEST(suite, TestValueSum18);
    SUITE_ADD_TEST(suite, TestValueSum19);
    SUITE_ADD_TEST(suite, TestValueSum20);

    return suite;
}

static void RunAllTests(void)
{
    CuString *summary = CuStringNew();
    CuSuite  *suite   = ValueSumSuiteNew();

    assert(summary);
    assert(suite);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, summary);
    CuSuiteDetails(suite, summary);

    (void)printf("%s\n", summary->buffer);

    CuStringDelete(summary);
    CuSuiteDelete(suite);
}

