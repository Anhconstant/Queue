#ifndef __LINER_QUEUE_C__
#define __LINER_QUEUE_C__
#include "Liner_Queue.h"


unsigned long LinerArray[LINER_MAX_SIZE] ;
LinerQueue_Struct LinerQueueX   = {
                                    .front = 0 ,
                                    .pos = &LinerArray[0]
                                }   ;

QUEUE_STATUS Queue_isEmpty(LinerQueue_Struct* queue){
    if(queue->front == 0 )return QUEUE_SUCCESS  ;
    else return QUEUE_FAIL  ;
}
QUEUE_STATUS Queue_isFull(LinerQueue_Struct* queue){
    if(queue->front == LINER_MAX_SIZE) return QUEUE_SUCCESS ;
    else return QUEUE_FAIL  ;
}
QUEUE_STATUS Queue_PUSHData(LinerQueue_Struct* queue, unsigned long data){
    if(Queue_isFull(queue)) return QUEUE_FAIL   ;
    else {
        queue->pos[queue->front++] = data   ;
        return QUEUE_SUCCESS    ;
    }
}
static int Queue_peek(LinerQueue_Struct* queue){
    for(int i = 0; i < queue->front - 1  ; i++ ){
        queue->pos[i] = queue->pos[i+1] ;
    }
    return 1;
}
long int Queue_POPData(LinerQueue_Struct* queue){
    long int data = queue->pos[0]   ;
    Queue_peek(queue)   ;
    queue->front -- ;
    return data ;
}
void show_queue(LinerQueue_Struct* queue){
    for(int i = 0 ; i < queue->front  ; i++) printf("pos(%d) = %ld ; ", i , queue->pos[i]) ;
}

#endif
