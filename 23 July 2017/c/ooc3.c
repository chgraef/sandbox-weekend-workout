#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

// version three: single inheritance, virtual methods table
// - one base class: Roman
// - multiple derived classes: Emperor, Soldier
// - multiple instances: Augustus, Brutus, Claudius, Soldier123, Soldier4711;
// - virtual table pointer

struct Roman_vtable;
struct Roman
{
    struct Roman_vtable *vptr;
};

struct Roman_vtable
{
    void (*greet)(struct Roman *);
    void (*deinit)(struct Roman *);
};

struct Emperor
{
    struct Roman base;
    const char *name;
};

struct Soldier
{
    struct Roman base;
    int number;
};

void roman_greet(struct Roman *roman);
void roman_deinit(struct Roman *);
void roman_free(struct Roman *);

struct Emperor * emperor_alloc(const char *);
void emperor_init(struct Emperor*, const char *);
static void emperor_greet(struct Emperor*);

struct Roman_vtable Emperor_vtable_instance = {
    .greet = (void (*)(struct Roman *)) emperor_greet,
    .deinit = NULL
};

struct Soldier * soldier_alloc(int);
void soldier_init(struct Soldier*, int);
static void soldier_greet(struct Soldier*);

struct Roman_vtable Soldier_vtable_instance = {
    .greet = (void (*)(struct Roman *)) soldier_greet,
    .deinit = NULL
};

struct Roman   *get_random_roman();
struct Emperor *get_random_emperor();
struct Soldier *get_random_soldier();

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

void roman_greet(struct Roman *self)
{
    assert(self && self->vptr);
    self->vptr->greet(self);
}

void roman_deinit(struct Roman *self)
{
    assert(self && self->vptr);
    if (self->vptr->deinit)
        self->vptr->deinit(self);
}

void roman_free(struct Roman *self)
{
    if (self)
        roman_deinit(self);
    free(self);
}

struct Emperor * emperor_alloc(const char *name)
{
    struct Emperor *result = (struct Emperor *) malloc(sizeof(struct Emperor));
    if (result)
        emperor_init(result, name);
    return result;
}

void emperor_init(struct Emperor *self, const char *name)
{
    assert(self);
    self->base.vptr = &Emperor_vtable_instance;
    self->name = name;
}

static void emperor_greet(struct Emperor *self)
{
    assert(self);
    printf("%s says: Ave\n", self->name);
}

struct Soldier * soldier_alloc(int number)
{
    struct Soldier *result = (struct Soldier *) malloc(sizeof(struct Soldier));
    if (result)
        soldier_init(result, number);
    return result;
}

void soldier_init(struct Soldier *self, int number)
{
    assert(self);
    self->base.vptr = &Soldier_vtable_instance;
    self->number = number;
}

static void soldier_greet(struct Soldier *soldier)
{
    assert(soldier);
    printf("Soldier #%d says: Ave\n", soldier->number);
}

struct Roman *get_random_roman()
{
    return (rand() % 2 == 0)?
        (struct Roman *) get_random_emperor() :
        (struct Roman *) get_random_soldier();
}

struct Emperor *get_random_emperor()
{
    const char *names[] = {"Augustus", "Tiberius", "Caligula", "Claudius", "Nero"};
    int choice = rand() % (sizeof(names) / sizeof(names[0]));
    return emperor_alloc(names[choice]);
}

struct Soldier *get_random_soldier()
{
    return soldier_alloc(rand());
}

// vim:set sw=4 et:
