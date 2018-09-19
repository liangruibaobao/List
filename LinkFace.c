#include"LinkList.h"
//void TailPrint(Node *first)
//{//从尾到头打印链表
//	Node *last = NULL;//记录最后一个元素的位置
//	Node *cur = first;
//	while (last!=first)
//	{ 
//		cur = first;//这里特别注意，每次都要更新cur
//		while (cur->next != last)
//		{
//			cur = cur->next;
//		}
//			printf("%d-->", cur->data);
//			last = cur;
//	}
//	printf("NULL");
//	printf("\n");
//}
//void TailPrint(Node *first)
//{
//	Node *cur = first;
//	if (cur->next != NULL)
//	{
//		TailPrint(cur->next);
//		printf("%d-->", cur->data);
//	}
//	else
//	{
//		printf("%d-->", cur->data);
//	}
//}
//void ReverseList(Node *first)
//{//逆置/反转单链表
//	Node *new = NULL;
//	Node *cur = first;//一直指向原链表的第一个结点
//	Node *node;
//	while (cur != NULL)
//	{
//		//从原链表头删
//		node = cur;
//		cur = cur->next;
//		//头插到新结点
//		node->next = new;
//		new = node;
//	}
//	first = new;//将头插完后的结点放回链表中
//	PrintLinkList(&first);//逆置完成后打印
//}
//void ReverseList(Node *first)
//{//逆置/反转单链表
//	if (first == NULL && first->next == NULL)
//	{
//		return;
//	}
//	Node *p1 = NULL;
//	Node *p2 = first;
//	Node *p3 = first->next;
//	while (p2!=NULL)
//	{
//		p2->next = p1;
//		p1 = p2;
//		p2 = p3;
//		if (p3 != NULL)
//		{
//			p3 = p3->next;
//		}
//	}
//	PrintLinkList(&p1);//逆置完成后打印
//}
typedef struct  ComplexNode
{
	int data;
	struct ComplexNode *next;
	struct ComplexNode *random;
}CN;
CN *CreateNode(int data)
{
	CN *node = (CN*)malloc(sizeof(CN));
	node->data = data;
	node->random = node->next = NULL;
	return node;
}
void InitCN()
{
	CN *n1 = CreateNode(1);
	CN *n2 = CreateNode(2);
	CN *n3 = CreateNode(3);
	CN *n4 = CreateNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	return n1;
}


