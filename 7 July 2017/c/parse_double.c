#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

double ParseDouble(const char *str/*, char **endPtr*/);

static char RetrieveCurrentDecimalPoint(void);

static int IsDecimalPoint(int);

static int IsPosSignPrefix(int);

static int IsNegSignPrefix(int);

static int IsSignPrefix(int);

static int IsScientificNotationSuffix(int);

static int ParseDigit(int);

int main(void)
{
    const char *const valueStr  = "10e+3";
    const double value          = ParseDouble(valueStr);

    (void)printf("%lf\n", value);
    (void)printf("%lf\n", 10e+3);     

    (void)getchar();
    return EXIT_SUCCESS;
}

static char RetrieveCurrentDecimalPoint(void)
{
    const struct lconv *const loc = localeconv();

    if (loc && loc->decimal_point && *loc->decimal_point) {
        return *loc->decimal_point;
    }

    return '.';
}

static int IsDecimalPoint(int sym)
{
    return (sym == (int)RetrieveCurrentDecimalPoint());
}

static int IsPosSignPrefix(int sym)
{
    return sym == '+';
}

static int IsNegSignPrefix(int sym)
{
    return sym == '-';
}

static int IsScientificNotationSuffix(int sym)
{
    return sym == 'e' || sym == 'E';
}

static int IsSignPrefix(int sym)
{
    return IsPosSignPrefix(sym) || IsNegSignPrefix(sym);
}

static int ParseDigit(int sym)
{
    return sym - '0';
}

double ParseDouble(const char *str/*, char **endPtr*/)
{
    if (!str) return 0.0;

    const char *pchar = str;
    while (isspace(*pchar)) ++pchar;

    const int isNeg = IsNegSignPrefix(*pchar);
    if (IsSignPrefix(*pchar)) ++pchar;

    double value = 0.0;

    while (isdigit(*pchar))
    {
        const int digit = ParseDigit(*pchar);
        value = 10.0 * value + digit;

        ++pchar;
    }

    if (IsDecimalPoint(*pchar)) {
        ++pchar;

        double mul = 10.0;

        while (isdigit(*pchar)) 
        {
            const int digit = ParseDigit(*pchar);
            
            value += digit / mul; 
            mul   *= 10.0;

            ++pchar;
        }
    } else if (IsScientificNotationSuffix(*pchar)) {
        ++pchar;

        const int isExpNeg = IsNegSignPrefix(*pchar);
        if (IsSignPrefix(*pchar)) ++pchar;

        int exp = 0;

        while (isdigit(*pchar)) 
        {
            const int digit = ParseDigit(*pchar);
            exp = 10 * exp + digit;

            ++pchar;
        }

        double mul = 1.0;

        for (int times = 0; times < exp; ++times) {
            mul *= 10.0;
        }

        if (isExpNeg) value = value / mul;
        else          value = value * mul;
    }

    return isNeg? -value : value;
}

