#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
	return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
	/* TODO: put a new process to queue [q] */ //DONE
	q->proc[q->size] = proc;
	q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q //DONE
	 * */
	struct pcb_t *result = NULL;
	int j = -1;
	for (int i = 0; i < q->size; i++)
	{
		if (result == NULL || result->priority < q->proc[i]->priority)
		{
			result = q->proc[i];
			j = i;
		}
	}

	if (result)
	{
		q->proc[j] = q->proc[q->size - 1];
		q->size--;
		return result;
	}
	else
		return NULL;
}
