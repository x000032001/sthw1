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

TEST( testTriangle , Equilateral )
{
	ASSERT_EQ( TriEqu , testTriangle(1,1,1) );
	ASSERT_EQ( TriEqu , testTriangle(100,100,100) );
	ASSERT_NE( TriEqu , testTriangle(3,4,3) );
}

TEST( testTriangle , Scalene )
{
	ASSERT_EQ( TriSca , testTriangle(2,3,4) );
	ASSERT_EQ( TriSca , testTriangle(4,5,6) );
	ASSERT_NE( TriSca , testTriangle(3,3,4) );
}

