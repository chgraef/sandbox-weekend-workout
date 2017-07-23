#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

// version one:
// - One Class: Roman
// - multiple instances: Augustus, Brutus, Claudius
// - methods as instance variables

typedef void (*Action)();

struct Roman
{
    void (*greet)();
    void (*deinit)(struct Roman *);
};

struct Roman *roman_alloc(void (*initializer)(struct Roman *));
void roman_greet(struct Roman *roman);
void roman_free(struct Roman *);

static void augustus_init    (struct Roman*);
static void augustus_greet ();

static void brutus_init    (struct Roman*);
static void brutus_greet ();

static void claudius_init    (struct Roman*);
static void claudius_greet ();

struct Roman *get_random_roman();

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        struct Roman *roman = get_random_roman();
        if (roman)
        {
            roman_greet(roman);
            roman_free(roman);
        }
    }
    return EXIT_SUCCESS;
}

struct Roman *roman_alloc(void (*initializer)(struct Roman *))
{
    struct Roman *result = (struct Roman *) malloc(sizeof(struct Roman));
    if (result)
        (*initializer)(result);
    return result;
}

void roman_greet(struct Roman *roman)
{
    assert(roman);
    roman->greet();
}

void roman_free(struct Roman *roman)
{
    assert(roman);
    if (roman->deinit)
        roman->deinit(roman);
    free(roman);
}

void augustus_init(struct Roman *self)
{
    assert(self);
    self->greet = &augustus_greet;
    self->deinit = NULL;
}

void brutus_init(struct Roman *self)
{
    assert(self);
    self->greet = &brutus_greet;
    self->deinit = NULL;
}

void claudius_init(struct Roman *self)
{
    assert(self);
    self->greet = &claudius_greet;
    self->deinit = NULL;
}

static void augustus_greet()
{
    puts("Hi");
}

static void brutus_greet()
{
    puts("Bonjour");
}

static void claudius_greet()
{
    puts("Hallo");
}

struct Roman *get_random_roman()
{
    typedef void (*initializer)(struct Roman *);
    static initializer initializers[] = {
        augustus_init,
        brutus_init,
        claudius_init
    };
    int choice = rand() % (sizeof(initializers) / sizeof(initializers[0]));
    return roman_alloc(initializers[choice]);
}

// vim:set sw=4 et:
