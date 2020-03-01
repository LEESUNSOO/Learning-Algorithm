#include "linkedList.h"

void ListInit(List * _list)
{
	_list->head = (List*)malloc(sizeof(List)); //���̳�����
	_list->head->next = NULL;
	_list->comp = NULL;
	_list->numOfData = 0;
}

void ListInsert(List * _list, LData data)
{
	if (_list->comp == NULL)
	{
		FInsert(_list, data);
	}
	else
		SInsert(_list, data);

}

void FInsert(List* _list, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = _list->head->next;
	_list->head->next = newNode;

	_list->numOfData++;

}

void SInsert(List* _list, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = _list->head;
	newNode->data = data;

	// head & pred��  ex ) data = 4
	//	     [dummy] -- [ 1 ] -- [ 3 ] -- [ 5 ] --~

	while (pred->next != NULL && _list->comp(data, pred->next->data) == 0)
	{
		pred = pred->next; //���⼭ pred�� �̵��ȴ� (��Ȯ���� ����Ű�� ����� �ּҰ� ����ȴ�)
	}

	newNode->next = pred->next; //�׷��� ������ ���ο� ���� while���� ���������� ��, data������ ū ����� �����Ͱ��� ������ ��, pred�� [ 3 ] �� ����Ű�� �ִ�
	pred->next = newNode; // ������ ���ο� ���� pred->next�� [ 5 ]�� ����Ű�� �ǰ� pred�� 3�� ���ο� ��带 ����Ű�� �ȴ�.

	_list->numOfData++;

}

int ListFirst(List * _list, LData * data)
{


	if (_list->head->next == NULL)
		return FALSE;

	_list->cur = _list->head->next;
	_list->before = _list->head;

	*data = _list->cur->data;
	return TRUE;
	
}

int ListNext(List * _list, LData * data)
{
	_list->before = _list->cur;
	_list->cur = _list->cur->next;

	if (_list->cur == NULL)
		return FALSE;

	*data = _list->cur->data;
	return TRUE;
}

LData ListRemove(List * _list)
{
	Node* rPos = _list->cur;
	LData data = rPos->data;


	_list->before->next = rPos->next;
	_list->cur = _list->before;

	free(rPos);
	_list->numOfData--;

	return data;
}

int ListCount(List * _list)
{
	return _list->numOfData;
}

void setSortRule(List * _list, int(*comp)(LData, LData))
{
	_list->comp = comp;
}
