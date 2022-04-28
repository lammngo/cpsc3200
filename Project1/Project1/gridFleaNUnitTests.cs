 using NUnit.Framework;

namespace Project1
{
    [TestFixture]
    public class gridFleaNUnitTests
    {
        private gridFlea g, g2, g3, g4, g5;

        [SetUp]
        public void SetUp()
        {
            // arrange
            g = new gridFlea(1, 4, 5);
            g2 = new gridFlea(3, 6, 8);
            g3 = new gridFlea(1, 10, 4);
            g4 = new gridFlea(7, 8, 2);
            g5 = new gridFlea(4, 7, 9);
        }
        [Test]
        public void If_isActive_AndEnergetic_ObjectMoves_pSquares()
        {
            // act
            g2.move(2);

            // assert
            Assert.AreEqual(2144, g2.value());
            Assert.IsTrue(g2.IsActive());
            Assert.IsTrue(g2.IsEnergetic());
        }
        [Test]
        public void If_isActive_ButNonEnergetic_ObjectMoves_1Square()
        {
            g.move(3);

            Assert.AreEqual(1980, g.value());
            Assert.IsTrue(g.IsActive());
            Assert.IsFalse(g.IsEnergetic());
        }

        [Test]
        public void Revive_If_Inactive_ButStillInsideTheGrid()
        {
            g.move(3);
            Assert.AreEqual(1980, g.value());
            g.move(6);
            Assert.AreEqual(2600, g.value());
            g.move(7);
            g.revive();
            Assert.AreEqual(3450, g.value());
            Assert.IsTrue(g.IsActive());
            Assert.IsTrue(g.IsInsideTheGrid());
        }
        [Test]
        public void ObjectMovingUntil_BecomeInactive_AndOutsideTheGrid()
        {
            g3.move(3);
            Assert.AreEqual(1584, g3.value());
            g3.move(6);
            Assert.AreEqual(2080, g3.value());
            g3.move(7);
            Assert.IsFalse(g3.IsActive());
            Assert.IsFalse(g3.IsInsideTheGrid());
        }
        [Test]
        public void If_ObjectIsInactive_AndOutsideTheGrid()
        {
            g4.move(3);
            Assert.AreEqual(-1, g4.value());
            Assert.IsFalse(g4.IsActive());
            Assert.IsFalse(g4.IsInsideTheGrid());
        }
        [Test]
        public void If_ObjectIsInactive_ButInsideTheGrid_AfterSomeMoves()
        {
            g5.move(3);
            Assert.AreEqual(3564, g5.value());
            g5.move(6);
            Assert.IsFalse(g5.IsActive());
            Assert.IsTrue(g5.IsInsideTheGrid());
        }
        [Test]
        public void AfterSomeMoves_ResetObject_BackToOriginalValues()
        {
            g.move(3);
            g.move(6);
            g.move(7);
            g.revive();
            g.reset();
            Assert.AreEqual(0, g.value());
            Assert.IsTrue(g.IsActive());
            Assert.IsTrue(g.IsInsideTheGrid());
        }
    }

}
