#if 01
#include "DLL_lib.h"
int main(void) {
	NodeDLL* head;
	NodeDLL* tail;
	head = DLL_CreateNode(0);
	tail = DLL_CreateNode(0);
	head->next = tail;
	tail->prev = head;
	
	DLL_ApendNode(tail, DLL_CreateNode(10));
	DLL_ApendNode(tail, DLL_CreateNode(20));
	DLL_ApendNode(tail, DLL_CreateNode(30));
	DLL_ApendNode(tail, DLL_CreateNode(40));
	NodeDLL* node40 = tail->prev;
	DLL_ApendNode(tail, DLL_CreateNode(50));
	//printf("%d", DLL_SearchNode(40, head, tail)->Data);
	DLL_RemoveNode(DLL_SearchNode(30, head, tail));

	DLL_InsertAfter(node40, DLL_CreateNode(41));
	DLL_InsertBefore(node40, DLL_CreateNode(39));
	DLL_Destroy(head, tail);
	DLL_PrintNode(head, tail);

	return 0;

}

#endif