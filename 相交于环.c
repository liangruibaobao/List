#include"LinkList.h"

Node *list1;
Node *list2;
int GetLength(Node *node)
{//算出链表的长度
	int count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
Node *Crossing(Node *list1, Node *list2)
{//求交点
	int length1 = GetLength(list1);
	int length2 = GetLength(list2);
	Node *longlist = list1;
	Node *shortlist = list2;
	int diff = length1 - length2;//两条链表的长度差
	if(length1<length2)
	{
		longlist = list2;
		shortlist = list1;
		diff = length2 - length1;
	}
	//让长链表先走，走到和短链表一样长
	while (diff--)
	{
		longlist = longlist->next;
	}
	//此时两条链表一样长，再让两条链表同时走
	//如果两条链表的结点相等则有交点
	//如果走完还无交点则无交点
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
{//删除一个无头单链表的非尾结点
	Node *next = node->next;
	node->data = next->data;
	node->next = next->next;
	free(next);
}
void InsertBeforeNode(Node *pos, DataType data)
{//在无头单链表的一个结点前插入一个结点
	Node *newnode = (Node*)malloc(sizeof(Node));//创建一个结点
	newnode->data = pos->data;//复制pos的data值
	newnode->next = pos->next;//将创建的结点插在pos的后面
	pos->data = data;//再将pos的data值改为要插入的值
	pos->next = newnode;//11改完之后的下一个结点的data仍是原来pos的data值
}
void JosephCircle(Node *first,int k)
{
	//构成环
	Node *cur = first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = first;
	//删除结点
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
	Node *node = FindTailK(list, k+1);//找到要删除结点的前一个结点
	if (node == NULL)
	{
		ListPopFront(&list);//如果要删除的结点的前一个结点为空则头删
	}
	else
	{
		Node *del = node->next;
		node->next = del->next;
		free(del);
	}
}