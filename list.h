typedef struct node{
	char c;
	int freq;
        int weight;
	struct node* next, *prev,*left, *right;
}node;
typedef struct list{
	struct node *head, *tail;
}list;
typedef struct queue{
	struct node *addr;
        struct queue *ptr;
}queue; 
node *start, *start1, *head, *nhead;
char ch1;
queue *front, *rear, *treetmp, *front1, *front2, *sfront;
void init(list* l);
void insert(list* l, char str, int pos);
void append(list *l, char str);
void sort(list *l);
void search(list *l, char c);
