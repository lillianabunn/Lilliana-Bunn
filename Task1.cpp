#include <iostream>

int main()
{
	int userInput;
	int i = 0;
	while (i < 10)
	{
		std::cout << "Please input a number, any number. Just not 5." << std::endl;
		std::cin >> userInput;
		if (userInput == 5)
		{
			std::cout << "Hey you weren't supposed to enter 5!" << std::endl;
			i = 10;
		}
		else
		{

		}
		if (i == 9)
		{
			std::cout << "Wow, you're more patient than I am, you win." << std::endl;
		}
		else
		{

		}
		i++;
	}
}