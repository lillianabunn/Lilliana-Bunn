using System;

namespace Week2Tutorial2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] listOfNumbers = new int[] { 2, 6, 200, 4, 23, 1, 0, 7, 8, 5, 3, 2 };
            for(int i=0; i < listOfNumbers.Length; i++)
            {
                Console.WriteLine(listOfNumbers[i]);
                foreach(int sortList in listOfNumbers)
                {
                    if(listOfNumbers[0] < listOfNumbers[1])
                    {
                        int temp1 = listOfNumbers[0];
                        int temp2 = listOfNumbers[1];
                        listOfNumbers[0] = temp2;
                        listOfNumbers[1] = temp1;
                        Console.WriteLine("open" + temp1 + " " + temp2 + "close");
                        Console.WriteLine(listOfNumbers[i]);
                    }
                }
            }
        }
    }
}
