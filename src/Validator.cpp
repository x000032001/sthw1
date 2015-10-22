#include "Validator.h"

#define legalRange(x) (1<=(x)&&(x)<=200)
Triangle testTriangle(int a,int b,int c)
{
	if( !legalRange(a) || !legalRange(b) || !legalRange(c) )
		return TriNot;
}
