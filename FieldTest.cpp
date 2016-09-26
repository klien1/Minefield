/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, placeMineOutBounds){
  Field minefield;

  ASSERT_ANY_THROW(minefield.get(11,11));
}

TEST(FieldType, isSafe){
  Field minefield;

  minefield.placeMine(2,2);
  ASSERT_FALSE(minefield.isSafe(2,2));
}

TEST(FieldTest, isSafeOutBounds){
  Field minefield;

  ASSERT_ANY_THROW(minefield.isSafe(11,11));
}

TEST(FieldTest, isSafeOutBoundsPlaceMine){
  Field minefield;

  minefield.placeMine(11,11);
  ASSERT_FALSE(minefield.isSafe(11,11));//out of bounds should return false
}

TEST(FieldTest, revealAdjacent){
  Field minefield;

  minefield.placeMine(3,3);
  minefield.placeMine(4,5);
  minefield.placeMine(3,2);
  minefield.placeMine(3,4);

  minefield.revealAdjacent(4,3);

}
