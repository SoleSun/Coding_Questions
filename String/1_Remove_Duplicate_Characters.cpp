#include <iostream>

void removeDuplicateCharacters(unsigned char *str)
{
	unsigned char ASCII_LUT[256] = {0};
	unsigned char *itr;

	if (*str == '\0') return;

	// The itr variable is meant to keep track of unique character
    // placeholders while the str pointer iterates through the whole
    // string
	for (itr = str; *str; str++)
	{
		if(ASCII_LUT[*str] == 0)
		{
			// Then it is a unique character
			ASCII_LUT[*str]++;
			//Assign the placeholder with the iterator when a unique
			//char has been found
			*itr = *str;
			itr++;
		}
	}

	*itr = '\0';
}

int main(void)
{
	unsigned char test1[] = "old man and the sea";
	unsigned char test2[] = "| | | | | w";
	unsigned char test3[] = "Who is QIQI WONG?";
	unsigned char test4[] = "";

	removeDuplicateCharacters(test1);
	removeDuplicateCharacters(test2);
	removeDuplicateCharacters(test3);
	removeDuplicateCharacters(test4);

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	std::cout << test4 << std::endl;

	return 0;
}

