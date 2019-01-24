#include <stdlib.h>
#include <stdio.h>

int binarySearchWrapper(int arr[], int num_of_elements, int find_this_num)
{
	return binarySearch(arr, num_of_elements, 0, find_this_num);
}

int binarySearch(int arr[], int upper_bound, int lower_bound, int find_this_num)
{
	if (upper_bound < lower_bound)
	{
		return -1;
	}
	else
	{
		int index = lower_bound + (upper_bound - lower_bound)/2;

		if (arr[index] == find_this_num)
		{
			return index;
		}
		else if (arr[index] > find_this_num)
		{
			binarySearch(arr, index-1, lower_bound, find_this_num);
		}
		else
		{
			binarySearch(arr, upper_bound, index+1, find_this_num);
		}
	}
}

int main (void)
{
	
	return 0;
}
