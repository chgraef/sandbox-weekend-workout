#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef void (*Action)(void);

struct Augustus {
    Action say_hi;
};

struct Brutus {
    Action say_bonjour;
};

struct Claudius {
    Action say_hallo;
};

struct Augustus *augustus_init  (struct Augustus*);
struct Brutus	*brutus_init    (struct Brutus*);
struct Claudius *claudius_init  (struct Claudius*);

void augustus_dispose (struct Augustus*);
void brutus_dispose   (struct Brutus*);
void claudius_dispose (struct Claudius*);

static void say_hi      (void);
static void say_bonjour (void);
static void say_hallo   (void);

void *brave_romans_new	  (size_t *out_count);
void  brave_romans_delete (void**, size_t);
void  brave_romans_talk	  (const void**, size_t);

int main(void)
{
    size_t romans_count = 0;
    void **brave_romans = brave_romans_new(&romans_count);

    if (brave_romans)
    {
        brave_romans_talk(brave_romans, romans_count);

        (void)printf("%p\n", ((struct Augustus*)brave_romans[0]));
        (void)printf("%p\n", ((struct Augustus*)brave_romans[0]));

        brave_romans_delete(brave_romans, romans_count); 
        brave_romans = NULL;
    }

    (void)puts("Success...");

    (void)getchar();
    return EXIT_SUCCESS;
}

struct Augustus *augustus_init(struct Augustus *self)
{
    assert(self);

    self->say_hi = &say_hi;
    return self;
}

struct Brutus *brutus_init(struct Brutus *self)
{
    assert(self);

    self->say_bonjour = &say_bonjour;
    return self;
}

struct Claudius *claudius_init(struct Claudius *self)
{
    assert(self);

    self->say_hallo = &say_hallo;
    return self;
}

void augustus_dispose(struct Augustus *self)
{
    /* Not much to do here... */
}

void brutus_dispose(struct Brutus *self)
{
    /* Not much to do here... */
}

void claudius_dispose(struct Claudius *self)
{
    /* Not much to do here... */
}

static void say_hi(void)
{
    (void)puts("Hi");
}

static void say_bonjour(void)
{
    (void)puts("Bonjour");
}

static void say_hallo(void)
{
    (void)puts("Hallo");
}

void *brave_romans_new(size_t *out_count)
{
    assert(out_count);

    const size_t SizeLookupTable[] = {
        sizeof(struct Augustus),
        sizeof(struct Brutus),
        sizeof(struct Claudius)
    };

    const void*(*CtorLookupTable[])(void*) = {
        (void*(*)(void*))(&augustus_init),
        (void*(*)(void*))(&brutus_init),
        (void*(*)(void*))(&claudius_init)
    };

    assert(sizeof(SizeLookupTable)/sizeof(SizeLookupTable[0]) 
            == sizeof(CtorLookupTable)/sizeof(CtorLookupTable[0]));

    const size_t roman_count = sizeof(SizeLookupTable)/sizeof(SizeLookupTable[0]);

    void **buffer = malloc(sizeof(*buffer) * roman_count);

    for (size_t index = 0; index < roman_count; ++index) 
    {
        const size_t required_size = SizeLookupTable[index];
        const void*(*ctor)(void*)  = CtorLookupTable[index];

        void *const block = malloc(sizeof(char) * required_size);
        assert(block);

        buffer[index] = block;
        (void)(*ctor)(buffer[index]);
    }

    *out_count = roman_count;

    return buffer;
}

void brave_romans_delete(void **brave_romans, size_t count)
{
    assert(brave_romans);

    for (size_t index = 0; index < count; ++index) 
    {
        void *brave_roman = brave_romans[index];

        free(brave_roman); brave_roman = NULL;
        brave_romans[index] = NULL;
    }

    free(brave_romans); brave_romans = NULL;
}

void brave_romans_talk(const void *const *brave_romans, size_t count)
{
    assert(brave_romans);

    for (size_t index = 0; index < count; ++index) 
    {
        const void *const brave_roman = brave_romans[0];
        (*(Action*)(brave_roman))();
    }
}
