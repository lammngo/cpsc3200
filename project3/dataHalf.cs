namespace p3;

public class dataHalf : dataExtractor
{
    public dataHalf(int[] xArray) : base(xArray)
    {
        if (!isActive) return;
        for (int i = 0; i < xArray.Length; i++)
        {
            xArray[i] /= 2;
        }

        bound = xArray[0];
        if (inactiveCount > bound)
        {
            isActive = false;
        }
    }
    private int bound;
    private int callCounter = 0;
    private int[] oddArray = {};

    public override int[] any()
    {
        callCounter++;
        if (callCounter % 2 == 1)
        {
            int[] parentAny = base.any();
            int max = parentAny[0];
            foreach (int i in parentAny)
            {
                max = i > max ? i : max;
            }
            oddArray = arrayAppend(parentAny, max + callCounter);
        }
        return oddArray;
    }
}