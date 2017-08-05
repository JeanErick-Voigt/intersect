
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intersect.h"

#define WORDLIMIT 257


//NODE * CreateNode(char * word, NODE* n);
//NODE * iterateWords(NODE *n, char** fileNum);
//void compareAndAdd(NODE *n, char * word);
//void printTree(NODE *n);


int main(int argc, char **argv)
{
	printf("Top of program\n");
	FILE* fp;
	int count = 0;
	char c;
	int root = 0;
	if (argc < 2){
		printf("Did not provide enough arguments to compare\n");
		exit(1);
	}

	int index = 0;
	for(int i = 1; i < argc; i++ ){
		fp = fopen(argv[i], "r");	
		if(fp){
			fclose(fp);
		}else{
			printf("could not open file");
			printf("%s\n", argv[i]);
		}
	}
	// iterate through words
	NODE *wordNodes = NULL;
	printf("top of loop\n");
	iterateWords(wordNodes, argv);
	printf("%s\n", wordNodes->parent->data);
	printTree(wordNodes);
	return(0);
}

NODE *iterateWords(NODE *n, char** fileNum)
{
	int wordValue;
	int count = 0;
	NODE* temp = NULL;
	FILE *fp;
	fp = fopen(*(fileNum + 1), "r");
	char c, buffer[WORDLIMIT];
	int index, root;
	index = root = 0;
	printf("before fgetc %s\n", *(fileNum + 1));
	while((c = fgetc(fp)) != EOF)
	{
		printf("Statement before buffer inc  %d\n", count++);
		buffer[index++] = c;
		if(isspace(c)){
			buffer[index - 1] = '\0';
		printf("This is after c = delimeter %s\n", buffer);
			if (n == NULL){
				n = CreateNode(buffer, temp);
				printf("This is NULL branch %s\n", n->data);
			}else{
				printf("this is else statement %s\n", n->data);
				wordValue = strcasecmp(n->data, buffer);
				if(wordValue > 0){
					if(n->right == NULL){
						n->right = CreateNode(buffer, n);
						n->right->parent = n;
					}
					n = n->right;
				}
				else if(wordValue < 0){
					if(n->left == NULL){
						n->left = CreateNode(buffer, n);
						n->left->parent = n;
					}
					n = n->left;
				}else{
					break;
				}

			}
			buffer[0] ='\0';
			index = 0;
		}
		printf("This is index  %d\n", index);
	}
	fclose(fp);
	return(n);

}

void printTree(NODE* n)
{
	if (n == NULL)
		return;
	printTree(n->left);
	printf("%s\n", n->data);
	printTree(n->right);
	printTree(n->parent); 
}

void compareAndAdd(NODE *n, char * word)
{
	NODE* temp;
	int wordValue;
	while(1)
	{
		wordValue = strcasecmp(n->data, word);
		if (wordValue == 0){ //words match and break
			break;
		}
		else if(wordValue < 0)
		{
			if (n->right == NULL){
				n -> right = CreateNode(word, temp);
				n -> right -> parent = n;
				break;
			}
			n = n -> right;
		}else{
		
			if (n -> left == NULL){
				n -> left = CreateNode(word, temp);
				n -> left -> parent = n;
				break;
			}
			n = n -> left;
		}
		n->wCount = 1;
	}
}

NODE* CreateNode(char *word, NODE* n)
{
	n = malloc(sizeof(NODE));
	n->data = malloc(sizeof(char*) * (strlen(word) + 1));
	strcpy(n->data, word);
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;
	n->wCount = 1;
	n->root = NULL;
	return n;
}

