using System;
using System.Threading.Tasks.Dataflow;

namespace p3;

public class P3
{
    static void Main(string[] args)
    {
        int[] theArray = {1, 2, 5, 8, 10, 16, 18};
        dataExtractor d = new dataExtractor(theArray);
        // // int[] array = d.any();
        // Array.ForEach(d.any(), Console.WriteLine);
        // Console.WriteLine(String.Join(", ", d.any()));
        // d.target(4);
        // Console.WriteLine(String.Join(", ", d.target(4)));
        // Console.WriteLine(String.Join(", ", d.sum(4)));
        dataHalf d1 = new dataHalf(theArray);
        Console.WriteLine(String.Join(", ", d1.any()));
        Console.WriteLine(String.Join(", ", d1.any()));
        Console.WriteLine(String.Join(", ", d1.any()));
        Console.WriteLine(String.Join(", ", d1.any()));
        Console.WriteLine(String.Join(", ", d1.any()));
        Console.WriteLine(String.Join(", ", d1.any()));







    }

}