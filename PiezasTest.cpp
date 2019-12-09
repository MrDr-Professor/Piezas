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