#include <stdio.h>

int findMissingNumber(int arr[], int upper_bound, int lower_bound)
{
	int index = lower_bound + (upper_bound - lower_bound)/2;
	int order = arr[index] - arr[0];

	if (upper_bound == lower_bound)
	{
		return order == index ? arr[index]+1 : arr[index]-1;
	}

	if (order == index)
	{
		return findMissingNumber(arr, upper_bound, index+1);
	}
	else if (order > index)
	{
		return findMissingNumber(arr, index, lower_bound);
	}
	else
	{
	    return 0; //should never reach here
	}
}

int findMissingNumberWrapper(int arr[], int num_of_elements)
{
	//if the maximum element is in the order it should be
	//   or there are no elements
	if (!num_of_elements || 
	    arr[num_of_elements] - arr[0] == num_of_elements)
	{
		//then there are no missing elements so return -1
		return 0;
	}
	//otherwise, find the missing number
	else
	{
		return findMissingNumber(arr, num_of_elements-1, 0);
	}
}

int main(void)
{
	int arr1[7] = {1,2,3,4,6,7,8};
	int arr2[7] = {10,11,13,14,15,16,17};
	int arr3[20] = {1,3,4,5,6,7,8,9,10,11,
                    12,13,14,15,16,17,18,19,20,21};
	int arr4[4][5] = {{4,6,7,8,9},
                      {4,5,7,8,9},
                      {4,5,6,8,9},
                      {4,5,6,7,9}};

	int arr5[5][6] = {{1,3,4,5,6,7},
         			  {1,2,4,5,6,7},
                      {1,2,3,5,6,7},
                      {1,2,3,4,6,7},
                      {1,2,3,4,5,7}};
    
    int arr6[3] = {1,3};               

	printf("arr1 is missing %d\n", findMissingNumberWrapper(arr1,7));
	printf("arr2 is missing %d\n", findMissingNumberWrapper(arr2,7));
	printf("arr3 is missing %d\n", findMissingNumberWrapper(arr3,20));
	for (int i = 0; i < 4; i++)
		printf("arr is missing %d\n", findMissingNumberWrapper(arr4[i],5));
	for (int i = 0; i < 5; i++)
		printf("arr is missing %d\n", findMissingNumberWrapper(arr5[i],6));

	printf("arr6 is missing %d\n", findMissingNumberWrapper(arr6,2));
	return 0;
}
