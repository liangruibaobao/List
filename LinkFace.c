#include"LinkList.h"
//void TailPrint(Node *first)
//{//��β��ͷ��ӡ����
//	Node *last = NULL;//��¼���һ��Ԫ�ص�λ��
//	Node *cur = first;
//	while (last!=first)
//	{ 
//		cur = first;//�����ر�ע�⣬ÿ�ζ�Ҫ����cur
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
//{//����/��ת������
//	Node *new = NULL;
//	Node *cur = first;//һֱָ��ԭ����ĵ�һ�����
//	Node *node;
//	while (cur != NULL)
//	{
//		//��ԭ����ͷɾ
//		node = cur;
//		cur = cur->next;
//		//ͷ�嵽�½��
//		node->next = new;
//		new = node;
//	}
//	first = new;//��ͷ�����Ľ��Ż�������
//	PrintLinkList(&first);//������ɺ��ӡ
//}
//void ReverseList(Node *first)
//{//����/��ת������
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
//	PrintLinkList(&p1);//������ɺ��ӡ
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


