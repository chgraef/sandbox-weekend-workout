#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int match(const char *pattern, const char *filename);

int match_solution(const char *pattern, const char *filename);

void help(void);

struct TestPair {
    const char *expected;
    const char *actual;
};

struct StringPair {
    char *key;
    char *value;
};

static const char *generate_extension(void)
{
    static const char *EXTENSIONS[] = {
        ".jpeg", ".gif", ".png", ".elf",
         ".pdf",   ".c",   ".h",  ".py",
          ".rb",     "",
    };

    const size_t count = sizeof(EXTENSIONS) / sizeof(EXTENSIONS[0]);
    const size_t index = rand() % count;

    return EXTENSIONS[index];
}

char get_random_char(void)
{
    static const char *kPool = ".ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const size_t kPoolSize = strlen(kPool);

    const size_t rand_index = rand() % kPoolSize;
    const char   rand_char  = kPool[rand_index];

    return rand_char;
}

char *generate_char_class(void)
{
    const size_t kBufferSize = 11;
    char        *buffer = (char*)calloc(kBufferSize, sizeof(*buffer));

    if (!buffer) return NULL;

    const size_t kMinSize = 3;
    const size_t kMaxSize = kBufferSize;

    const size_t count = 1 + kMinSize + rand() % (kMaxSize - kMinSize);

    char lookup[UCHAR_MAX] = { 0 };

    for (size_t index = 0; index < count; ++index)
    {
        while (1)
        {
            const char rand_char = get_random_char();

            if (lookup[rand_char] > 0) continue;

            lookup[rand_char] |= 1;
            buffer[index] = rand_char;

            break;
        }
    }

    buffer[0] = '[';
    buffer[count - 2] = ']';
    buffer[count - 1] = '\0';

    return buffer;
}

static struct StringPair generate_pattern(int is_matching)
{
    const size_t      kBufferSize = 32;
    const size_t      kSampleBase = 3;

    const size_t      kMinSize = 1;
    const size_t      kMaxSize = kBufferSize;

    const size_t      kCount = 1 + kMinSize + rand() % (kMaxSize - kMinSize);

    const char *const kExtension = generate_extension();

    char *pattern = (char*)calloc(1 + kCount + strlen(kExtension), sizeof(*pattern));
    char *source  = (char*)calloc(1 + kCount + strlen(kExtension), sizeof(*pattern));

    if (!pattern) return (struct StringPair) { .key = NULL, .value = NULL };
    if (!source)  return (struct StringPair) { .key = NULL, .value = NULL };

    size_t pattern_index = 0;
    size_t source_index = 0;

    while (pattern_index < kCount)
    {
        const int is_pattern = rand() % kSampleBase;
        char *char_class = generate_char_class();

        const size_t char_class_count = strlen(char_class);
        const size_t remaining_count  = kCount - pattern_index;

        if (is_pattern && char_class_count > 2 && char_class_count <= remaining_count)
        {
            (void)strcpy(&pattern[pattern_index], char_class);

            if (is_matching)
            {
                const size_t rand_index = 1 + rand() % (char_class_count - 2);
                const char   rand_char  = char_class[rand_index];

                source[source_index] = rand_char;
            } else {
                const char rand_char = get_random_char();

                source[source_index] = rand_char;
            }

            pattern_index += char_class_count; ++source_index;
        } else {
            if (is_matching)
            {
                const char rand_char = get_random_char();

                pattern[pattern_index] = rand_char;
                source[source_index]   = rand_char;
            } else {
                while (1)
                {
                    const char pattern_rand_char = get_random_char();
                    const char source_rand_char = get_random_char();

                    if (source_rand_char == pattern_rand_char) continue;

                    pattern[pattern_index] = pattern_rand_char;
                    source[source_index]   = source_rand_char;

                    break;
                }
            }

            ++pattern_index; ++source_index;
        }

        free(char_class); char_class = NULL;
    }

    (void)strcpy(&pattern[pattern_index], kExtension);
    (void)strcpy(&source[source_index], kExtension);

    return (struct StringPair) { .key = pattern, .value = source };
}

const struct StringPair generate_matching_pattern(void)
{
    return generate_pattern(1);
}

const struct StringPair generate_mismatching_pattern(void)
{
    return generate_pattern(0);
}

