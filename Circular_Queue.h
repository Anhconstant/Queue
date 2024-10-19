#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__


/*  @author
    -   CIRCULAR QUEUE
    -   Queue : 
    .REAR : POS OF DATA POP IS FIRST 
    .FRONT : POS OF DATA PUSH (BEFORE PUSH IS "NULL" OR "OTHER DATA NOT OF QUEUE")
    .POS : POINTER TO ARAY 
    -   MAX_SIZE : SIZE OF QUEUE
    - INITTIALIZATION : 
        unsigned long arr[MAX_SIZE] ;   // NAME OF ARRAY
        QueueStruct queueX ={   .front =  0 ,
                                .rear = -1 ,
                                .pos = &arr[0] } ; // INIT QUEUE
*/
#define MAX_SIZE    15  /*  size of queue   */

typedef enum{
    QUEUE_FAIL = 0u,
    QUEUE_SUCCESS = 1u
}QUEUE_STATUS ;

typedef struct 
{
    int front ;
    int rear ;
    unsigned long* pos ; /* POINTER TO ARRAY OF DATA */
}   QueueStruct ;

unsigned long arr[MAX_SIZE] ;   // extern

QueueStruct queueX ={   .front =  0 ,
                        .rear = -1 ,
                        .pos = &arr[0] } ;
// extern
QUEUE_STATUS Queue_isEmpty(QueueStruct* queue) ;
QUEUE_STATUS Queue_isFull(QueueStruct* queue) ;
QUEUE_STATUS Queue_PUSHData(QueueStruct* queue,unsigned long data) ;
long int Queue_POPData(QueueStruct* queue) ;
QUEUE_STATUS show_queue(QueueStruct* queue) ; /* debug */
#endif
