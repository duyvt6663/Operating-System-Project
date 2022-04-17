#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
    if(q->size < MAX_QUEUE_SIZE)
        q->proc[q->size++] = proc;
}

int peek(struct queue_t * q)
{
    /* RETURN the first top priority index
     * given that q->size > 0
     * */
    int idx = 0;
    uint32_t TP = q->proc[0].priority;

    for(int i = 1; i < q->size; ++i)
        if(q->proc[i].priority > TP)
        {
            TP = q->proc[i].priority;
            idx = i;
        }

    return idx;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
    if(q->size > 0)
    {
        int idx = peek(q);
        struct pcb_t * temp = q->proc[idx];

        q->proc[idx] = q->proc[q->size];
        
        q->size--;

        return temp;
    }
	return NULL;
}

