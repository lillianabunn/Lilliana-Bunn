using System;

namespace csharp1
{
    class Week2
    {
        static void Main(string[] args)
        {
            int[] counter = new int[101];

            for (int i=1; i < 101; i++)
            {
                counter.SetValue(i, i); 
                Console.WriteLine(i);
            }

            for (int i=1; i<101; i++)
            {
                if (i % 3==0 & i % 5 == 0)
                {
                    Console.WriteLine(i + "FizzBuzz");
                }
                else if (i % 3 == 0)
                {
                    Console.WriteLine(i + "Fizz");
                }
                else if(i % 5 == 0)
                {
                    Console.WriteLine(i + "Buzz");
                }
            }

            int number1 = 4;
            int number2 = 5;

            Console.WriteLine("The first number is: " + number1 + "The second number is: " + number2);
            Console.WriteLine("Swapping...");
            number1 = number1 + number2;
            number2 = number1 - number2;
            number1 = number1 - number2;




            Console.WriteLine(number1);
            Console.WriteLine(number2);
        }
    }
}