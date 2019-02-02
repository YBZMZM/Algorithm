//==================================================================
// Merge Sort
// ���ߣ�ZYZMZM
// ˼·�����η���һ���ǳ����͵�Ӧ�á���������������кϲ����õ���
//       ȫ��������У�����ʹÿ��������������ʹ�����жμ�����
//==================================================================

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

bool IsVaild = false;  // ��־�Ƿ�Ϊ��������

void Merge(int *arr, int length, int gap)
{
	int *brr = (int *)malloc(sizeof(int) * length);
	assert(brr != NULL);

	int start1 = 0;
	int end1 = start1 + gap - 1;
	int start2 = end1 + 1;
	int end2 = start2 + gap - 1 > length - 1 ? length - 1 : start2 + gap - 1;

	int i = 0;
	while (start2 < length)
	{
		while (start1 <= end1 && start2 <= end2)
		{
			if (arr[start1] <= arr[start2])
			{
				brr[i++] = arr[start1++];
			}
			else
			{
				brr[i++] = arr[start2++];
			}
		}

		while (start1 <= end1)
		{
			brr[i++] = arr[start1++];
		}
		while (start2 <= end2)
		{
			brr[i++] = arr[start2++];
		}

		start1 = end2 + 1;
		end1 = start1 + gap - 1;
		start2 = end1 + 1;
		end2 = start2 + gap - 1 > length - 1 ? length - 1 : start2 + gap - 1;
	}

	while (start1 < length)
	{
		brr[i++] = arr[start1++];
	}
	for (int i = 0; i < length; i++)
	{
		arr[i] = brr[i];
	}
}


void Merge_Sort(int *arr, int length)
{
	IsVaild = false;

	if (arr == NULL || length <= 0)
	{
		return;
	}

	for (int i = 1; i < length; i *= 2)
	{
		Merge(arr,length,i);
	}

	IsVaild = true;
}

// ====================Test Code====================

void Sort(int *arr, int length)
{
	Merge_Sort(arr,length);
	if (IsVaild)
	{
		for (int i = 0; i < length; i++)
		{
			printf("%d  ",arr[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Input is InVaild\n");
	}
}


void Test1()
{
	int arr[] = {3,1,5,2,7,6,9,3,7,0};
	int length = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,length);
}

void Test2()
{
	int arr[] = {1,2,3,4,5,9,8,7,6,0};
	int length = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,length);
}

void Test3()
{
	int arr[] = {4,3,5,6,7,8,9,0,1,2};
	int length = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,length);
}

void Test4()
{
	int *arr = NULL;
	Sort(arr,0);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
}