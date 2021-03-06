#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size < MAX_QUEUE_SIZE && proc != NULL) {

		q->proc[q->size] = proc;
		q->size++;
	}
	// debug : fix
	//printf("%d\n", q->size);
	// int i ;
	// for (i = 0; i < q->size; i++) {
	// 	printf("%d", q->proc[i]->pid);
	// }
	//
	// printf("\n");
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */

	// if q is not empty then we can dequeue
	if (!empty(q)) {

		struct pcb_t * proc = NULL;
		proc = q->proc[0]; // asssume highest at head

		int i = 0;
		int temp = 0;
		// find highest
		for (i = 0; i < q->size; i++) {
			if (proc->priority <= q->proc[i]->priority) {
				temp = i;
				proc = q->proc[i];
			}
		}

		// remove the highest
		for (i = temp; i < q->size - 1; i++) {
			q->proc[i] = q->proc[i + 1];
		}

		q->size--;
		// printf("%d\n", q->size);

		return proc;

	}
	return NULL;
}
