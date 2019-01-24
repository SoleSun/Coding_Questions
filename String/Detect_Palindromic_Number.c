#include <stdio.h>
#include <stdbool.h>

bool checkIfPalindrome(unsigned char str[])
{
	bool isPalindrome = true;
	unsigned char* backItr;
	int num_of_chars = 0;

	for(backItr = str; *backItr; backItr++, num_of_chars++);
	backItr--;

	for(int itr = num_of_chars; itr > (num_of_chars/2); itr--)
	{
		if (*str != *backItr)
		{
			isPalindrome = false;
		}
	}

	return isPalindrome;
}


int main(void)
{
	char str[9] = "12344321";

	if (checkIfPalindrome(str))
		printf("It's a palindrome!\n");

	return 0;
}
