#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  *mre_alloc  (size_t size);
void   mre_free   (void* block);
size_t mre_strlen (const char *txt);

int main(void)
{
    const char   *PAYLOAD = "Hello world!";
    const size_t  PAYLOAD_SIZE = strlen(PAYLOAD);

    char         *message = (char*)mre_alloc((1 + PAYLOAD_SIZE) * sizeof(*PAYLOAD));
    const size_t *block   = (size_t*)message;

    if (!message) return 1;

    (void)strcpy(message, PAYLOAD);
    (void)puts(message);

    const size_t s_len = mre_strlen(message);

    (void)printf("Size: %zd\n", s_len);

    mre_free(message); message = NULL;

    (void)getchar();

    return 0;
}

void *mre_alloc(size_t size)
{
    static const size_t MAGIC = 0xc0ffee;

    const size_t real_size = (size + sizeof(size_t)
                              - ((size + sizeof(size_t)) % sizeof(size_t)));

    void *buffer = malloc(real_size + sizeof(size_t));

    if (buffer)
    {
        const size_t  magic_offset = real_size - sizeof(size_t);
        size_t *const buffer_end   = (size_t*)((char*)buffer + magic_offset);

        *buffer_end = MAGIC;
    }

    return buffer;
}

void mre_free(void* block)
{
    if (block) free(block);
}

size_t mre_strlen(const char *txt)
{
    if (!txt) return 0;

    const size_t *guide = (size_t*)txt;
    size_t        count = 0;

    while (txt[count]) {
        if (count % sizeof(size_t)) {
            if (*guide == 0xc0ffee) return (size_t)-1;
            else ++guide;
        }
        ++count;
    }

    return count;
}

