#include <vector>

class Solution {
public:
	/* 
		O(log(n) + log(m))
	 	Consider first the case of where there are odd total elements. 
		 	The strategy is to perform a binary search for an element in one of the arrays:
		 	Say you start with the element in arr1 at index i. Then you already know that 
		 	element i is already greater than i elements since the array is sorted.
		 	For element i to be the median however in arr2, it must have j elements greater
		 	and less than it, where 
			j = ((arr1.size() + arr2.size()) / 2) - i.
			i.e. do a constant time search where arr2[j-1] <= arr1[i] <= arr[j];

		If the element isn't found in one array then the iterator is simply pointed to the
		other array. 

		In the even case, a median is the average of the two elements that have 
		(arr1.size() + arr2.size() - 2) / 2 elements surrounding them. 
	*/ 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double median = -1;

        if (nums1.size() != 0 && nums2.size() != 0)
        {
            bool even = (nums1.size() + nums2.size()) % 2 == 0;
            median = FMSARecurse(nums1, nums2, nums1.size(), 0, even);
            
            // if the median wasn't found in the first array
            if (median == -1)
            {
                // then searh the second array 
                median = FMSARecurse(nums2, nums1, nums2.size(), 0, even);
            }
        }
        else if (nums1.size() != 0)
        {
            median = nums1.size() % 2 == 0 ? 
                     (nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1]) / 2 :
                     nums1[nums1.size()/2];
        }
        else if (nums2.size() != 0)
        {
            median = nums2.size() % 2 == 0 ? 
                     (nums2[nums2.size()/2] + nums2[nums2.size()/2 - 1]) / 2 :
                     nums2[nums2.size()/2];
        }

        return median;
    }

    /** 
     * Recursive helper function for performing binary search. Array nums1 is 
     * searched and compared with nums2. Returns the median of the two arrays
     */
    double FMSARecurse(vector<int>& nums1, vector<int>& nums2, int high, int low, bool even)
    {
        double median; 
    	int i = low + (high - low)/2;
    	int j = (nums1.size() + nums2.size())/2 - i;

        // if the total number of elements is even, then there is one less
        // element that must be less than the number at index i of array 1.
        if (even) j--;
    	
    	// Base case
    	// If the high and low boundaries cross then there is median in this array 
    	if (low > high)
    	{
    		return -1; 
    	}

    	// Do a check 
    	if (nums1[i] >= nums2[j-1] && nums1[i] <= nums2[j])
    	{
            // if the number is even then the number to be averaged can either be
            // located in j or i+1, so take the lesser of the two and return the average
            // otherwise, the median is just the number at i
            median = even ? 
                     (nums1[i] + min(nums1[i+1], nums2[j]) ) / 2 :
                     nums1[i];
    	}
    	else if (nums1[i] >= nums2[j-1])
    	{
    		// The number in index i is too large to the median so search the left half
    		median = FMSARecurse(nums1, nums2, i - 1, low, even);
    	}
    	else
    	{
    		// The number in index i is too small to the median so search the right half
    		median = FMSARecurse(nums1, nums2, high, i + 1, even);	
    	}

        return median;
    }

    int min(int x, int y)
    {
        return x < y ? x : y;
    }
};

int main(void)
{
	vector<int> arr1 {1,4,5,6};
	vector<int> arr2 {0,6,7};
}