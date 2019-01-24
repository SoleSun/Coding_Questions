// Given a sorted positive consecutive integer array that is rotated to the right n times,
// write a function to find how many times it as been rotated What is the time complexity
// of your function and can you improve it?

// Use binary search to determine the minimum rotations:
// * If the current element is less than the first element, then the minimum lies in the left half.
// * Else, then search the right half

#include <stdio.h>

int countRotations(int arr[], int low, int high)
{
	// High can never be lower than low 
	if (high < low)
	{
		return -1;
	}

	// check for same indexed arrays
	if (high == low)
	{
		return low;
	}

	int mid = low + (high - low) / 2;

	if (mid < high && arr[mid] < arr[mid+1])
	{
		return mid+1;
	}
	if (mid > low && arr[mid] < arr[mid-1])
	{
		return mid;
	}

	return arr[mid] > arr[low] ?
           countRotations(arr, mid+1, high) :
           countRotations(arr, low, mid-1);
}


