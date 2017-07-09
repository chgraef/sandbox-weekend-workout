#include <stdio.h>
#include <stdlib.h>

#define Handlee(handle, type) ((type*)(*handle))

typedef struct Object {
    unsigned int _id;
} Object;

typedef void **Handle;

Object *ObjectNew      (unsigned int id);
void    ObjectDelete   (Object *self);

Handle *HandleNew      (void *handlee);
void    HandleDelete   (Handle* handle, void(*freeHandlee)(void*));
Handle *ReallocHandlee (Handle *handle, size_t newSize);

int main(void)
{
    const unsigned objId     = 3741;
    Handle        *objHandle = HandleNew(ObjectNew(objId));

    (void)printf("%u\n", Handlee(objHandle, Object)->_id);

    /* Force handlee reallocation by doubling its original size. */
    (void)ReallocHandlee(objHandle, 2 * sizeof(Handlee(objHandle, Object)));

    (void)printf("%u\n", Handlee(objHandle, Object)->_id);

    HandleDelete(objHandle, ObjectDelete); objHandle = NULL;

    (void)getchar();
    return EXIT_SUCCESS;
}

Object *ObjectNew(unsigned int id)
{
    Object *obj = (Object*)calloc(1, sizeof(*obj));

    if (obj) {
        obj->_id = id;
    }

    return obj;
}

void ObjectDelete(Object *self)
{
    if (self) free(self);
}

Handle *HandleNew(void *handlee)
{
    if (!handlee) return NULL;

    Handle *handle = (Handle*)calloc(1, sizeof(*handle));

    if (handle) *handle = handlee;

    return handle;
}

void HandleDelete(Handle* handle, void(*freeHandlee)(void*))
{
    if (!handle) return;

    void *handlee = *handle;

    free(handle); handle = NULL;

    if (freeHandlee) {
        (*freeHandlee)(handlee);
        handlee = NULL;
    }
}

Handle *ReallocHandlee(Handle* handle, size_t newSize)
{
    if (!handle) return NULL;
    
    void *const handlee    = *handle;
    void *const newHandlee = realloc(handlee, newSize);
    
    if (!newHandlee) return NULL;

    *handle = newHandlee;

    return handle;
}

