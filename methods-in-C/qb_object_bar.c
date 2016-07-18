#include "qb_object_bar.h"
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
    char temp;
    char *name;
} qb_object_impl_s;

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

static void int_method(qb_object_ptr self);
static qb_object_impl_ptr int_qb_object_impl_create(void);
static void int_qb_object_impl_destroy(qb_object_impl_ptr *implementation);

/* Functions definitions-----------------------------------------------------*/

qb_object_ptr qb_object_bar_create(void)
{
    struct qb_object *temp = (struct qb_object *) malloc(sizeof *temp);
    if (NULL == temp)
    {
        printf("NULL pointer\n");
        return temp;
    }

    temp->method = int_method;
    temp->object = int_qb_object_impl_create();
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

static qb_object_impl_ptr int_qb_object_impl_create(void)
{
    printf("object BAR implementation constructor\n");
    return NULL;
}

void qb_object_bar_destroy(qb_object_ptr *object)
{
    if (NULL == object)
    {
        printf("prevents from NULL as argument\n");
        return;
    }

    if (NULL == *object)
    {
        printf("prevetns from pointing to NULL\n");
	return;
    }

    int_qb_object_impl_destroy((qb_object_impl_ptr *)&(*object)->object);
    memset((void *)(*object), 0, sizeof **object);
    free((void *)(*object));
    *object = NULL;
}

static void int_qb_object_impl_destroy(qb_object_impl_ptr *implementation)
{
    (void)implementation;
    printf("object BAR implementation destructor\n");
}
