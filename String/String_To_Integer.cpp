#include <iostream>

class Solution {
public:
    long long myAtoi(std::string s) {
        long long conversion = 0; 
        int multiplier = 1;
        bool numFirstFound = false;
        if( !s.empty() )
        {
        	for(std::string::iterator it = s.begin(); 
        		it < s.end();
        		it++)
        	{
        		// If the first valid character hasn't been found until now
        		if((*it >= '0' && *it <= '9') || 
        			*it == '-'                || 
        			*it == '+')
        		{        			
        			if(*it == '-') 
    				{
    					if (numFirstFound) break;
    					multiplier = -1;
    				}
        			else if (*it == '+')
        			{
        				if (numFirstFound) break;
        			}
        			else
        			{
        				conversion = (conversion * 10) + (*it - '0');
        			}

        			if (!numFirstFound) numFirstFound = true;
        		}
        		else if(*it == ' '){}
        		else break;
        	}
        }

        return conversion * multiplier;
    }
};

int main (void)
{
	std::string test = "-91283472332";

	Solution sol; 
	long long num  = sol.myAtoi(test) ;
	std::cout << num << std::endl;

	return 0;
}