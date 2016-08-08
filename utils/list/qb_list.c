#include "qb_list.h"

#include <stdio.h>

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/

/* Data types----------------------------------------------------------------*/

struct qb_list_elem_s
{
    qb_list_elem_ptr next;
    qb_list_elem_ptr prev;
    void* data;
};

struct qb_list_s
{
    qb_destroy_elem destroy_elem;
    qb_list_elem_ptr head;
    qb_list_elem_ptr tail;
};

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

/* Functions definitions-----------------------------------------------------*/

qb_list_ptr qb_list_create(void)
{
    return NULL;
}

void qb_list_destroy(qb_list_ptr *list)
{
    (void)list;
}

