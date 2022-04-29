using System;
using System.Threading.Tasks.Dataflow;

namespace p3;

public class P3
{
    static void Main(string[] args)
    {
        int[] arr = {1, 2, 5, 8, 10, 16, 18};  
        int[] arr2 = {2, 4, 6, 10, 14, 16};
        int[] arr3 = {1, 6, 8, 9, 11, 16, 18};
        dataExtractor d = new dataExtractor(arr);
        dataExtractor d1 = new dataExtractor(arr2);
        // Console.WriteLine(String.Join(", ", d.any()));
        // Console.WriteLine(String.Join(", ", d.target(4)));
        // Console.WriteLine(String.Join(", ", d.target(5)));
        Console.WriteLine(String.Join(", ", d1.sum(4)));
        // Console.WriteLine(String.Join(", ", d1.sum(3)));
        //dataHalf d1 = new dataHalf(theArray);
        // Console.WriteLine(String.Join(", ", d1.any()));
        // Console.WriteLine(String.Join(", ", d1.any()));
        // Console.WriteLine(String.Join(", ", d1.any()));
        // Console.WriteLine(String.Join(", ", d1.any()));
        // Console.WriteLine(String.Join(", ", d1.any()));
        // Console.WriteLine(String.Join(", ", d1.any()));
        // dataPlus d2 = new dataPlus(theArray);
        // Console.WriteLine(String.Join(", ", d2.target(3)));
        // dataPlus d3 = new dataPlus(arr2);







    }

}