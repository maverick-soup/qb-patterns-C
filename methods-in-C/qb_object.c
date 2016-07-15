#include "qb_object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/

/* Data types----------------------------------------------------------------*/

struct
{
    int size;
} qb_object_impl_s;

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

static void int_method(qb_object_ptr self);

/* Functions definitions-----------------------------------------------------*/

qb_object_ptr qb_object_create(void)
{
    struct qb_object *temp = (struct qb_object *) malloc(sizeof *temp);
    if (NULL == temp)
    {
        printf("NULL pointer\n");
        return temp;
    }

    temp->method = int_method;
    temp->object = NULL;
    return temp;
}

static void int_method(qb_object_ptr self)
{
    if (NULL == self->object)
    {
        printf("NULL pointer\n");
        return;
    }
}

void qb_object_destroy(qb_object_ptr *object)
{
    memset((void *)(*object), 0, sizeof **object);
    free((void *)(*object));
    *object = NULL;
}

