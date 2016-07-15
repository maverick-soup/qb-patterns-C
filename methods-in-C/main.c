#include "qb_object.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    qb_object_ptr object = qb_object_create();

    (void) argc;
    (void) argv;

    object->method(object);
    qb_object_destroy(&object);
    return 1;
}
