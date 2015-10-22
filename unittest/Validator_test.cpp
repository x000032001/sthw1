#include "Validator.h"

TEST( testTriangle , Not )
{
	// low bound 
	ASSERT_EQ( TriNot , testTriangle(0,0,0) );
	ASSERT_EQ( TriNot , testTriangle(0,1,1) );
	ASSERT_EQ( TriNot , testTriangle(1,1,0) );
	ASSERT_EQ( TriNot , testTriangle(1,0,1) );
	ASSERT_EQ( TriNot , testTriangle(1,0,0) );
	ASSERT_EQ( TriNot , testTriangle(0,1,0) );
	ASSERT_EQ( TriNot , testTriangle(0,0,1) );

	// up bound
	ASSERT_EQ( TriNot , testTriangle(0,0,0) );
	ASSERT_EQ( TriNot , testTriangle(0,201,201) );
	ASSERT_EQ( TriNot , testTriangle(201,201,0) );
	ASSERT_EQ( TriNot , testTriangle(201,0,201) );
	ASSERT_EQ( TriNot , testTriangle(201,0,0) );
	ASSERT_EQ( TriNot , testTriangle(0,201,0) );
	ASSERT_EQ( TriNot , testTriangle(0,0,201) );
}

TEST( testTriangle , Illegal )
{
	// for the formula
	// a + b > c && a + c > b && b + c > a
	ASSERT_EQ( TriIll , testTriangle(1,1,3) );
	ASSERT_EQ( TriIll , testTriangle(3,1,1) );
	ASSERT_EQ( TriIll , testTriangle(1,3,1) );
}
