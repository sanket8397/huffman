#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* doubly linked list */
void init(list *l) {
	l->head = l->tail = NULL;
}
void append(list *l, char str){
	node *tmp, *q;
	tmp = (node*)malloc(sizeof(node));
	tmp->c = str;
	tmp->freq = 1;
	if(l->head == NULL){
		tmp->next = NULL;
		l->head = l->tail = tmp;
		return;
	}
	else{
		q = l->tail;
		q->next = tmp;
		tmp->next = NULL;
		tmp->prev = q;
		l->tail = tmp;
		return;
	}	
}
void search (list *l, char c){
	int k = 0;
	node *q;
	q = l->head;
	while(q->c != c){
		q = q->next;
		if (q == NULL){
			k = 1;
			break;
		}
	}
	if(k == 0){
		q->freq = q->freq + 1; 
	}
	if(k == 1){
		append(l, c);
	}
	
}

