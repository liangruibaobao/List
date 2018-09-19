#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"
// ��ʼ��
void InitLinkList(Node **pplist)
{ 
	assert(pplist);
	pplist = NULL;
}
// ���� 
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
//�������
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
// β������ 
void ListPushBack(Node **pplist, DataType data)
{
	Node *node = CreateNode(data);//�ȴ������
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = node;
		return;
	}
		//�ҵ����һ�����
		Node *cur = *pplist;
		while (cur->next!=	NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
}
//ͷ������ 
void ListPushFront(Node **pplist, DataType data)
{
	assert(pplist);
	Node *newnode = CreateNode(data);
	newnode->next = *pplist;
	*pplist = newnode;
}
//β��ɾ��
void ListPopBack(Node **pplist)
{
	assert(pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else //������������㣬�����ҵ����ڶ������
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
// ͷ��ɾ�� 
void ListPopFront(Node **pplist)
{
	assert(pplist);
	assert(*pplist);//�����ǿ�����
	Node *cur = *pplist;
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}
// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
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
// ���������룬���뵽���ǰ 
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
		Node *newnode = CreateNode(data);//�������
		Node *cur = *pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode->next = pos;
		cur->next = newnode;
	}
}
// �������ɾ�� 
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
// ��ֵɾ����ֻɾ�����ĵ�һ�� 
void ListRemove(Node **pplist, DataType data)
{
	assert(pplist);
	Node *p = ListFind(pplist,data);
	ListErase(pplist, p);
}
// ��ֵɾ����ɾ�����е� 
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