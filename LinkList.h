#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// ֵ���� 
typedef int DataType;
//����Ľṹ
typedef struct Node {
	DataType data; // ������ 
	struct Node *next; // ָ����ָ����һ����� 
}Node;

// ��ʼ�� 
void InitLinkList(Node **pplist);

//��ӡ����
void PrintLinkList(Node **pplist);

// β������ 
void ListPushBack(Node **pplist, DataType data);

 //ͷ������ 
void ListPushFront(Node **pplist, DataType data);

// β��ɾ�� 
void ListPopBack(Node **pplist);

// ͷ��ɾ�� 
void ListPopFront(Node **pplist);

// ���������룬���뵽���ǰ 
void ListInsert(Node **pplist, Node *pos, DataType data);

// �������ɾ�� 
void ListErase(Node **pplist, Node *pos);

// ��ֵɾ����ֻɾ�����ĵ�һ�� 
void ListRemove(Node **pplist, DataType data);

// ��ֵɾ����ɾ�����е� 
void ListRemoveAll(Node **pplist, DataType data);

//// ���� 
//void DestroyLinkList(pNode *pplist);
//
// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
Node *ListFind(Node **pplist, DataType data);

#endif // !__LINKLIST_H__
