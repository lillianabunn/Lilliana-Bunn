#include <iostream>

int main()
{
	int numberChoice;
	int counter;
	int temp = 0;
	bool whileBoolean = true;
	std::cout << "Please input any number between 1 and 9: ";
	std::cin >> numberChoice;
	while (whileBoolean == true)
	{
		if (numberChoice > 9 || numberChoice < 1)
		{
			std::cout << "Invalid input, please try again. Input any number between 1 and 9." << std::endl;
			std::cin >> numberChoice;
		}
		else
		{
			whileBoolean = false;
		}
	}
	for (int i = 1; i <= numberChoice; i++)
	{
		std::cout << i << ", ";
		temp = temp + i;
	}
	std::cout << "\n" << "Your sum is: ";
	std::cout << temp;
}