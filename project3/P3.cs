
namespace p3;

public class P3
{
    private static int MAX_SIZE = 10;
    static void Main(string[] args)
    {
        Console.WriteLine("*** Creating 10 Data Extractor objects ***");
        Console.WriteLine();
        dataExtractor[] arr = new dataExtractor[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++)
        {
            arr[i] = generateDataExtractor();
            Console.WriteLine(String.Join(", ", "=== Object " + i + " was defined as " + arr[i] + " ==="));
            if (arr[i].IsActive())
            {
                Console.WriteLine("<<< Testing if object is currently active to use method >>>");
                Console.WriteLine(">>> Congrats! This object is currently active <<< ");
                Console.WriteLine("*** Object attempting to use method any() 3 times ***");
                printArr("1st", arr[i].any());
                printArr("2nd", arr[i].any());
                printArr("3rd", arr[i].any());
                Console.WriteLine("*** Object attempting to use method target(unit z) 5 times ***");
                printArr("1st(with z = 3)", arr[i].target(3));
                printArr("2nd(with z = 4)", arr[i].target(3));
                printArr("3rd(with z = 2)", arr[i].target(3));
                printArr("4th(with z = 5)", arr[i].target(3));
                printArr("5th(with z = 6)", arr[i].target(3));
                Console.WriteLine("*** Object attempting to use method sum(unit z) 2 times ***");
                Console.WriteLine("1st(with z = 2): " + arr[i].sum(2));
                Console.WriteLine("2nd(with z = 5): " + arr[i].sum(5));
            }
            else
            {
                Console.WriteLine("Sorry, this object is being used under the invalid state.");
            }
            Console.WriteLine();
        }
    }
    private static void printArr(string prefix, int[] arr)
    {
        Console.Write(prefix + ": ");
        if (arr.Length == 0)
        {
            Console.WriteLine("Array is empty");
        }
        else
        {
            Console.WriteLine(String.Join(", ", arr));
            
        }
    }

    private static dataExtractor generateDataExtractor()
    {
        Random r = new Random();
        int num = r.Next(1, 4);
        switch (num)
        {
            case 1:
                dataExtractor d = new dataExtractor(generateArr());
                return d;
            case 2:
                dataHalf d1 = new dataHalf(generateArr());
                return d1;
            case 3:
                dataPlus d2 = new dataPlus(generateArr());
                return d2;
            default:
                throw new NotImplementedException();
        }
    }

    public static int[] generateArr()
    {
        Random r = new Random();
        int[] arr = new int[r.Next(1, 10)];
        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = r.Next(1, 20);
        }
        return arr;
    }
}