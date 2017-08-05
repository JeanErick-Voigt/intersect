#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intersect.h"

#define WORDLIMIT 257


NODE * CreateNode(NODE *n, char * word);
NODE * CreateNonEmptyNode(NODE *n, char * word);




int main(int argc, char **argv)
{
	printf("Top of program");
	FILE* fp;
	FILE* fp1;
	char buffer[WORDLIMIT];
	int wordValue;
	int count = 0;
	char c;
	int root = 0;
	//if (argc < 2){
	//	printf("Did not provide enough arguments to compare\n");
	//	exit(1);
	//}

	int index = 0;
//	for(int i = 1; i < argc; i++ ){
//		fp = fopen(argv[i], "r");	
//		if(fp){
//			rewind(fp);
//			fclose(fp);
//			fp = NULL;
//		}else{
//			printf("could not open file");
//			printf("%s\n", argv[i]);
//		}

//	}
	// iterate through words
	NODE *wordNodes = NULL;
	NODE *temp = NULL;
	printf("%s" , argv[2]);
	fp1 = fopen(argv[1], "r");
//	if(fp){
//		printf("Good");
//		printf("%ld", ftell(fp));
//	}
	printf("top of loop");
	while((c = fgetc(fp1)) != EOF){
		buffer[index++] = c;
		if(c == ' ' || c == '\t' || c =='\n'){
			buffer[index] = '\0'; // to compare against tree
			

			// if no nodes initialize first node and set space equal to the buffer word
			if(root == 0){
				wordNodes = CreateNode(wordNodes, buffer);
				wordNodes -> root -> data = wordNodes -> data = buffer;
				root = 1;
				printf("%s\n", wordNodes -> root -> data);
				buffer[0] = '\0';
				index = 0;
				continue;
			}
			//There is already a root
			while(1){
				wordValue = strcasecmp(wordNodes->data, buffer);
				wordNodes = CreateNonEmptyNode(wordNodes, buffer);
				if(wordValue > 0){
					//wordNodes = CreateNonEmptyNOde(wordNode, buffer);
					if(wordNodes -> right == NULL){
						wordNodes = wordNodes->right;
						wordNodes = CreateNonEmptyNode(wordNodes, buffer);
						wordNodes -> parent -> data = wordNodes -> data;
						wordNodes->data  = buffer;
						break;
					}else{
						wordNodes = wordNodes->right;
					}
				}
				else if(wordValue < 0){
					if(wordNodes -> left == NULL){
						wordNodes = wordNodes -> left;
						wordNodes = CreateNonEmptyNode(wordNodes, buffer);
						wordNodes -> parent -> data = wordNodes -> data;
						wordNodes -> left -> data = buffer;
						break;
					}else{
						wordNodes = wordNodes -> left;
					}
				}else{
					break;
				}
			} 

		}
		buffer[0] = '\0';
		index = 0;
	}
	return(0);
}


			


				/*if(count == 0){ // root set
				wordNodes = CreateNode(WordNodes, buffer);
				count = 1;
				continue;

			}
			
			if (NODE wordNodes == NULL){   //add node and if first go around root node
				strccasecmp(CreateNonEmptyNode(wordNodes, buffer), ;
				count = 1
			}     

			wordValue = strcasecmp(wordNodes -> data, buffer)
			if (wordValue == 0){
				break;
			}

			else if(wordValue == -1 & ){ 

				
			}
			else if (count == 0){ //root node
				if (wordValue == - 1){
					wordNodes = WordNodes -> word;
				}

				el{
		fp = fopen(argv[i], "r");


		}
	}
}
*/

//no root
NODE* CreateNode(NODE* n, char *word) 
{

	n = malloc(sizeof(NODE));
	//NODE *n->data = malloc(sizeof(char*) * (strlen(word) + 1));
	//strcpy(n->data, word);
	//n->root = n->data;
	n -> parent = NULL;
	n -> left = NULL;
	n -> right = NULL;
	n -> wCount = 1;
	n -> root = NULL;
	return n;
}

NODE* CreateNonEmptyNode(NODE* n, char * word)
{
	n = malloc(sizeof(NODE));
	n->data = malloc(sizeof(char*) * strlen(word) + 1);
	return n;
}

