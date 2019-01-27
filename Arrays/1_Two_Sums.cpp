#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
  		std::vector<int> result;
  		// User a hash map to leverage the search. Find the complement 
  		std::unordered_map<int, int> complements;

  		for (unsigned int i = 0; i < nums.size(); i++)
  		{	
  			// The complement exists 
  			if(complements.find(nums[i]) != complements.end())
  			{
  				// so add the current index and the index 
  				// where the other element is stored
  				result.push_back(complements[nums[i]]);
  				result.push_back(i);
  			}
  			else
  			{
  				// Store the complement and the index it resides
  				complements.insert({target-nums[i],i});
  			}
  		}

  		return result;
    }
};

int main(void)
{
	std::vector<int> test = {1,5,5,11};

	Solution sol;
	std::vector<int> result = sol.twoSum(test, 10);

	for (unsigned int i = 0; i < result.size(); i++)
		std::cout << result[i] << std::endl;
	return 0;
}