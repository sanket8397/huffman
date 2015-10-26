#include <stdio.h>
#include <stdlib.h>
#include "list.h"
main(){
	list l;
	node *q, *sq, *start;
	init(&l);
	char c;
	int chk, count = 0;
	scanf("%c",&c);		/*only for entering 1st element*/
	append(&l, c);
	while(scanf("%c",&c) != -1){
		search(&l,c);
	}
	q = l.head;

	while(q != NULL){
		count++;	/*to count no. of elements*/
		q = q->next;
	}
	q = l.head;       
	print(q);
	assign_initial_wt(q);
	sq = breakmerge(q,count);
	print(sq);
	start = htree(sq);
	start1 = start;
	//treestruct(start1,0);
	printf("list is:");
        while(sq != NULL){
		ch1 = sq->c;
		traverse(start);
		sq = sq->next;
        }
        printf("\ndone................");
}
