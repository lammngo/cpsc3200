
/* Implementation invariants:
 *
 * Implementation choices:
 * 
 * 1. dataPlus parameterized constructor:
 * - check for invalid state (active or inactive) of an object
 * - no need to check for the length and duplicates of an array that passed in the constructor because they were already
 * checked in the parent class
 * - a is set to the middle value of yArray
 * - all data members of this class were set to private
 *
 * 2. arrayConcat():
 * - this private method will keep the requestCount in check, if the base requestCount % k (which in this design k is
 * set to 7), it will trigger the yArray and append to yArray j*k value. j will be incremented by 1 everytime you
 * called the function.
 *
 * 3. target():
 * - check for the arrayConcat to see if it triggers the yArray because of its requestCount
 * - check for invalid state of an object because it override everything from the parent class
 * - after it appended odd values from xArray to the newArr (again, the algorithm was specified inside of the dataExtractor
 * class), reset the zCounter to 0 because you want to do the same technique with yArray, but this time, append the even
 * values from yArray.
 *
 * 4. sum(), any():
 * - check for the arrayConcat to see if it triggers the yArray because of its requestCount
 * - no need for the invalid state check because it was already checked inside of their parent class
 * 
 */


namespace p3;

public class dataPlus : dataExtractor
{
    public dataPlus(int[] yArr) : base(yArr) 
    {
        if(!isActive) return;
        a = yArray[yArray.Length / 2];
        yArray = arrayAppend(yArray, a);
    }
    
    private int a;
    private int j = 1;
    private int k = 7;
    public override int[] any()
    {
        arrayConcat();
        return base.any();
    }

    public override int sum(uint z)
    {
        arrayConcat();
        return base.sum(z);
    }

    /* Pre-conditions:
     * - sum(), target() taking in z as unit type
     *
     * Post-conditions:
     * - zCounter will be updated everytime it appended new values from xArray to the arr variable that was created
     * inside of the method. zCounter was reset back to 0 after its done with xArray.
     * - arrConcat() may be triggered if you called the method several times and the requestCount got updated in the
     * parent class. 
     *
     */
    
    public override int[] target(uint z)
    {
        int zCounter = 0;
        int[] arr = { };
        if (!isActive) return arr;
        arrayConcat();
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

    private void arrayConcat()
    {
        if (requestCount % k == 0)
        {
            j++;
            yArray = arrayAppend(yArray, j * k);
        }
    }
}