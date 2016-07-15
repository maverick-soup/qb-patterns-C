#include "qb_object.h"

#include <stdio.h>

static void int_fake_method(struct qb_object *const self);

int main(int argc, char *argv[])
{
    qb_object_ptr test = qb_object_create();
    qb_object_ptr object = qb_object_create();

    (void) argc;
    (void) argv;

    test->method = object->method;
    object->method = int_fake_method;
    object->method(test);

    qb_object_destroy(&test);
    qb_object_destroy(&object);
    return 1;
}

static void int_fake_method(struct qb_object *const self)
{
    printf("Fake method\n");
    self->method(self);
}
