//#include <stdio.h>
//#include "arrayList.h"
//
//
//
//int main()
//{
//	//����
//	List list;
//	int data;
//	ListInit(&list);
//
//	//����
//	ListInsert(&list, 10);
//	ListInsert(&list, 10);
//	ListInsert(&list, 20);
//	ListInsert(&list, 20);
//	ListInsert(&list, 30);
//
//	//�����ͼ�
//	printf("���� ������ �� : %d \n", ListCount(&list));
//
//
//	//��ȸ
//	if (ListFirst(&list, &data))
//	{
//		printf("%d \n", data);
//
//		while (ListNext(&list, &data))
//		{
//			printf("%d \n", data);
//		}
//
//		printf("\n\n");
//	}
//
//	//����
//
//	if (ListFirst(&list, &data))
//	{
//		if (data == 20)
//		{
//			ListRemove(&list);
//		}
//		while (ListNext(&list, &data))
//		{
//			if (data == 20)
//			{
//				ListRemove(&list);
//			}
//		}
//	}
//
//
//	//�����ͼ�
//	printf("���� ������ �� : %d \n", ListCount(&list));
//
//
//	//���� �� ����ȸ
//	if (ListFirst(&list, &data))
//	{
//		printf("%d \n", data);
//
//		while (ListNext(&list, &data))
//		{
//			printf("%d \n", data);
//		}
//
//		printf("\n\n");
//	}
//
//
//
//
//	return 0;
//}