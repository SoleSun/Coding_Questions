#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
		//Create two iterators at the front and end
    	int max = 0;

    	if (height.size() > 1)
    	{
	    	int low  = 0, 
	    	    high = height.size()-1;

	    	while(low < high) 
	    	{
	    		// The smaller of the two heights form the max height
	    		int width = height[high] < height[low] ? 
	    		            height[high]               :
	    		            height[low];

	    		int area  = (high - low) * (width);
	    		max = max < area ? area : max;

	    		if(height[low] < height[high])
	    		{ 
	    			low++;
	    		}
	    		else
	    		{
	    			high--;
	    		}
	    	}
    	}
		return max;            
    }
};

int main(void)
{
	return 0;
}