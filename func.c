#include <stdio.h>
#include <stdlib.h>
#include"list.h"
#include <string.h>

void cpush(char c);/* stack */
char cpop();/* stack */
void push(void);
struct node *pop(void);
void  print(node *);
node* breakmerge(node *, int);
node* merge(node *, node*);
node* htree(node *);
void  assign_initial_wt(node *);
void  enq(node *);/* queue */
node* deq(void);/* queue */
void traverse(node *);
void treestruct(struct node *, int);
void padding(char , int);


struct node *root,*s1,*curr,*pushele;

/*stack*/ 
 struct stack{
	struct stud *addr;
 	struct stack *ptr;
} *top, *top1, *tmp;

struct cstack{
	char ch;
	struct cstack *ptr;
}*ctop,*ctop1,*ctmp;

static int max, count, visitednode, ccount;
char ch, str[15];
int found=0;

void print(node *final){
	printf("\n");
	while(final){
		printf("%c:%d  ",final->c, final->weight);
		final = final->next;
	}
}
int nodecount(node * q){
	int count = 0;
	while(q != NULL){
		count++;
		q = q->next;
        }
	return count;
}

node* breakmerge(node *head,int n){
	node* work[n+1];
	int lim , j, k, chk; 
	for(k = 0; k < n; k++){
		work[k] = head;
		head = head->next;
		work[k]->next = NULL;
        }
	work[k] = NULL;
	for (lim = n; lim > 1; lim = (lim + 1) / 2 ){
		for (j = k = 0; k < lim; j++, k += 2){
			work[j] = merge(work[k], work[k+1]);
		}
		work[j] = NULL;     /* Extra null reference for odd cases */
        }
	return work[0];
}

node* merge(node *a, node *b){
	node *result = NULL;
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	if(a->weight <=  b->weight){
		result = a;
		result->next = merge(a->next, b);
	}
	else{
		result = b;
		result->next = merge(a,b->next);
	}
	return result;
}

void  assign_initial_wt(node *ntmp){
	node *final=ntmp;
	int freq;
	while(ntmp != NULL){
		ntmp->weight = ntmp->freq;
		ntmp->left = NULL;
		ntmp->right = NULL;
		ntmp = ntmp->next;
	}
	while(final){
		printf("%c:%d  ",final->c, final->weight);
		final = final->next;
        }
}
 
node* htree(node* head){
	node *ntmp, *ntmp1, *ntmp2, *tmp, *wt, *lt, *rt, *start;
	int wtval1, wtval2, chk, prevwt;
	print(head);
	while(head->next != NULL){

		lt = head;
		wtval1 = lt->weight;         
		head = head->next;
		rt = head;
		wtval2 = rt->weight;
		ntmp = (node*)malloc(sizeof(node));
		ntmp->left = lt;
		ntmp->right = rt;
		prevwt = wtval1 + wtval2;
		ntmp->weight = prevwt;
		if (nhead == NULL){
			head = head->next;
			nhead = ntmp;
			while(head != NULL){
				ntmp1 = (node*)malloc(sizeof(node));
				ntmp1->c = head->c;
				ntmp1->freq = head->freq;
				ntmp1->left = head->left;
				ntmp1->right = head->right;
				ntmp1->weight = head->weight;
				ntmp1->next = NULL;
				ntmp->next = ntmp1;
				head = head->next;  
				ntmp = ntmp1;           
			}
		}
		else{
             		ntmp->next = head->next;
			nhead = ntmp;
		}
		head = breakmerge(nhead,nodecount(nhead));
		printf("\nsorted:");
		print(head);
}
 return (head);
}
void traverse(struct node *s1){
	int i = 0;
	found = 0;
	top = NULL;
	ctop = NULL;
	start = s1;
	while(s1 != NULL){
		cpush('0'); 
		check(s1);
		if(found == 1){
			ch=cpop();
			break;
		}
		if(s1->right != NULL){
			pushele = s1->right;
			push();
			cpush('R');
		}
		if(s1->right==NULL)
			cpush('N');
	s1=s1->left;
	}
	while(count > 0){
		if(found == 1)
			break;
		if(s1 == NULL){
			s1=pop();
			ch=cpop();
			while(ch!='R'){
				ch=cpop();
			}
		ch=cpop();
		}   
		cpush('1');
		check(s1);
		if(found == 1)
			break;
		if(s1->right != NULL){
			pushele=s1->right;
			push();
			cpush('R');
		}
		if(s1->right == NULL)
			cpush('N');
		s1=s1->left;
		cpush('0');
	}
	printf("\nAt End of traverse:");
	strcpy(str," ");
	i = 0;
	while(ctop != NULL){
		ch = cpop();
		if(ch == '0' || ch == '1'){
			str[i]=ch;
			i++;
		}
	}
	str[i]='\0';
}

check(struct node *cnode){
	char ch = cnode->c;
	visitednode++;
	if(ch == ch1){
		printf("\nFound at node %d",visitednode);
		found = 1;
	}
}
/********************************************************************/
void push(void ){
	if(top == NULL){
		top = (struct stack *)malloc(sizeof(struct stack));
		top->ptr = NULL;
		top->addr = pushele;
		count++;
}
	else{
		tmp = (struct stack *)malloc(sizeof(struct stack));
		tmp->ptr = top;
		tmp->addr = pushele;
		top = tmp;
		count++;
	}
}
struct node *pop(){
	top1 = top;
	if(top1 == NULL)
		return(NULL);
	else{
		top1 = top1->ptr;
		curr = top->addr;
		free(top);
		top = top1;
		count--;
		return(curr);
	}
 }
/***********************************************/
/* char Stack*/
void cpush(char c){
	if(ctop == NULL){
		ctop = (struct cstack *)malloc(sizeof(struct cstack));
		ctop->ptr = NULL;
		ctop->ch = c;
		ccount++;
	}
	else{
		ctmp= (struct cstack *)malloc(sizeof(struct cstack));
		ctmp->ptr = ctop;
		ctmp->ch = c;
		ctop = ctmp;
		ccount++;
	}
}
char cpop(){
	char popch;
	ctop1 = ctop;
	if(ctop1 == NULL)
		return(NULL);
 	else{
		ctop1 = ctop1->ptr;
		popch = ctop->ch;
 		free(ctop);
		ctop=ctop1;
		ccount--;
		return(popch);
	}
}
/**********************************************/
void padding(char ch, int n){
	int i;
	for(i = 0; i < n; i++)
		putchar ( ch );
}

void treestruct(struct node *link, int level){
	int i;
	if(link == NULL){
		padding('\t', level);
		puts ("Å");
	}
	else{
		treestruct(link->right, level + 1);
		padding('\t', level);
		printf("%c:%d\n",link->c, link->weight);
	 	treestruct(link->left, level + 1);
	}
}
