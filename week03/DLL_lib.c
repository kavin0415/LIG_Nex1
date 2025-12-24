#include "DLL_lib.h"
NodeDLL* DLL_CreateNode(ElementType data) 
{
	NodeDLL* newnode = NULL;
	newnode = (NodeDLL*)malloc(sizeof(NodeDLL));
	if (newnode == NULL) 
	{
		printf("short of memory");
		return NULL;
	}
	newnode->Data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
//prev -> newnode -> tail
void DLL_ApendNode(NodeDLL* tail, NodeDLL* newnode) 
{
	NodeDLL* prev = tail->prev;
	newnode->next = tail;
	newnode->prev = prev;
	tail->prev = newnode;
	prev->next = newnode;
}
void DLL_PrintNode(NodeDLL* head,NodeDLL* tail) {
	for (NodeDLL *curr = head->next ; curr != tail; curr = curr->next)
	{
		printf("%d ", curr->Data);
	}
	printf("\n");
}
NodeDLL* DLL_SearchNode(ElementType data, NodeDLL* head, NodeDLL* tail) {
	for (NodeDLL* curr = head->next; curr != tail; curr = curr->next)
	{
		if (data == curr->Data)
			return curr;
	}
	return NULL;
}
void DLL_RemoveNode(NodeDLL* delnode) {
	NodeDLL * prevNode = delnode->prev;
	NodeDLL* nextNode = delnode->next;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	free(delnode);

}
void DLL_InsertAfter(NodeDLL* fnode,NodeDLL* newnode) {
	NodeDLL * nextNode = fnode->next;
	nextNode->prev = newnode;
	fnode->next = newnode;
	newnode->prev = fnode;
	newnode->next = nextNode;
}
void DLL_InsertBefore(NodeDLL* fnode, NodeDLL* newnode) {
	NodeDLL* prevNode = fnode->prev;
	prevNode->next = newnode;
	fnode->prev = newnode;
	newnode->prev = prevNode;
	newnode->next = fnode;
}
void DLL_Destroy(NodeDLL* head, NodeDLL* tail) {
	for (NodeDLL* curr = head->next; curr != tail;)
	{
		NodeDLL * nextNode = curr->next;
		free(curr);
		curr = nextNode;
	}
	head->next = tail;
	tail->prev = head;
}