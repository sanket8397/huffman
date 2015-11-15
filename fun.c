#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"list.h"

static int max, count, visitednode, ccount;
char ch, str[15];
int found = 0;

void print(node *final){
	printf("\n");
	while(final){
		printf("%c:%d  ", final->c, final->weight);
		final = final->next;
	}
}
int nodecount(node *q){
        int count = 0;
	while(q != NULL){
		count++;
		q = q->next;
	}
	return count;
}

node* breakmerge(node *head, int n){
	node *work[n+1];
	int lim, j, k, chk; 
	for ( k = 0; k < n; k++ ){
		work[k] = head;
		head = head->next;
		work[k]->next = NULL;
        }
	work[k] = NULL;
	for ( lim = n ; lim > 1 ; lim = (lim+1)/2 ){
		for ( j = k = 0; k < lim; j++, k += 2 ){
			work[j] = merge ( work[k], work[k+1] );
		}
	work[j] = NULL;     /* Extra null reference for odd cases */
	}
	return work[0];
}

node* merge(node *a,node *b){
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

void assign_initial_wt(node *ntmp){
	node *final = ntmp;
	int freq;
	while(ntmp!=NULL){
		ntmp->weight = ntmp->freq;
		ntmp->left = NULL;
		ntmp->right = NULL;
		ntmp = ntmp->next;
	}
	while(final){
		final=final->next;
	}
}
 
node* htree(node *head){
	node *ntmp, *ntmp1, *ntmp2, *tmp, *wt, *lt, *rt, *start;
	int wtval1, wtval2, rflag = 1, chk, prevwt;
	while(head->next != NULL){
		rflag = 1;
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
/*		printf("%d", ntmp->weight);*/
		if (nhead == NULL){
			head = head->next;
			nhead = ntmp;
			while(head!=NULL){
				ntmp1 = ( node*) malloc( sizeof( node));
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
/*			print( nhead);*/
		}
		else{
/*			printf("%d", ntmp->weight);*/
			ntmp->next = head->next;
			nhead = ntmp;
		}
		head = breakmerge(nhead, nodecount( nhead));
	}
	return ( head);
}

list1 t;
void printPaths(struct node *node){	
	extern	list1 t;
	init1(&t);
	char strpath[100];
	printPathsRecur(t, node, strpath, ' ', 0);
	data *g;
	g = t.head;
	while(g){
/*		printf("%c :: %s",g->ch,g->str);*/
		g = g->next;	
	}
}

void conversion(char buffer[],  char s[]){
	int pos=0, size = 1024, i, len, slen, j, cnt0_5 = 0, cnt1_5 = 0, chk;
        char c, c1;
	data *k;
	len = strlen( buffer);
/*	printf("\nbuffer len :%d  ", len);
	scanf("%d", &i);*/
	for(i = 0; i < len; i++){
		c = buffer[i];	
		k = t.head;
		while(k->ch != c){
			k = k->next;
			}
		slen = strlen(k->str);
		for(j = 0; j < slen; j++){
			s[pos++] = (char) k->str[j];
			if(pos >= size - 1) { 
				size *= 2;
				s = (char*)realloc(s, size);
			}
			if( k->str[j] == '0'){
				cnt0_5++;
				if( cnt0_5 == 5){
					s[pos++] = '1';
					cnt0_5 = 0; 
				}
				cnt1_5 = 0;
			}
			else{
				cnt0_5 = 0;
				cnt1_5++;
				if(cnt1_5 == 5){
					s[pos++] = '0';
					cnt1_5 = 0; 
				}
			}
		}
	}
	s[pos] = '\0';	
}

void atob(char ch, int ar[]){
	int b, i = 0, j;
	int a[8];
	b = ch;
	if(b < 0){
		b = 256 + b;
	}
	while(b != 0){
		a[i] = b % 2;
		b = b / 2;
		i++;
	}
	while(i < 8){
		a[i] = 0;
		i++;	
	}
	for(j = 0;j < 8; j++){
		ar[j] = a[7-j];
	}
	return ;	
}

void conv_bin_char(char bs[], char cs[]){
	int i, j, len, maxlen = 0, temp, pos = 0, ctrli, ctrlj, ctrlk, ctrl_value, ctrllen, size = 1024, chk; 
	char mstr[16] = "\0", tempstr[1000] = "\0";
	data *k;
	ctrli = (int) bs[0] - 48;
	ctrlj = (int) bs[1] - 48;
	ctrlk = (int) bs[2] - 48;
	if ((ctrli == 0) && (ctrlj == 0) && (ctrlk == 0))
		ctrl_value = 0;
	if ((ctrli == 0) && (ctrlj == 0) && (ctrlk == 1))
		ctrl_value = 1;
	if ((ctrli == 0) && (ctrlj == 1) && (ctrlk == 0))
		ctrl_value = 2;
	if ((ctrli == 0) && (ctrlj == 1) && (ctrlk == 1))
		ctrl_value = 3;
	if ((ctrli == 1) && (ctrlj == 0) && (ctrlk == 0))
		ctrl_value = 4;
	if ((ctrli == 1) && (ctrlj == 0) && (ctrlk == 1))
		ctrl_value = 5;
	if ((ctrli == 1) && (ctrlj == 1) && (ctrlk == 0))
		ctrl_value = 6;
	if ((ctrli == 1) && (ctrlj == 1) && (ctrlk == 1))
		ctrl_value = 7;
	ctrllen = strlen(bs);
	ctrllen = ctrllen - ctrl_value;
 	for(i = 3, j = 0; i < ctrllen; i++){
		memset(mstr, '\0', sizeof(mstr));
		mstr[j] = bs[i];
		strcat(mstr, "\0");     
		found = 0;
		while(found != 1){
			k = t.head;
			while(k != NULL && found != 1){
				if (strcmp(mstr,k->str) == 0){
					found = 1;
            				cs[pos++] = k->ch;
            				if(pos >= size - 1) { 
        	   				size *= 2;
           	   				cs = (char*)realloc(cs, size);
					}
				}
				k = k->next;       
			} 
			if(found == 0){ 
				k = t.head;
				j++;
				i++;
				mstr[j] = bs[i];
				strcat(mstr, "\0");
			}  
		}
		if(found == 1){
			j = 0;
			found = 0;
		}
	}
	cs[pos] = '\0';
}

void B_to_decod(char input[], char output[],int size){
	int length = strlen(input), chk;     
	int x, a, y, z, counter, ct, power[8], rem,i = 0, pos = 0;
	int binary[8];    
	int asciiNum = 0;     
	char ascii;
	char  *ctrlinput = (char *)malloc(size);      
	rem = 8 - (length + 3) % 8;
        if (rem == 8)
		rem=0;
	for(i=0;i<rem;i++){
		if(i%2==1)
			strcat(input,"1");
		else
			strcat(input,"0");
	}
	strcat(input,"\0");
	switch(rem){
		case 0 :ctrlinput[0] = '0';
			ctrlinput[1] = '0'; 
			ctrlinput[2] = '0';
			break;
		case 1 :ctrlinput[0] = '0';
			ctrlinput[1] = '0'; 
			ctrlinput[2] = '1';
			break;
		case 2 :ctrlinput[0] = '0';
			ctrlinput[1]='1'; 
			ctrlinput[2]='0';
			break;
		case 3 :ctrlinput[0] = '0';
			ctrlinput[1] = '1'; 
			ctrlinput[2] = '1';
			break;
		case 4 :ctrlinput[0] = '1';
			ctrlinput[1] = '0'; 
			ctrlinput[2] = '0';
			break;
		case 5 :ctrlinput[0] = '1';
			ctrlinput[1] = '0'; 
			ctrlinput[2] = '1';
			break;
		case 6 :ctrlinput[0] = '1';
			ctrlinput[1] = '1'; 
			ctrlinput[2] = '0';
			break;
		case 7 :ctrlinput[0] = '1';
			ctrlinput[1] = '1'; 
			ctrlinput[2] = '1';
			break;
	}
	ctrlinput[3] = '\0';
	strcat(ctrlinput, input);
	input = (char*)realloc(input, size);        
	memset(input, '\0', sizeof(input));
	strcpy(input, ctrlinput);
	z = 0;  
        pos = 0; 
	length = strlen(input);
	for(x = 0; x < length / 8; x++){     /* total characters = length / 8 */
		for( a = 0; a < 8; a++){
			binary[a] = (int) input[z] - 48;  /* char '1'-48 gives integer 1 */
			z++;		                  /* char '0'-48 gives integer 0 */
		}
		counter = 7;        
		for( ct = 0; ct < 8; ct++){
			power[ct] = counter;      /* power[] = {7, 6, 5, ..... 1, 0} */
			counter--;    		/* decrement counter each time */
		}
		for( y = 0; y < 8; y++){
			int a = binary[y];    
			int b = power[y];    
			asciiNum += a* bpow(2, b); 
		}
		ascii = asciiNum;   
		asciiNum = 0;    
		output[pos++] = (char)ascii;
		if(pos >= size - 1) { 
			size *=2;
			output = (char*)realloc(output, size);
		}
	}
	output[pos] = '\0';
}

int bpow(int x, int n){
	int result = 1, i = 0;
	for(i = 0; i < n; i++)
		result = result * 2;
	return result;
}

void printPathsRecur(struct list1 t, struct node *node, char strpath[], char lr, int pathLen){
	if (node == NULL) 
		return;
	/* append this node to the path array */
	strpath[pathLen] = lr;
	pathLen++;
	/* it's a leaf, so print the path that led to here  */
	if (node->left == NULL && node->right == NULL){
		strpath[pathLen] = '\0';
		printstr(strpath, node->c);
	}
	else{
		/* otherwise try both subtrees */
		printPathsRecur(t,node->left, strpath,'0', pathLen);
		printPathsRecur(t,node->right, strpath,'1', pathLen);
	}
}

void printstr(char str[], char ch){
	append1(&t, str, ch);
}    
 
void padding ( char ch, int n ){
	int i;
	for ( i = 0; i < n; i++ )
		putchar ( ch );
}

void treestruct ( struct node *link, int level ){
	int i;
	if ( link == NULL ) {
		padding ( '\t', level );
		puts ( "Å" );
	}
	else {
		treestruct( link->right, level + 1 );
		padding ( '\t', level );
		printf ( "%c:%d\n",link->c, link->weight );
		treestruct( link->left, level + 1 );
	}
}
