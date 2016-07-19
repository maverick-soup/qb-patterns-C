#include "qb_object_interface.h"
#include "qb_object_foo.h"
#include "qb_object_bar.h"

#include "../utils/logger/qb_logger.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    qb_object_ptr foo = qb_object_foo_create();
    qb_object_ptr bar = qb_object_bar_create();
    
    (void) argc;
    (void) argv;

    QB_LOG("test %d", 102);

    foo->method(foo);
    qb_object_foo_destroy(&foo);

    bar->method(bar);
    qb_object_bar_destroy(&bar);

    return 0;
}
