#include"LinkList.h"

Node *list1;
Node *list2;
int GetLength(Node *node)
{//�������ĳ���
	int count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
Node *Crossing(Node *list1, Node *list2)
{//�󽻵�
	int length1 = GetLength(list1);
	int length2 = GetLength(list2);
	Node *longlist = list1;
	Node *shortlist = list2;
	int diff = length1 - length2;//��������ĳ��Ȳ�
	if(length1<length2)
	{
		longlist = list2;
		shortlist = list1;
		diff = length2 - length1;
	}
	//�ó��������ߣ��ߵ��Ͷ�����һ����
	while (diff--)
	{
		longlist = longlist->next;
	}
	//��ʱ��������һ������������������ͬʱ��
	//�����������Ľ��������н���
	//������껹�޽������޽���
	while (1)
	{
		if (longlist == shortlist)
		{
			return longlist;
		}
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;

}
void NoHeadNotTail(Node *node)
{//ɾ��һ����ͷ������ķ�β���
	Node *next = node->next;
	node->data = next->data;
	node->next = next->next;
	free(next);
}
void InsertBeforeNode(Node *pos, DataType data)
{//����ͷ�������һ�����ǰ����һ�����
	Node *newnode = (Node*)malloc(sizeof(Node));//����һ�����
	newnode->data = pos->data;//����pos��dataֵ
	newnode->next = pos->next;//�������Ľ�����pos�ĺ���
	pos->data = data;//�ٽ�pos��dataֵ��ΪҪ�����ֵ
	pos->next = newnode;//11����֮�����һ������data����ԭ��pos��dataֵ
}
void JosephCircle(Node *first,int k)
{
	//���ɻ�
	Node *cur = first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = first;
	//ɾ�����
	cur = first;
	while (cur->next != cur)
	{
		Node *prev = NULL;
		for (int i = 0; i < k - 1; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	printf("%d\n", cur->data);
}
void Merge(Node *list1, Node *list2)
{
	Node *cur1 = list1;
	Node *cur2 = list2;
	Node *node;
	Node *tail = NULL;
	Node *result = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			node = cur1;
			cur1 = cur1->next;

			if (tail == NULL)
			{
				result = node;
			}
			else
			{
				tail->next = node;
			}
			node->next = NULL;
			tail = node;
		}
		else
		{
			node = cur2;
			cur2 = cur2->next;
			if (result == NULL)
			{
				tail = node;
			}
			else
			{
				tail->next = node;
			}
			node->next = NULL;
			tail = node;
		}
	}
	if(cur1!=NULL)
	{
		tail->next = cur1;
	}
	if (cur2 != NULL)
	{
		tail->next = cur2;
	}
	PrintLinkList(&result);
}
Node *FindMid(Node *list)
{
	Node *fast = list;
	Node *slow = list;
	while (fast)
	{
		if (fast->next != NULL)
		{
			fast = fast->next->next;
		}
		else
		{
			break;
		}
		slow = slow->next;
	}
	return slow;
}
Node *FindTailK(Node *list, int k)
{
	Node *forward = list;
	Node *backward = list;
	while (--k)
	{
		forward = forward->next;
	}
	while (forward->next)
	{
		forward = forward->next;
		backward = backward->next;
	}
	return backward;
}
void DelTailK(Node *list, int k)
{
	Node *node = FindTailK(list, k+1);//�ҵ�Ҫɾ������ǰһ�����
	if (node == NULL)
	{
		ListPopFront(&list);//���Ҫɾ���Ľ���ǰһ�����Ϊ����ͷɾ
	}
	else
	{
		Node *del = node->next;
		node->next = del->next;
		free(del);
	}
}