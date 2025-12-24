#pragma once
#ifndef __DLL_LIB_H__
#define __DLL_LIB_H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct _nodeDLL {
	ElementType Data;
	struct _nodeDll* next;
	struct _nodeDll* prev;

}NodeDLL;

NodeDLL * DLL_CreateNode(ElementType data);
void DLL_ApendNode(NodeDLL* tail, NodeDLL* newnode);
void DLL_PrintNode(NodeDLL* head, NodeDLL* tail);
void DLL_RemoveNode(NodeDLL* delnode);
NodeDLL* DLL_SearchNode(ElementType data, NodeDLL* head, NodeDLL* tail);
void DLL_InsertAfter(NodeDLL* fnode, NodeDLL* newnode);
void DLL_InsertBefore(NodeDLL* fnode, NodeDLL* newnode);
void DLL_Destroy(NodeDLL* head, NodeDLL* tail);

#endif