//#include <stdio.h>
//
//
//int RBSearch(int arr[], int first, int last, int target) //��ͷ� �����Կ� ���� ������ �Ǿ��� first�� last�� ���� ������ ����������Ѵ�.
//{
//
//	int mid = (first + last) / 2;
//
//	if (first > last)
//		return -1;
//
//	if (arr[mid] == target)
//	{
//		return mid;
//	}
//	else if (arr[mid] > target)
//	{
//		RBSearch(arr, 0, mid - 1, target);
//	}
//	else
//		RBSearch(arr, mid+1, last, target);
//}
//
//
//
//int main()
//{
//	int arr[] = { 1,3,5,7,9,11,15,19,24 };
//	int idx = RBSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 14);
//	printf("%d", idx);
//
//	return 0;
//}