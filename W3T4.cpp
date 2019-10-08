#include <iostream>

/*int main()
{
	bool whileBool = true;

	int numberChoice;


	std::cout << "Please input a number between 1 and 9: ";
	std::cin >> numberChoice;

	int space = numberChoice - 1;

	while (whileBool == true)
	{
		if (numberChoice < 1 || numberChoice > 9)
		{
			std::cout << "\n" << "Invalid number, please try again: ";
			std::cin >> numberChoice;
		}
		else
		{
			whileBool = false;
		}
	}

	std::cout << "You have chosen: " << numberChoice << std::endl;
	std::cout << "Commencing..." << std::endl;

	for (int i = 1; i <= numberChoice; i++)
	{
		for (int j = numberChoice; j <= space; j++)
		{
			std::cout << " ";
		}
		space--;
		for (int k = 1; k < numberChoice; k++)
		{
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}*/

int main()
{
	bool whileBool = true;

	int numberChoice;


	std::cout << "Please input a number between 1 and 9: ";
	std::cin >> numberChoice;

	int space = numberChoice - 1;

	while (whileBool == true)
	{
		if (numberChoice < 1 || numberChoice > 9)
		{
			std::cout << "\n" << "Invalid number, please try again: ";
			std::cin >> numberChoice;
		}
		else
		{
			whileBool = false;
		}
	}



	//NOT MINE

	//LOOP TO PRINT UPPER HALF TRIANGLE
	for (int i = 0; i < 5; i++)
	{
		//LOOP TO PRINT SPACES
		for (int j = 5; j >= i; j--)
		{
			std::cout << " ";
		}
		/* LOOP TO PRINT
			*
		   **
		  ***
		  */
		for (int k = 0; k <= i; k++)
		{
			std::cout << "*";
		}
		//LOOP TO PRINT OTHER HALF"
		for (int l = 1; l <= i; l++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	//LOOP TO PRINT LOWER HALF  TRIANGLE
	for (int j = 0; j <= 5; j++)
	{
		//LOOP TO PRINT SPACES
		for (int k = 0; k <= j; k++)
		{
			std::cout << " ";
		}

		/* LOOP TO PRINT
			***
			 **
			  *
		*/
		for (int l = 5; l >= j; l--)
		{
			std::cout << "*";
		}
		//LOOP TO PRINT OTHER HALF
		for (int m = 5; m > j; m--)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	return 0;
}