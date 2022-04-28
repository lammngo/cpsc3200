using System;

/// <summary>
/// class invariants
/// - this class design aimed to move objects diagonally on both x and y axis, in which object can either be energetic or
/// non-energetic but it must be active in order to make a move. The clients can use some other methods such as revive(), reset() to
/// manipulate the object as needed.


/// interface invariants
/// - No default constructor
/// - Parameterized constructor, 3 arguments must be passed in: energeticPoint, activePoint, size respectively
/// - Constructor will initialize all private members
/// - move(int p): object will move object to a specific number of squares depends on its state
/// - revive(): make the object active again if its currently inactive but still inside of the grid, the clients can continue 
/// to move the object after using the revive() method if they desire to
/// - value(): return the values of the object after some number of moves or after using other methods like revive() or reset()
/// - reset(): bring the object back to its starting state

namespace Project1
{
    public class gridFlea
    {
        public gridFlea(int energeticPoint, int activePoint, int size)
        {
            this.energeticPoint = energeticPoint;
            this.activePoint = activePoint;
            this.size = size;
        }
        private int x, y, count;
        private bool isEnergetic = true;
        private bool isActive = true;
        private const int INITIAL_X = 0;
        private const int INITIAL_Y = 0;

        private readonly int reward = 69;
        private readonly int size, energeticPoint, activePoint;

        /// <summary>
        /// precondition:
        /// - move(int p): the object MUST be ACTIVE in order to make a move. To check if its active or not, compare count(number of
        /// steps moved) with size(which is the gridSize)
        /// - revive(): ONLY USED when the object is inactive but still still inside of the grid, return -1 for other cases
        /// - value(): the object MUST be ACTIVE if you want to use this method, otherwise, it will return -1 if object is inactive
        /// and outside of the grid, return 0 if object is inactive but still inside of the grid
        /// - reset(): the clients can reset the object back to its starting state whenever they want to, ideally is when after making
        /// some moves and calling revive a few times, in other words, after you done with everything and you want a fresh restart

        /// post condition:
        /// - after checking for active state and your object satisfied, it will move upward diagonally on both x and y axis p squares
        /// if its energetic, otherwise, it will move 1 square only
        /// - the revive() method will make the object inactive status into active status again, which means after using the revive(),
        /// your objects isActive status will become true
        /// - value() will reduce the number of rewards as you move, which means the more you move your object, the less reward you
        /// are going to receive, and it will be resulted in the total value in which calculated by a math formula
        /// reset() makes x, y, and count back to 0, isActive and isEnergetic back to true

        //the object is inactive but still inside of the bound

        public void move(int p)
        {

            if (!isActive)
            {
                return;
            }
            if (isEnergetic)
            {
                x += p;
                y += p;
                count += p;

            } else {
                x++; 
                y++;
                count++;
            }
            isEnergetic = count < energeticPoint;
            isActive = count <= activePoint && count <= size; 
     
        }

        public void revive()
        {
            if (isActive || count > size)
            {
                return;
            }

            isActive = true;
            count = 0;
        }

        public int value()
        {
            if (!isActive && count > size)
            {
                return -1;
            } else if (!isActive && count <= size) 
            {
                return 0;
            }
            else
            {
                int change = Math.Abs(INITIAL_X - x) + Math.Abs(INITIAL_Y - y);
                return (reward - count) * size * change;
            }
        }

        public void reset()
        {
            x = INITIAL_X;
            y = INITIAL_Y;
            isEnergetic = true;
            isActive = true;
            count = 0;
        }

        public bool IsEnergetic()
        {
            return isEnergetic;
        }
        public bool IsActive()
        {
            return isActive;
        }
        public bool IsInsideTheGrid()
        {
            return count <= size;
        }       
    }
    
}

/// <summary>
/// implementation invariants
/// - move(int p):
/// + the method takes in one argument p. Object is in isActive status if it has not passed the activePoint(which was
/// randomly generated in the driver file) and it is still inside of the grid (comparing count(number of steps moved) and size)
/// + if object is isEnergetic, it moves up to p squares diagonally by making x, y and count added up to p squares
/// + if object is not isEnergetic, it moves up to 1 square diagonally by making x, y and count added up to 1 square
/// - revive(): if the object is isActive OR outside of the grid(count > size), then return nothing, otherwise, set isActive = true
/// and count = 0
/// - value():
/// + if object is not isActive and outside of the grid, return -1
/// + if object is not isActive but still inside of the grid, return 0
/// + otherwise, reduced reward by the number of steps moved (which is in this case is count), then return the result with size and
/// change(distance between initial x and initial y values with their current values) by multiplying them three together
/// - reset(): set everything back to its initial state
/// </summary>
///