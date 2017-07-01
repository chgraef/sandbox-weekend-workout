#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

static unsigned long long get_flag_opcode(const char *flag);

static int get_real_count(int curcnt, int maxcnt);

static void count_nl(const char *s, int *out_nl_count, int *out_chr_count);

char *head(int argc, const char *const *argv);

int main(void)
{
    const char *const flag = "-n0";
    const char *const text = "One\nTwo\nThree\n";

    const int   argc = 2;
    const char *argv[] = {
        [0] = flag,
        [1] = text
    };

    char *result = head(argc, argv);

    if (!result) return EXIT_FAILURE;

    (void)puts(result);

    free(result); result = NULL;

    (void)puts("Success...");
    (void)getchar();

    return EXIT_SUCCESS;
}

char *head(int argc, const char *const *argv)
{
    if (argc != 2) return NULL;
    if (!argv)     return NULL;

    const char *const flag = argv[0];
    const char *const text = argv[1];

    if (!flag) return NULL;
    if (!text) return NULL;

    const unsigned long long flag_opcode = get_flag_opcode(flag);

    if (flag_opcode)
    {
        const int value = flag_opcode >> 32ull;
        int real_value  = 0;
        int chr_count   = 0;

        if (flag_opcode & 1) {
            /* -n flag */

            int nl_count = 0;
            count_nl(text, &nl_count, &chr_count);

            real_value = get_real_count(value, nl_count);

        } else if (flag_opcode & 2) {
            /* -c flag */

            chr_count  = strlen(text);
            real_value = get_real_count(value, chr_count);

        }

        char *buffer = (char*)calloc(1 + chr_count, sizeof(*buffer));

        if (buffer)
        {
            if (flag_opcode & 1)
            {
                int nl_index  = 0;
                int chr_index = 0;

                while (nl_index < real_value)
                {
                    if (text[chr_index] == '\n') ++nl_index;

                    buffer[chr_index] = text[chr_index];
                    ++chr_index;
                }

            } else if (flag_opcode & 2) {
                for (int chr_index = 0; chr_index < real_value; ++chr_index) {
                    buffer[chr_index] = text[chr_index];
                }
            }

            return buffer;
        }
    }

    return NULL;
}

static unsigned long long get_flag_opcode(const char *flag)
{
    const char         *curchr = flag;
    unsigned long long  opcode = 0;

    if (!flag) return 0;

    if      (!strncmp(curchr, "-n", 2)) opcode |= 1;
    else if (!strncmp(curchr, "-c", 2)) opcode |= 2;
    else return 0;

    curchr += 2;
    while (isspace(*curchr)) ++curchr;

    const int value = (int)strtol(curchr, NULL, 10);
    if (errno == ERANGE) return 0;

    opcode |= ((unsigned long long)value << 32);

    return opcode;
}

static int get_real_count(int curcnt, int maxcnt)
{
    if (curcnt > 0) {
        return (curcnt < maxcnt) ? curcnt : maxcnt;
    } else if (curcnt < 0) {
        return (abs(curcnt) < maxcnt) ? maxcnt - abs(curcnt) : maxcnt;
    }

    return 0;
}

static void count_nl(const char *s, int *out_nl_count, int *out_chr_count)
{
    if (!s)             return;
    if (!out_nl_count)  return;
    if (!out_chr_count) return;

    for (const char *c = s; *c; ++c)
    {
        if (*c == '\n') ++*out_nl_count;
        ++*out_chr_count;
    }
}

