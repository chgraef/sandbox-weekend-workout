#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

// version two: single inheritance, method pointes in the instances
// - one base class: Roman
// - multiple derived classes: Emperor, Soldier
// - multiple instances: Augustus, Brutus, Claudius, Soldier123, Soldier4711;

struct Roman
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

struct Soldier * soldier_alloc(int);
void soldier_init(struct Soldier*, int);
static void soldier_greet(struct Soldier*);

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

void roman_greet(struct Roman *self)
{
    assert(self);
    self->greet(self);
}

void roman_deinit(struct Roman *self)
{
    assert(self);
    if (self->deinit)
        self->deinit(self);
}

void roman_free(struct Roman *self)
{
    if (self)
        roman_deinit(self);
    free(self);
}

struct Emperor * emperor_alloc(const char *name)
{
    struct Emperor *self = (struct Emperor *) malloc(sizeof(struct Emperor));
    if (self)
        emperor_init(self, name);
    return self;
}

void emperor_init(struct Emperor *self, const char *name)
{
    assert(self);
    self->base.greet = (void (*)(struct Roman *)) &emperor_greet;
    self->base.deinit = NULL;
    self->name = name;
}

static void emperor_greet(struct Emperor *self)
{
    assert(self);
    printf("Emperor %s says: Ave\n", self->name);
}

struct Soldier * soldier_alloc(int number)
{
    struct Soldier *self = (struct Soldier *) malloc(sizeof(struct Soldier));
    if (self)
        soldier_init(self, number);
    return self;
}

void soldier_init(struct Soldier *self, int number)
{
    assert(self);
    self->base.greet = (void (*)(struct Roman *)) &soldier_greet;
    self->base.deinit = NULL;
    self->number = number;
}

static void soldier_greet(struct Soldier *self)
{
    assert(self);
    printf("Soldier #%d says: Ave\n", self->number);
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
