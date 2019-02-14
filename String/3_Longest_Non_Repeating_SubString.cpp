class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  		int ASCII_LUT_OF_INDICES[128];
  		int max;

  		for(int i = 0, j = 0; j < s.size(); j++)
  		{
  			i = ASCII_LUT_OF_INDICES[(unsigned char) s[j]] > i ? 
  			    ASCII_LUT_OF_INDICES[(unsigned char) s[j]]     :
  			    i;

  			max = max < j - i ? 
  			      (j - i)     : 
  			      max;

  			ASCII_LUT_OF_INDICES[(unsigned char) s[j]] = j + 1;
  		}

  		return max;
    }
};