int main(void)
{
    srand((unsigned)time(NULL));

    const size_t kCount = 255;

    for (size_t times = 0; times < kCount; ++times)
    {
        struct StringPair pattern_filename_pair = generate_mismatching_pattern();

        char *pattern  = pattern_filename_pair.key;
        char *filename = pattern_filename_pair.value;

        (void)printf("Pattern: \"%s\"\nFilename: \"%s\"\n\n", pattern, filename);

        free(pattern);  pattern = NULL;
        free(filename); filename = NULL;
    }

    (void)getchar();

    return EXIT_SUCCESS;
}

void help(void)
{
    {
        struct TestPair PAIRS[] = {
            { "hello",  "hello"  },
            { "hi",     "hi"     },
            { "wizard", "wizard" },
            { "dennis", "dennis" },
            { "bash",   "bash"   },
        };

        for (size_t index = 0; index < sizeof(PAIRS)/sizeof(PAIRS[0]); ++index) \
        {
            const struct TestPair *const pair = &PAIRS[index];

            if (strcmp(pair->expected, pair->actual) != match_solution(pair->expected, pair->actual)) {
                (void)puts("It looks like your solution does not handle basic string comparison correctly. :(");
                break;
            }
        }
    }

    {
        struct TestPair PAIRS[] = {
            { "h3llo",  "hello"  },
            { "hi",     "h1"     },
            { "wiz4rd", "wizard" },
            { "d3nn1s", "dennis" },
            { "b2sh",   "bash"   },
        };

        for (size_t index = 0; index < sizeof(PAIRS)/ sizeof(PAIRS[0]); ++index) \
        {
            const struct TestPair *const pair = &PAIRS[index];

            if (strcmp(pair->expected, pair->actual) != match_solution(pair->expected, pair->actual)) {
                (void)puts("It looks like your solution does not handle basic string comparison correctly. :(");
                break;
            }
        }
    }

    {
        struct TestPair PAIRS[] = {
            { "hello",  "hllo"  },
            { "hi",     "h"     },
            { "wizard", "wzard" },
            { "dennis", "dnnis" },
            { "bash",   "bsh"   },
        };

        for (size_t index = 0; index < sizeof(PAIRS)/sizeof(PAIRS[0]); ++index) \
        {
            const struct TestPair *const pair = &PAIRS[index];

            if (strcmp(pair->expected, pair->actual) != match_solution(pair->expected, pair->actual)) {
                (void)puts("It looks like your solution does not handle basic string comparison correctly. :(");
                break;
            }
        }
    }

    {
        struct TestPair PAIRS[] = {
            { "hllo",  "hello"  },
            { "h",     "hi"     },
            { "wzard", "wizard" },
            { "dnnis", "dennis" },
            { "bsh",   "bash"   },
        };

        for (size_t index = 0; index < sizeof(PAIRS)/sizeof(PAIRS[0]); ++index) \
        {
            const struct TestPair *const pair = &PAIRS[index];

            if (strcmp(pair->expected, pair->actual) != match_solution(pair->expected, pair->actual)) {
                (void)puts("It looks like your solution does not handle basic string comparison correctly. :(");
                break;
            }
        }
    }
}

int match(const char *pattern, const char *filename)
{
    if (!pattern)  return 0;
    if (!filename) return 0;

    const char *curchr = filename;
    const char *patchr = pattern;

    while (*curchr && *patchr)
    {
        if (*patchr == '[') {
            int is_match = 0;

            ++patchr;

            while (*patchr && *patchr != ']') {
                if (*curchr == *patchr) is_match = 1;
                ++patchr;
            }

            if (*patchr)   ++patchr;
            if (!is_match) return 0;

            ++curchr;
        } else if (*curchr != *patchr) {
            return 0;
        } else {
            ++curchr, ++patchr;
        }
    }

    return !*curchr && !*patchr;
}

int match_solution(const char *pattern, const char *filename)
{
    if (!pattern)  return 0;
    if (!filename) return 0;

    const char *curchr = filename;
    const char *patchr = pattern;

    while (*curchr && *patchr)
    {
        if (*patchr == '[') {
            int is_match = 0;

            ++patchr;

            while (*patchr && *patchr != ']') {
                if (*curchr == *patchr) is_match = 1;
                ++patchr;
            }

            if (*patchr)   ++patchr;
            if (!is_match) return 0;

            ++curchr;
        } else if (*curchr != *patchr) {
            return 0;
        } else {
            ++curchr, ++patchr;
        }
    }

    return !*curchr && !*patchr;
}
