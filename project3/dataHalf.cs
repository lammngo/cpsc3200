
/* Implementation invariants:
 *
 * Implementation choices:
 * 1. dataHalf parameterized constructor:
 * + check for invalid state (active or no) of every objects in an array
 * + no need to check for the length and duplicates of an array that passed in the constructor because they were already
 * checked in the parent class
 * + the bound will be set to the first element of xArray
 * + all the data members of this class will be set to private
 *
 * 2. override any() from dataExtractor:
 * + check for invalid state of every objects in an array
 * + check for the bound because if the object that has inactiveCount bigger tha the bound then object will be deactivated
 * + callCounter is used to identify if the method call is odd or even
 * + in order to make each odd method call distinct, i appended to a previous array a max value of it, by doing this the
 * new array with odd method call will always be different from the last one. the even method calls will be ignored as
 * they only copied the values from the aligned odd one. 
 * 
 * 3. override target() and sum():
 * + always checkBound before execute the function to see if the objects are active
 *
 */


namespace p3;

public class dataHalf : dataExtractor
{
    public dataHalf(int[] xArr) : base(xArr)
    {
        if (!isActive) return;
        for (int i = 0; i < xArray.Length; i++)
        {
            xArray[i] /= 2;
        }
        bound = xArray[0];
    }
    private int bound;
    private int callCounter;
    private int[] oddArray = {};

    /* Pre-conditions:
     * - Guard checking for all 3 methods: objects MUST BE active in order to use the methods
     * - z that was passed in target() and sum() MUST BE unit type
     *
     * Post-conditions:
     * - any():
     * + odd number of method calls will produce different arrays, while even number of method calls will simply copy
     * their aligned odd ones
     * 
     */
    public override int[] any()
    {
        if (!isActive) return oddArray;
        checkBound();
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

    public override int[] target(uint z)
    {
        checkBound();
        return base.target(z);
    }

    public override int sum(uint z)
    {
        checkBound();
        return base.sum(z);
    }

    private void checkBound()
    {
        if (inactiveCount > bound)
        {
            isActive = false;
        }
    }
}