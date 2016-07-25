#include "qb_object_interface.h"
#include "qb_object_foo.h"
#include "qb_object_bar.h"

#include "../utils/logger/qb_logger.h"

#include <stdio.h>

typedef void (*iterator_strategy)(qb_object_ptr *iter);

static void int_iterate(qb_object_ptr *const begin,
			qb_object_ptr *const end,
			iterator_strategy const strategy);

static void int_method_strategy(qb_object_ptr *iter);
static void int_destroy_strategy(qb_object_ptr *iter);

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    qb_object_ptr container[] = {qb_object_foo_create(), qb_object_bar_create()};
    qb_object_ptr *begin = container;
    qb_object_ptr *end = begin + (sizeof container / sizeof *container);

    int_iterate(begin, end, int_method_strategy);
    int_iterate(begin, end, int_destroy_strategy);

    return 0;
}

static void int_iterate(qb_object_ptr *const begin,
			qb_object_ptr *const end,
			iterator_strategy const strategy)
{
    for (qb_object_ptr *iter = begin; iter != end; ++iter)
    {
        if (NULL != *iter && NULL != (*iter)->destroy)
        {
	    strategy(iter);
        }
    }
}

static void int_method_strategy(qb_object_ptr *iter)
{
    (*iter)->method(*iter);
}

static void int_destroy_strategy(qb_object_ptr *iter)
{
    (*iter)->destroy(iter);
}
