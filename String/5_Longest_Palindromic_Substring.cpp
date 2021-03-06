#include <iostream>

class Solution
{
public:
	Solution(){};
	
    std::string longestPalindrome(std::string s) 
    {
        std::string longest_palindrome = "";
        int start = 0, end = 0;

        if (s.size() >= 1)
        {
            for (unsigned int i = 0; i < s.size(); i++)
            {
                int odd  = expandAroundCentre(s, i, i);
                int even = expandAroundCentre(s, i, i+1);
                int len = odd > even ? odd : even;
                if (len > (end - start))
                {
                    start = i - ((len-1) / 2);
                    end   = i + (len / 2);
                }
            }

            longest_palindrome = s.substr(start, (end-start)+1);
        }

        return longest_palindrome;
    }

    int expandAroundCentre(std::string s, int L, int R)
    {
        int left_ = L, right_ = R; 

        while((left_ >= 0) && 
              (right_ < s.size()) && 
              (s[left_] == s[right_]) )
        {
            left_--;
            right_++;
        }

        return right_ - left_ - 1;
    }

	std::string longestPalindromeOld(std::string s) 
	{
		std::string longest_palindrome;
    	std::string buffer; 

    	for (unsigned int i = 0; i < s.size(); i++)
    	{
    		buffer.push_back(s[i]);
    		for(unsigned int j = i; j < s.size(); j++)
    		{
    			if (isPalindrome(buffer) &&
    				(buffer.size() > longest_palindrome.size()) )
    			{
    				longest_palindrome = buffer;
    			}
    			if (j + 1 < s.size()) buffer.push_back(s[j+1]);
    		}
    		buffer.clear();
    	}

    	return longest_palindrome;
    }	

    bool isPalindrome (std::string str)
    {
    	bool isPalin = true;
    	if (str.empty())
    	{
    		isPalin = false;
    	}
    	else
    	{
    		for(unsigned int itr1 = 0, itr2 = str.size()-1;
    			itr1 <= ( (str.size() - 1) / 2 );
    			itr1++, itr2--)
    		{
    			if(str[itr1] != str[itr2])
    			{
    				isPalin = false;
    				break;
    			}
    		}
    	}

   		return isPalin;
    }
};

int main()
{
	std::string test1 = "abbad";
	std::string test2 = "cbbd";
	std::string test3 = "a";
	std::string test4 = "babad";

	Solution sol;
	
	std::cout << sol.longestPalindrome(test1) << std::endl;
	std::cout << sol.longestPalindrome(test2) << std::endl;
	std::cout << sol.longestPalindrome(test3) << std::endl;
	std::cout << sol.longestPalindrome(test4) << std::endl;

	return 0;
}