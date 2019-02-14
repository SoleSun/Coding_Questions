#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int trap(vector<int>& height) {
        int volume = 0;
        // Need at least two walls to define a volume 
        if(height.size() > 2)
        {
        	// currentLevel represents the current water table
        	int low          = 0;
            int high         = height.size()-1;
        	int currentLevel = 0; // the maximum height that can be currently contained 
                                  // between the walls
            int prevCurrLev  = 0; // the previously maximum height
        	int minHeight    = 0; // the smaller height between the two iterators

        	while (low < high)
        	{
        		int subtractor;
        		// The lower of the two heights represents the water table
			    minHeight = height[low] <= height[high] ?
					    height[low]                 :
						height[high];
                
                // If the height of the walls 
       			if(minHeight > currentLevel)
       			{
       				// Subtract the height differential of the current block
   					// from the water table
					subtractor   = currentLevel;
       				prevCurrLev  = currentLevel;
       				currentLevel = minHeight;

                    volume += ((high - low - 1) * (minHeight - prevCurrLev));
       			} 
       			else
       			{
       				subtractor = minHeight;
       			}

       			// Subtract the height differential of the current block
				// from the water table
				volume = volume - subtractor >= 0 ?  
		                 volume - subtractor      :
		                 0;

       			if (height[low] <= height[high]) 
   				{
   					low++;
   				}
       			else 
   				{
   					high--;
   				}

        	}
        }

        return volume;
    }
};

int main(void)
{
	vector<int> test1 {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> test2 {0,1,0,2,1};
    vector<int> test3 {3,2,0,4,1,6,1,0,1};
    vector<int> test4 {1};
	Solution sol;

	std::cout << sol.trap(test1) << std::endl;
	std::cout << sol.trap(test2) << std::endl;
    std::cout << sol.trap(test3) << std::endl;
    std::cout << sol.trap(test4) << std::endl;

	return 0;
}