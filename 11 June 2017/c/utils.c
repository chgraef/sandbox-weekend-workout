#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

char		*c_ary_to_s(const char **c_ary);
static int	 is_toss_coin_result_heads(void);
static int	 randrange(const int min, const int max_exclusive);
static char     *generate_string(void);
char		*generate_pattern(void);
char		*generate_filename(void);
char	       **generate_filenames(void);
const char	*generate_extension(void);

void display_help(const char *pattern, const char *actual)
{
    if (!pattern) return;
    if (!actual)  return;

    const char *patcurchar = pattern;
    const char *actcurchar = actual;
    const size_t patlen = strlen(pattern);
    const size_t actlen = strlen(actual);
    int mismatch_count = 0;

    (void)puts(actual);

    while (*patcurchar || *actcurchar)
    {
        if ((*patcurchar && *actcurchar) && (*patcurchar == *actcurchar || *patcurchar == '?'))
        {
            (void)putchar(' ');
        }
        else {
            const size_t patoffset = patcurchar - pattern;
            const size_t actoffset = actcurchar - actual;

            if (!*actcurchar && patoffset >= actoffset) {
                (void)putchar('-');
            }
            else if (!*patcurchar && patoffset <= actoffset) {
                (void)putchar('+');
            }
            else {
                (void)putchar('^');

                ++mismatch_count;
            }
        }

        if (*patcurchar) ++patcurchar;
        if (*actcurchar) ++actcurchar;
    }

    (void)putchar('\n');
    (void)puts(pattern);
    (void)putchar('\n');

    if (patlen != actlen) {
        (void)printf("- The pattern and the matched filename must have the same character count regardless \n"
            "of the number of the '?' wildcard characters. ");

        if (patlen > actlen) {
            (void)printf("But here, the pattern is longer than \nthe match. Please make sure you do not terminate "
                "the character comparison loop \nprematurely.");
        }
        else {
            (void)printf("But here, the match is longer than the \npattern. Please make sure you terminate the "
                "character comparison loop once the \npattern ends.");
        }

        (void)putchar('\n');
    }

    if (mismatch_count > 0) {
        (void)printf("- Please make sure your solution is comparing characters correctly. %s mismatch%s.\n",
            mismatch_count == 1 ? "One" : "Multiple", mismatch_count == 1 ? "" : "es");
    }

    if (mismatch_count == 0 && patlen == actlen) {
        (void)puts("Good match. Good job!");
    }
}

int main(void)
{
    display_help("n?pla?", "nupla2");

    (void)getchar();

    return EXIT_SUCCESS;
}

char *c_ary_to_s(const char **c_ary)
{
    if (!c_ary) return NULL;

    static const char *const LEFT_BRACE  = "{";
    static const char *const RIGHT_BRACE = " }";
    static const char *const SEPARATOR   = " ";

    size_t total_count = strlen(LEFT_BRACE) + strlen(RIGHT_BRACE);

    for (const char **p_cur_item = c_ary; *p_cur_item; ++p_cur_item) {
        total_count += strlen(*p_cur_item) + strlen(SEPARATOR);
    }

    char *buffer = (char*)calloc(1 + total_count, sizeof(*buffer));

    if (buffer)
    {
        char *dest = buffer;

        for (const char *curchar = LEFT_BRACE; *curchar; ++curchar) {
            *dest++ = *curchar;
        }

        for (const char **p_cur_item = c_ary; *p_cur_item; ++p_cur_item)
        {
            for (const char *curchar = SEPARATOR; *curchar; ++curchar) {
                *dest++ = *curchar;
            }

            for (const char *curchar = *p_cur_item; *curchar; ++curchar) {
                *dest++ = *curchar;
            }
        }

        for (const char *curchar = RIGHT_BRACE; *curchar; ++curchar) {
            *dest++ = *curchar;
        }
    }

    return buffer;
}

static int is_toss_coin_result_heads(void)
{
    return rand() % 2;
}

static int randrange(const int min, const int max_exclusive)
{
    if (min >= max_exclusive) return -1;

    return min + (rand() % (max_exclusive - min));
}

static char *generate_string(void)
{
    static const int  MIN_COUNT = 1;
    static const int  MAX_COUNT = 15;
    static const char BASE_CHARS[] = ("abcdefghijklmnopqrstuvwxyz"
                                      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                      "123456789_-.");

    srand((unsigned)time(NULL));

    const int count = randrange(MIN_COUNT, MAX_COUNT + 1);
    char *buffer = (char*)calloc(1 + count, sizeof(*buffer));

    if (buffer)
    {
        for (int index = 0; index < count; ++index) {
            buffer[index] = BASE_CHARS[randrange(0, 1 + (int)(sizeof(BASE_CHARS) / sizeof(BASE_CHARS[0])))];
        }
    }

    return buffer;
}

char *generate_pattern(void)
{
    char *pattern = generate_string();

    if (pattern)
    {
        for (char *curchar = pattern; *curchar; ++curchar) {
            if (is_toss_coin_result_heads()) {
                *curchar = '?';
            }
        }
    }

    return pattern;
}

char *generate_filename(void)
{
    char *filename = generate_string();

    if (filename)
    {
        const char *const extension   = generate_extension();

        const size_t filename_length  = strlen(filename);
        const size_t extension_length = strlen(extension);

        if (extension_length < filename_length)
        {
            const size_t offset = filename_length - extension_length;

            (void)strcpy(&filename[offset], extension);
        }

        return filename;
    }

    return NULL;
}

char **generate_filenames(void)
{
    static const int MIN_COUNT = 1;
    static const int MAX_COUNT = 32;

    srand((unsigned)time(NULL));

    const int count = randrange(MIN_COUNT, MAX_COUNT + 1);
    char **filenames = (char**)calloc(1 + count, sizeof(*filenames));

    if (filenames)
    {
        for (int index = 0; index < count; ++index) {
            filenames[index] = generate_filename();
        }
    }

    return filenames;
}

const char *generate_extension(void)
{
    static const char *EXTENSIONS[] = {
        ".jpg", ".jpeg", ".png", ".elf", ".ods",
        ".sh",  ".txt", ".py",   ".rb",  ".c",
        ".cpp"
    };

    return EXTENSIONS[randrange(0, 1 + (int)(sizeof(EXTENSIONS) / sizeof(EXTENSIONS[0])))];
}
