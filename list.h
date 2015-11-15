typedef struct node{
	char c;
	int freq;
        int weight;
	struct node* next, *prev,*left, *right;
	}node;
typedef struct list{
	struct node *head, *tail;
	}list;
typedef struct data{
	char str[16];
	char ch;
	struct data *next, *prev;
}data;
typedef struct list1{
	struct data *head, *tail;
}list1;
struct node *root, *s1, *curr, *pushele;
node *start, *start1, *head, *nhead;
char ch1;

void init(list* l);
void insert(list* l, char str, int pos);
void append(list *l, char str);
void sort(list *l);
void search(list *l, char c);
void append1(list1 *l, char str[], char ch);
void init1(list1 *l);
void conversion(char [], char []);
void B_to_decod(char[], char[] , int); 
int bpow(int, int);
void conv_bin_char(char [],char []);
char strpath[100];
void printPaths(struct node* ); 
void printPathsRecur(struct list1 ,struct node*,char [],char, int); 
void printstr(char str[], char);
void atob(char, int []);
void  print(node*);
node* breakmerge(node *, int );
node* merge(node* ,node*);
node* htree(node*);
void  assign_initial_wt(node *);
void traverse(node *);
void treestruct( struct node *, int );
void padding(char, int);


