#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"
// 初始化
void InitLinkList(Node **pplist)
{ 
	assert(pplist);
	pplist = NULL;
}
// 销毁 
void DestroyLinkList(Node **pplist)
{
	assert(pplist);
	Node *cur=*pplist;
	Node *next;
	while (cur!= NULL)
	{
		next = cur->next;
		free(cur);
		cur=next;
	}
}
//创建结点
static Node*  CreateNode(DataType data)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("CreateNode::malloc");
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void PrintLinkList(Node **pplist)
{
	Node *cur = *pplist;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 尾部插入 
void ListPushBack(Node **pplist, DataType data)
{
	Node *node = CreateNode(data);//先创建结点
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = node;
		return;
	}
		//找到最后一个结点
		Node *cur = *pplist;
		while (cur->next!=	NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
}
//头部插入 
void ListPushFront(Node **pplist, DataType data)
{
	assert(pplist);
	Node *newnode = CreateNode(data);
	newnode->next = *pplist;
	*pplist = newnode;
}
//尾部删除
void ListPopBack(Node **pplist)
{
	assert(pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else //至少有两个结点，才能找倒数第二个结点
		{
		Node *cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
// 头部删除 
void ListPopFront(Node **pplist)
{
	assert(pplist);
	assert(*pplist);//链表不是空链表
	Node *cur = *pplist;
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}
// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
Node *ListFind(Node **pplist, DataType data)
{
	assert(pplist);
	Node *cur = *pplist;
	while (cur->next != NULL)
	{
		if (cur->data == data)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
// 给定结点插入，插入到结点前 
void ListInsert(Node **pplist, Node *pos, DataType data)
{
	assert(pplist);
	if (pos == *pplist)
	{
		ListPushFront(pplist, data);
		return;
	}
	else
	{
		Node *newnode = CreateNode(data);//创建结点
		Node *cur = *pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode->next = pos;
		cur->next = newnode;
	}
}
// 给定结点删除 
void ListErase(Node **pplist, Node *pos)
{
	assert(pplist);
	if (pos == *pplist)
	{
		ListPopFront(pplist);
		return;
	}
	else
	{
		Node* cur = *pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}
// 按值删除，只删遇到的第一个 
void ListRemove(Node **pplist, DataType data)
{
	assert(pplist);
	Node *p = ListFind(pplist,data);
	ListErase(pplist, p);
}
// 按值删除，删除所有的 
void ListRemoveAll(Node **pplist, DataType data)
{
	assert(pplist);
	Node *cur = *pplist;
	Node *pre = *pplist;
	while (cur != NULL)
	{
		if (data == cur->data)
		{
			Node *del = cur;
			cur = cur->next;
			if (del == *pplist)
			{
				ListPopFront(pplist);
			}
			else if (del->next == NULL)
			{
				ListPopBack(pplist);
			}
			else
			{
				pre->next = del->next;
				free(del);
			}
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}