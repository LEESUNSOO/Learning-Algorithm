#include <stdio.h>

//����Ž��
int BSearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) // �־��� ��� ������ 1�� ������ �������ٵ� �׶����� ���ٸ� first = mid+1; ��������  
	{					  // while���� ������ ����� �ȴ�. ������ '<='�� ����ؾ��Ѵ�.
		mid = (first + last) / 2;

		if (target == arr[mid])
		{
			return mid;
		}
		else
		{
			if (arr[mid] > target)
			{
				last = mid - 1;
			}
			else
				first = mid + 1;
			/*
				mid�� target�� ���� ���� ��� last = mid, first = mid�� ���� ���, �� ���� �����͸� �� �˻��һ� ? �� �ƴϴ�.
				first�� last�� ������ ���� ��� ���� while���� ��� �� ���� �ȴ�(first�� last���� Ŀ�� �� ����.)
			
			*/
		}


	}

	return -1;
	
}


int main()
{

	int arr[] = { 1,4,7,9,12,19,23,28,33,60 };
	int idx;
	idx = BSearch(arr, sizeof(arr) / sizeof(int), 8);

	printf("%d", idx);

	return 0;

}