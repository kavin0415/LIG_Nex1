#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <stdlib.h>
typedef struct _node{
	int data;
	struct _node* next;
	struct _node* prev;
}Node;
 Node* createNode(int data) {
	Node * newnode = NULL;
	newnode = (Node*)malloc((sizeof(Node)));
	if (newnode == NULL)
	{
		printf("short of memory");
		return NULL;
	}
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
 void getscan() {
	 return
 }
int main(void) {
	char arr[100000] = { 0 };
	int N=0;
	(void)scanf("%s", arr);
	(void)scanf("%d", &N);
	getscan();
	for
}
#endif