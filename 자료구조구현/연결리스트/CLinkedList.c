#include "CLinkedList.h"

void ListInit(List * _list)
{
	_list->numOfData = 0;
	_list->tail = NULL;
	_list->cur = NULL;
	_list->before = NULL;

	//��? ���������� cur�� before�� null�ʱ�ȭ�� ���ٱ�?

}

void ListInsert(List * _list, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;


	if (_list->tail == NULL)
	{
		_list->tail = newNode;
		newNode->next = _list->tail;
	}
	else//                    tail
	{	// [ 1 ] -- [ 3 ] -- [ 4 ]

		newNode->next = _list->tail->next;
		_list->tail->next = newNode;
		_list->tail = newNode;


	}
}


void ListInsertFront(List * _list, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (_list->tail == NULL)
	{
		_list->tail = newNode;
		newNode->next = _list->tail;
	}
	else
	{
		newNode->next = _list->tail->next;
		_list->tail->next = newNode;
	}
}

int ListFirst(List * _list, LData * data)
{
	if (_list->tail == NULL)
		return FALSE;
	
	// *data = _list->tail->next->data; �̷��� �ۼ�������, next���� ���谡 ��ƴ�. ������,
	_list->before = _list->tail;
	_list->cur = _list->tail->next;
	*data = _list->cur->data;

	return TRUE;

}

int ListNext(List * _list, LData * data)
{
	//if (_list->cur->next == NULL) // ?
	if (_list->tail == NULL) // �Ƹ� �̷��� �����ϴ� ������ �������� ��ȸ�ϴ� �������� ���� ��尡 ���� ��츦 �����ϱ� ���ؼ� �ε��ϴ�? ���� ���� ��ĵ� Ʋ���� �������ϴ�!
		return FALSE;

	_list->before = _list->cur;
	_list->cur = _list->cur->next;
	*data = _list->cur->data;
	return TRUE;
}

LData ListRemove(List * _list)
{
	Node* rPos = _list->cur;
	LData rData = rPos->data;

	if (rPos == _list->tail)
	{
		if (_list->tail == _list->tail->next)
			_list->tail = NULL;
		else
			_list->tail = _list->before;


	}

	_list->before->next = _list->cur->next;
	// _list->cur->next = NULL; �� cur�� �ϳ��� ����� ������. �̰��� ��带 ����Ű�� �ִ� ����! ������ ������ �Բ� cur�� �ڷ� ��ĭ �̵��ؾ��Ѵ�. ����,
	_list->cur = _list->before;

	free(rPos);
	_list->numOfData--;
	return rData;
}

int ListCount(List * _list)
{
	return _list->numOfData;
}
