/*
此问题相当于寻找第k = （（nums1Size + nums2Size + 1） / 2）大的数
在第一次搜索的时候，当且仅当nums1[k / 2 - 1] == nums2[k / 2 - 1] 是，算是找到了这个数
用point1, point2来标识当找到的时候在nums1和nums2的位置，
如果nums1[(k + 1) / 2 - 1] < nums2[(k + 1) / 2 - 1],则说明真正找到的时候，p > (k + 1) / 2 - 1, q < (k + 1) / 2 - 1，
那么就可以把nums1中的前面k / 2个元素全部删掉，重新递归寻找（每次都当作第一次寻找）
*/


#include <stdio.h>

int max(int a, int b)
{
	if (a < b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int find_kth_number(int *start_pointer1, int length1, int *start_pointer2, int length2, int k)
{
	int middle1, middle2;
	if (0 == length1)
	{
		return *(start_pointer2 + k - 1);
	}

	if (0 == length2)
	{
		return *(start_pointer1 + k - 1);
	}

	if (1 == k)
	{
		if (*start_pointer1 > *start_pointer2)
		{
			return *start_pointer2;
		}
		else
		{
			return *start_pointer1;
		}
	}

	if (2 == k)
	{
		if (start_pointer1[0] > start_pointer2[0])
		{
			if (1 < length2)
			{
				return min(start_pointer1[0], start_pointer2[1]);
			}
			else
			{
				return start_pointer1[0];
			}
		}
		else if (start_pointer1[0] == start_pointer2[0])
		{
			return start_pointer1[0];
		}
		else
		{
			if (1 < length1)
			{
				return min(start_pointer2[0], start_pointer1[1]);
			}
			else
			{
				return start_pointer2[0];
			}
		}
	}

	if (1 == length1)
	{
		if (start_pointer1[0] >= start_pointer2[k - 1])
		{
			return start_pointer2[k - 1];
		}
		else
		{
			return max(start_pointer2[k - 2], start_pointer1[0]);
		}
	}

	if (1 == length2)
	{
		if (start_pointer2[0] >= start_pointer1[k - 1])
		{
			return start_pointer1[k - 1];
		}
		else
		{
			return max(start_pointer2[0], start_pointer1[k - 2]);
		}
	}

	if ((length1 >= (k + 1) / 2) && (length2 >= (k + 1) / 2))
	{
		if (*(start_pointer1 + (k + 1) / 2 - 1) == *(start_pointer2 + (k + 1) / 2 - 1))
		{
			return *(start_pointer1 + (k + 1) / 2 - 1);
		}

		if (*(start_pointer1 + (k + 1) / 2 - 1) < *(start_pointer2 + (k + 1) / 2 - 1))
		{
			return find_kth_number(start_pointer1 + (k + 1) / 2 - 1, length1 - (k + 1) / 2 + 1, start_pointer2, length2, k - (k + 1) / 2 + 1);
		}

		if (*(start_pointer1 + (k + 1) / 2 - 1) > *(start_pointer2 + (k + 1) / 2 - 1))
		{
			return find_kth_number(start_pointer1, length1, start_pointer2 + (k + 1) / 2 - 1, length2 - (k + 1) / 2 + 1, k - (k + 1) / 2 + 1);
		}
	}
	else
	{
		if (length1 < (k + 1) / 2)
		{
			//middle1 = (length1 + 1) / 2;
			middle1 = length1;
			middle2 = k - middle1;
		}
		else
		{
			//middle2 = (length2 + 1) / 2;
			middle2 = length2;
			middle1 = k - middle2;
		}
		if (*(start_pointer1 + middle1 - 1) == *(start_pointer2 + middle2 - 1))
		{
			return *(start_pointer1 + middle1 - 1);
		}
		
		if (*(start_pointer1 + middle1 - 1) < *(start_pointer2 + middle2 - 1))
		{
			return find_kth_number(start_pointer1 + middle1 - 1, length1 - middle1 + 1, start_pointer2, length2, k - middle1 + 1);
		}
		
		if (*(start_pointer1 + middle1 - 1) > *(start_pointer2 + middle2 - 1))
		{
			return find_kth_number(start_pointer1, length1, start_pointer2 + middle2 - 1, length2 - middle2 + 1, k - middle2 + 1);
		}
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	double median;
	int k, left, right;
	k = (nums1Size + nums2Size + 1) / 2;

	if (0 != (nums1Size + nums2Size) % 2)
	{
		median = find_kth_number(nums1, nums1Size, nums2, nums2Size, k);
	}
	else
	{
		left = find_kth_number(nums1, nums1Size, nums2, nums2Size, k);
		right = find_kth_number(nums1, nums1Size, nums2, nums2Size, k + 1);
		median = (left + right) / 2.0;
	}
	return median;
}

int main()
{
	int nums1Size, nums2Size, i;
	int nums1[10], nums2[10];
	double median;
	scanf_s("%d%d", &nums1Size, &nums2Size);
	for (i = 0; i < nums1Size; i++)
	{
		scanf_s("%d", nums1 + i);
	}
	for (i = 0; i < nums2Size; i++)
	{
		scanf_s("%d", nums2 + i);
	}
	median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	printf("%f", median);
	getchar();
	getchar();
	return 0;
}