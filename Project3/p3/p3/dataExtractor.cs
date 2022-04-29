using System;
namespace p3;

public class dataExtractor
{
    public dataExtractor(int[] x)
    {
        if (x.Length <= 0)
        {
            isActive = false;
            inactiveCount++;
            return;
        }
        for (int i = 0; i < x.Length; i++)
        {
            xArray = arrayAppend(xArray, x[i]);
            checkDuplicates(xArray);
            yArray = arrayAppend(yArray, xArray[i] * 2);
            checkDuplicates(yArray);
        }
    }
    
    protected int[] xArray = {};
    protected int[] yArray = {};
    protected int inactiveCount = 0;
    protected bool isActive = true;

    
    private bool checkDuplicates(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            for (int j = i+1; j < arr.Length; j++)
            {
                if (arr[i] == arr[j])
                {
                    isActive = false;
                    inactiveCount++;
                    return isActive;
                }
            }
        }
        return isActive; 
    }

    protected int[] arrayAppend(int[] arr, int val)
    {
        int[] newArr = new int[arr.Length+1];
        for (int i = 0; i < arr.Length; i++)
        {
            newArr[i] = arr[i];
        }
        newArr[^1] = val;
        return newArr;
    }


    public virtual int[] any()
    {
        int[] arr = new int[xArray.Length*2];
        int arrIndex = 0;
        
        if (!isActive) return arr;
        
        for (int ele = 0; ele < xArray.Length; ele++)
        {
            arr[arrIndex++] = xArray[ele];
            arr[arrIndex++] = yArray[ele];
        }
        return arr;
    }

    public virtual int[] target(uint z)
    {
        int zCounter = 0;
        int[] arr = {};
        if (!isActive) return arr;

        foreach (var i in xArray)
        {
            if (zCounter == z) break;
            if (i % 2 == z % 2)
            {
                arr = arrayAppend(arr, i);
                zCounter++;
            }
        }
        return arr;
    }

    
    public int sum(uint z)
    {
        int total = 0;

        if (!isActive) return total;

        int[] arr = target(z);
        foreach (var i in arr)
        {
            total += i;
        }
        return total;
    }

    public bool IsActive()
    {
        return isActive;

    }
}
