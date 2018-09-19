#include"LinkList.h"
Node *list1;
Node *list2;
//void test()
//{
//	InitLinkList(&list2);
//	ListPushBack(&list2, 1);
//	ListPushBack(&list2, 3);
//	ListPushBack(&list2, 5);
//	ListPushBack(&list2, 7);
//	ListPushBack(&list2, 9);
//	PrintLinkList(&list2);
//	/*ListPopBack(&list);
//	PrintLinkList(&list);
//	ListPopFront(&list);
//	PrintLinkList(&list);*/
//	
//	/*ListInsert(&list, p, 7);
//	PrintLinkList(&list);*/
//	/*Node *p = ListFind(&list,4);
//	ListErase(&list, p);
//	PrintLinkList(&list); */
//	/*ListRemove(&list, 3);
//	PrintLinkList(&list);*/
//	ListRemoveAll(&list, 3);
//	PrintLinkList(&list);
//
//
//}
//void test1()
//{
//	InitLinkList(&list);
//	ListPushFront(&list, 1);
//	ListPushFront(&list, 2);
//	ListPushFront(&list, 3);
//	ListPushFront(&list, 4);
//	ListPushFront(&list, 5);
//	ListPushFront(&list, 6);
//	PrintLinkList(&list);
//
//}
void test2()
{
	InitLinkList(&list1);
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 5);
	ListPushBack(&list1, 7);
	ListPushBack(&list1, 9);
	//PrintLinkList(&list1);
	InitLinkList(&list2);
	ListPushBack(&list2, 2);
	ListPushBack(&list2, 4);
	ListPushBack(&list2, 6);
	ListPushBack(&list2, 8);
	ListPushBack(&list2, 10);
	//PrintLinkList(&list2);
	Merge(list1, list2);

	//JosephCircle(list, 3);
	//ReverseList(list);
	//TailPrint(list);

}
void test9()
{
	InitLinkList(&list1);
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 5);
	ListPushBack(&list1, 6);
	ListPushBack(&list1, 7);
	ListPushBack(&list1, 8);
	ListPushBack(&list1, 9);
	ListPushBack(&list1, 10);
	PrintLinkList(&list1);
	//Node *p = FindTailK(list1, 3);
	//printf("%d\n", p->data);
	DelTailK(list1, 3);
	PrintLinkList(&list1);

}
void testCN()
{
	InitCN();
}

int main()
{
	
	test9();
	//testCN();
	return 0;
}