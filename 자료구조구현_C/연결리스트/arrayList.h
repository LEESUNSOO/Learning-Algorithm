//#pragma once
//#ifndef __ARRAY_LIST_H__ //ifdef = if define -> ���� ���ǰ� �ƾ��ٸ�~ �̷� �������� ���ǰ� �� ��� �����Ǹ� ���� ���� ��ġ
//#define __ARRAY_LIST_H__ //ifndef�� not�� �ǹ̷� ���� �ʾҴٸ�~ �� �ǹ��ε� ifdef�� ����� ���ŷο��� �ٿ��ش�.
//						 //���� ��� ���� c���Ͽ� ���� ��������� �����Ǿ� �ִ� ��� ������ ������ �� �ֱ⶧���̴�.
//						 //ifdef�� ���, ���ǰ� �Ǿ��ִٸ� ifdef�� else ���� ������ ������ �������ϰ� 
//						 //���ǰ� �Ǿ����� ���� ���, else�� endif ���� ������ ������ �������Ѵ�.
//						 //���� ifndef(�ݴ��ǹ�)�� ����� ���, ���ǵ��� ���� ��쿡�� endif ������ ������ �������ϰ�
//						 //���ǵ� ���, else���ĸ� �������ϳ� ���ǵ� ��� �������� �ʿ䰡 ���⶧���� ���������ϴ�.
//
//#include "point.h"
////�ʿ� �Լ�
////1. �ʱ�ȭ - void ListInit(List* _list) : ����Ʈ�� �ּҰ��� �޾� �ʱ�ȭ�� �����Ѵ�.
////2. ������ �߰� - void ListInsert(List* _list, LData data) : data�� �޾� list�� �����Ѵ�.
////3. ������ ���� - int ListFirst(List* _list, LData* pdata) : list�� ù �����Ͱ� pdata�� ����ȴ�.
////3-1. ������ ���� - int ListNext(List* _list, LData* pdata) : list�� ù ������ ������ ������ ����ȴ�. 
////3)�� ��� ���� ������ Ȯ���� �� ������, �ݺ�ȣ���� �����ϰ� �ݺ����� �������� ���� ���, �׻� ListFirst�� ����Ǿ�� �Ѵ�.
////4. ������ ���� - LData ListRemove(List* _list, LData* pdata) : 
////5. ������ �� ����
//
////�ϴ� T/F �˻縦 �ϱ� ���� c++�� ��� Bool������ ����ϸ� ������ ����� c�̱� ������
//#define TRUE 1
//#define FALSE 0
//
////�迭�� ����� ����Ʈ�̱� ������ ũ�⸦ �������ְ�
//#define LIST_LEN 100
////�ӽ÷� int�ڷ����� ����Ʈ�� ������ ���·� �����Ѵ�(typedef�� ���� ����� ������ ���Ŀ� �ٸ� �ڷ����� �ٷ궧 �� �κи� �����ϴ� ����
//typedef Point* LData; // �߰�������ס�
//
//typedef struct __ArrayList		//28~36 typedef�� ������ �� �𸣰���
//{
//	LData arr[LIST_LEN];
//	int curPosition;
//	int numOfData;
//
//}ArrayList;
//
//typedef ArrayList List;
//
////�ʱ�ȭ
//void ListInit(List* plist);
////����
//void ListInsert(List* plist, LData data);
//
////��ȸ
//int ListFirst(List* plist, LData* pdata);
//int ListNext(List* plist, LData* pdata);
//
////����
//LData ListRemove(List* plist);
////�����ͼ� ��ȸ
//int ListCount(List* plist);
//
//#endif // !__ARRAY_LIST_H__
//
