#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void init1(list1 *l) {
	l->head = l->tail = NULL;
}
void append1(list1 *l, char str[], char ch){
	data *tmp, *q;
	tmp = (data*)malloc(sizeof(data));
	int i= 0, j,k;
	j =strlen(str);
	char c[j-1];
	for(i = 0, k = 0; str[i] != '\0'; i++){
		switch(str[i]){
			case '1':
			case '0':
				c[k++] = str[i];		
		}
	}
	c[k] = '\0';
	strcpy(tmp->str,c);
	tmp->ch = ch;
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


