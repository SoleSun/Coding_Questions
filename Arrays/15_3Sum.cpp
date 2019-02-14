#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std; 
bool compareVector (const int i, const int j) {return i < j;}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
		if(nums.size() > 2)
        {
            sort(nums.begin(), nums.end(), compareVector);
            vector<int> sorted = nums;

            for (int i = 0; i < sorted.size()-2; i++)
            {
                if (i == 0 || (i>0 && sorted[i] != sorted[i-1]))
                {
                    int low  = i + 1,
                    high = sorted.size() - 1,
                    sum  = 0 - sorted[i];
                    while(low < high)
                    {
                        if(sorted[low] + sorted[high] == sum)
                        {
                            vector<int> temp {sorted[low], sorted[high], sorted[i]};
                            result.push_back(temp);
                            while(low < high && sorted[low] == sorted[low+1])   low++;
                            while(low < high && sorted[high] == sorted[high-1]) high--;
                            low++; high--;
                        }
                        else if(sorted[low] + sorted[high] < sum)
                        {
                            low++;
                        }
                        else
                        {
                            high--;
                        }		
                    }
                }
            }
        }
		return result;
    }
};

int main(void)
{

	vector<int> test{-1, 0, 1};

	Solution sol; 
	vector<vector<int>> result = sol.threeSum(test);
	return 0;
}