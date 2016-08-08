#ifndef QB_LIST_H
#define QB_LIST_H

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Forward declarations------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/
 
/* Macros--------------------------------------------------------------------*/
 
/* Data types----------------------------------------------------------------*/

typedef struct qb_list_s* qb_list_ptr;
typedef struct qb_list_elem_s* qb_list_elem_ptr;
typedef void (*qb_destroy_elem)(void**);

/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

qb_list_ptr qb_list_create(void);
void qb_list_destroy(qb_list_ptr *list);



#ifdef __cplusplus
}
#endif

#endif /* QB_LIST_H */

