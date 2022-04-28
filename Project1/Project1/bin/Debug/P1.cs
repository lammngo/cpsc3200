using System;

namespace Project1
{
    public class P1
    {
        static void Main(string[] args)
        {
            Console.WriteLine();
            Console.WriteLine("---------------------Welcome to the gridFlea program---------------------");
            Console.WriteLine();
            Console.WriteLine("notes: This program will test on moving object 3 times/moves");
            Console.WriteLine();
            Console.WriteLine("=========================================================================");
            Console.WriteLine();

            Random rnd = new Random();

            gridFlea[] arr = new gridFlea[10];

            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine("* Preparing for object #" + i + " to bounce *");

                int energeticPoint = rnd.Next(1, 10);
                Console.WriteLine("energetic point: " + energeticPoint);
                int activePoint = energeticPoint + rnd.Next(1, 10);
                Console.WriteLine("active point: " + activePoint);
                int gridSize = rnd.Next(1, 10);
                Console.WriteLine("grid size: " + gridSize);

                arr[i] = new gridFlea(energeticPoint, activePoint, gridSize);

                Console.WriteLine();
               
                int firstMove = -3;
                Console.WriteLine("<---Object " + i + " attempt to move " + firstMove + " steps--->");
                arr[i].move(firstMove);
                if (arr[i].value() == -1)
                {
                    Console.WriteLine("Object is out of bound! Permanently inactivated.");
                }
                else if (arr[i].value() == 0)
                {
                    Console.WriteLine("Reviving object since it passed the active point but still inside the grid...");
                    arr[i].revive();
                    Console.WriteLine("Your object revived and gained " + arr[i].value() + " values after moving " + firstMove + " steps");
                } else
                    Console.WriteLine("Your object gained " + arr[i].value() + " values after moving " + firstMove + " steps");

                int secondMove = 6;
                Console.WriteLine("<---Object " + i + " attempt to move " + secondMove + " steps--->");
                arr[i].move(secondMove);
                if (arr[i].value() == -1) {
                    Console.WriteLine("Object is out of bound! Stop moving.");
                }
                else if (arr[i].value() == 0)
                {
                    Console.WriteLine("Reviving object since it passed the active point but still inside the grid...");
                    arr[i].revive();
                    Console.WriteLine("Your object revived and gained " + arr[i].value() + " values after moving " + secondMove + " steps");
                }
                else
                    Console.WriteLine("Your object gained " + arr[i].value() + " values after moving " + secondMove + " steps");

                int thirdMove = 7;
                Console.WriteLine("<---Object " + i + " attempt to move " + thirdMove + " steps--->");
                arr[i].move(thirdMove);
                if (arr[i].value() == -1)
                {
                    Console.WriteLine("Object is out of bound! Stop moving.");
                }                
                else if(arr[i].value() == 0){

                    Console.WriteLine("Reviving object since it passed the active point but still inside the grid...");
                    arr[i].revive();
                    Console.WriteLine("Your object revived and gained " + arr[i].value() + " values after moving " + thirdMove + " steps");
                } else
                    Console.WriteLine("Your object gained " + arr[i].value() + " values after moving " + thirdMove + " steps");

                // reset
                Console.WriteLine();
                Console.WriteLine("---> Reseting object back to originial values <---");
                arr[i].reset();
                Console.WriteLine("Your object returned back to " + arr[i].value() + " values");

                Console.WriteLine();
                Console.WriteLine("=========================================================================");
                Console.WriteLine();
            }
            Console.WriteLine("*********************************THE END*********************************");
        }

    }

}
