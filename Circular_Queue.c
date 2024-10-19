#ifndef __CIRCULAR_QUEUE_C__
#define __CIRCULAR_QUEUE_C__
#include "Circular_Queue.h"


// unsigned long arr[MAX_SIZE] ;

// QueueStruct queueX ={   .front =  0 ,
//                         .rear = -1 ,
//                         .pos = &arr[0] } ;

QUEUE_STATUS Queue_isEmpty(QueueStruct* queue){
    if( ((queue->front == queue->rear+1 ) )) return QUEUE_SUCCESS;
    else return QUEUE_FAIL;
}
QUEUE_STATUS Queue_isFull(QueueStruct* queue){
    if(  queue->rear == queue->front   ){
        return QUEUE_SUCCESS;
    }
    else{ 
        return QUEUE_FAIL;
    }
}
QUEUE_STATUS Queue_PUSHData(QueueStruct* queue,unsigned long data){
    if(Queue_isFull(queue)){
        return QUEUE_FAIL   ;
    }       
    else if((queue->front + 1 )== MAX_SIZE ){
        queue->pos[queue->front] = data ;
        queue->front = 0 ;
        return QUEUE_SUCCESS ;
    }
    else {
        if(queue->rear == -1) queue->rear = 0; 
        queue->pos[queue->front] = data ;
        queue->front++ ;
        return QUEUE_SUCCESS ;
    }
}
long int Queue_POPData(QueueStruct* queue){
    if(Queue_isEmpty(queue)){
        return QUEUE_FAIL ;        
    }
    else if((queue->rear + 1 )== MAX_SIZE ){
        long int data = queue->pos[queue->rear] ;
        queue->rear = -1 ;
        return data ;
    }
    else{
        long int data = queue->pos[queue->rear] ;
        queue->rear ++ ;
        return data ;
    }
}

QUEUE_STATUS show_queue(QueueStruct* queue){
    if(Queue_isEmpty(queue)){
        return QUEUE_FAIL ;        
    }else {
        int pos = queue->rear ;
        do 
        {
            printf("pos(%d) = %ld ; ",pos , queue->pos[pos]) ;
            if( pos + 1 == MAX_SIZE ) pos = 0 ;
            else pos++ ;
        } 
        while(pos  != queue->front  );
        printf("\n");
        return QUEUE_SUCCESS ; 
    }
}
#endif
