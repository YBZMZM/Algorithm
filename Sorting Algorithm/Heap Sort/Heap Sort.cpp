//==================================================================
// Heap sort
// ���ߣ�ZYZMZM
// ˼·������-��������ѡ���β���������жѵ���
//==================================================================

#include <stdio.h>

bool IsVaild = false;  // ��־�Ƿ�Ϊ��������

void HeapAdjust(int *arr , int start , int end)  
{
	int temp = arr[start];
	for (int i = start * 2 + 1; i < end; i = i * 2 + 1)
	{
		if (i < end - 1 && arr[i] < arr[i + 1])
		{
			i++;
		}
		if (arr[start] < arr[i])
		{
			arr[start] = arr[i];
			start = i;
		}
		else
		{
			break;
		}
		arr[i] = temp;
	}
}


void Heap_sort(int *arr, int length)
{
	IsVaild = false;

	if (arr == NULL || length <= 0)
	{
		return;
	}

	for (int i = length / 2; i >= 0; i--)	// ��ʼ��Ԫ��Ϊ�����
	{
		HeapAdjust(arr, i, length);
	}

	for (int i = length - 1; i > 0; i--)  // ��β�������ѵ���
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		HeapAdjust(arr, 0 ,i);
	}

	IsVaild = true;
}

// ====================Test Code====================

void Sort(int *arr, int length)
{
	Heap_sort(arr,length);
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
