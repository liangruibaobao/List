#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// 值类型 
typedef int DataType;
//链表的结构
typedef struct Node {
	DataType data; // 数据域 
	struct Node *next; // 指针域，指向下一个结点 
}Node;

// 初始化 
void InitLinkList(Node **pplist);

//打印链表
void PrintLinkList(Node **pplist);

// 尾部插入 
void ListPushBack(Node **pplist, DataType data);

 //头部插入 
void ListPushFront(Node **pplist, DataType data);

// 尾部删除 
void ListPopBack(Node **pplist);

// 头部删除 
void ListPopFront(Node **pplist);

// 给定结点插入，插入到结点前 
void ListInsert(Node **pplist, Node *pos, DataType data);

// 给定结点删除 
void ListErase(Node **pplist, Node *pos);

// 按值删除，只删遇到的第一个 
void ListRemove(Node **pplist, DataType data);

// 按值删除，删除所有的 
void ListRemoveAll(Node **pplist, DataType data);

//// 销毁 
//void DestroyLinkList(pNode *pplist);
//
// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
Node *ListFind(Node **pplist, DataType data);

#endif // !__LINKLIST_H__
