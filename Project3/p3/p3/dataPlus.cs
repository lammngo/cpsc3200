namespace p3;

public class dataPlus : dataExtractor
{
    public dataPlus(int[] yArr) : base(yArr) 
    {
        if(!isActive) return;
        a = yArray[yArray.Length / 2];
        yArray = arrayAppend(yArray, a);
        // Console.WriteLine(String.Join(", ", yArray));
    }
    
    private int a;
    public override int[] target(uint z)
    {
        int zCounter = 0;
        int[] arr = { };
        if (!isActive) return arr;
        foreach (var i in xArray)
        {
            if(zCounter == z) break;
            if (i % 2 != 0)
            {
                arr = arrayAppend(arr, i);
                zCounter++;
            }
        }

        zCounter = 0;
        foreach (var j in yArray)
        {
            if(zCounter == z) break;
            if (j % 2 == 0)
            {
                arr = arrayAppend(arr, j);
                zCounter++;
            }
        }

        return arr;
    }
}