#ifndef __LINER_QUEUE_H__
#define __LINER_QUEUE_H__
#include "stdio.h"

/*  @author : github.com/Anhconstant
    FIRST IN FIRST OUT
    -   LINER QUEUE
    -   Queue : 
    .0 : POS OF DATA POP IS FIRST 
    .FRONT : POS OF DATA PUSH (BEFORE PUSH IS "NULL" OR "OTHER DATA NOT OF QUEUE")
    .POS : POINTER TO ARAY 
    -   LINER_MAX_SIZE : SIZE OF QUEUE
    - INITTIALIZATION : 
        unsigned long arr[CIRCULAR_MAX_SIZE] ;   // NAME OF ARRAY
        CircularQueue_Struct queueX ={   .front =  0 ,
                                .pos = &arr[0] } ; // INIT QUEUE
*/
#define LINER_MAX_SIZE  15
typedef enum{
    QUEUE_FAIL = 0u,
    QUEUE_SUCCESS = 1u
}QUEUE_STATUS ;

typedef struct{
    int front   ;
    unsigned long* pos  ;   /* POINTER TO ARRAY OF DATA */
}LinerQueue_Struct;

extern unsigned long LinerArray[LINER_MAX_SIZE] ;
extern LinerQueue_Struct LinerQueueX   ;

QUEUE_STATUS Queue_isEmpty(LinerQueue_Struct* queue)    ;
QUEUE_STATUS Queue_isFull(LinerQueue_Struct* queue) ;
QUEUE_STATUS Queue_PUSHData(LinerQueue_Struct* queue, unsigned long data) ;
static int Queue_peek(LinerQueue_Struct* queue) ;
long int Queue_POPData(LinerQueue_Struct* queue) ;
void show_queue(LinerQueue_Struct* queue)   ;


#endif
