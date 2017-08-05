
struct node {
	int wCount;
	struct node* left;
	struct node* right;
	struct node* parent;
	struct node* root;
	char* data;	

};
typedef struct node NODE;

NODE * CreateNode(char* word, NODE *n);
//NODE * CreateNonEmptyNOde(NODE *n, char* word);
NODE * iterateWords(NODE * n, char ** filenum);
void compareAndAdd(NODE *n, char * word);
void printTree(NODE *n);
