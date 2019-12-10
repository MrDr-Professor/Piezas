/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, drop1)
{
  Piezas p;
	ASSERT_EQ(p.dropPiece(0), X);
}

TEST(PiezasTest, drop2)
{
  Piezas p;
  p.dropPiece(0);
	ASSERT_EQ(p.dropPiece(1), O);
}

TEST(PiezasTest, drop34)
{
	Piezas p;
  p.dropPiece(3);
	ASSERT_EQ(p.dropPiece(1), O);
}

TEST(PiezasTest, dropAllIn1)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
	ASSERT_EQ(p.dropPiece(0), X);
}

TEST(PiezasTest, dropFill)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
	ASSERT_EQ(p.dropPiece(3), O);
}

TEST(PiezasTest, dropFullCol)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
	ASSERT_EQ(p.dropPiece(0), Blank);
}

TEST(PiezasTest, dropUnderbounds)
{
	Piezas p;
	ASSERT_EQ(p.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropOverbounds)
{
	Piezas p;
	ASSERT_EQ(p.dropPiece(4), Invalid);
}

TEST(PiezasTest, getX)
{
	Piezas p;
  p.dropPiece(0);
	ASSERT_EQ(p.pieceAt(0, 0), X);
}

TEST(PiezasTest, getO)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(3);
	ASSERT_EQ(p.pieceAt(0, 3), O);
}

TEST(PiezasTest, getBlank)
{
	Piezas p;
	ASSERT_EQ(p.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, getInvUnderCol)
{
	Piezas p;
	ASSERT_EQ(p.pieceAt(0, -1), Invalid);
}

TEST(PiezasTest, getInvOverCol)
{
	Piezas p;
	ASSERT_EQ(p.pieceAt(0, 4), Invalid);
}

TEST(PiezasTest, getInvUnderRow)
{
	Piezas p;
	ASSERT_EQ(p.pieceAt(-1, 0), Invalid);
}

TEST(PiezasTest, getInvOverRow)
{
	Piezas p;
	ASSERT_EQ(p.pieceAt(4, 0), Invalid);
}

TEST(PiezasTest, getInvBoth)
{
	Piezas p;
	ASSERT_EQ(p.pieceAt(4, 4), Invalid);
}

TEST(PiezasTest, reset1)
{
	Piezas p;
  p.dropPiece(0);
  p.reset();
	ASSERT_EQ(p.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, reset2)
{
	Piezas p;
  p.dropPiece(1);
  p.reset();
	ASSERT_EQ(p.pieceAt(0, 1), Blank);
}

TEST(PiezasTest, reset3)
{
	Piezas p;
  p.dropPiece(2);
  p.reset();
	ASSERT_EQ(p.pieceAt(0, 2), Blank);
}

TEST(PiezasTest, reset4)
{
	Piezas p;
  p.dropPiece(3);
  p.reset();
	ASSERT_EQ(p.pieceAt(0, 3), Blank);
}

TEST(PiezasTest, resetFull)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(3);
  p.reset();
	ASSERT_EQ(p.pieceAt(2, 3), Blank);
}

TEST(PiezasTest, notDone)
{
	Piezas p;
	ASSERT_EQ(p.gameState(), Invalid);
}

TEST(PiezasTest, rowTie)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), Blank);
}

TEST(PiezasTest, XRow)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(3);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), X);
}

TEST(PiezasTest, ORow)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(0);
  p.dropPiece(3);
  p.dropPiece(1);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(2);
	ASSERT_EQ(p.gameState(), O);
}

TEST(PiezasTest, XCol)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(2);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), X);
}

TEST(PiezasTest, colTie)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(2);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), Blank);
}

TEST(PiezasTest, OCol)
{
	Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(1);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(2);
	ASSERT_EQ(p.gameState(), O);
}