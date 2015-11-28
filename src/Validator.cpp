#include "Validator.h"

#define legalRange(x) (1<=(x)&&(x)<=200)
Triangle testTriangle(int a,int b,int c)
{
	if( !legalRange(a) || !legalRange(b) || !legalRange(c) )
		return TriNot;

	if( !(a+b>c && a+c>b && b+c>a) )
		return TriIll;

	if( a == b && b == c )
		return TriEqu;

	if( a != b && b != c && a != c )
		return TriSca;

	return TriIs;
}


