#include "pch.h"
#include "TriangleLibrary.h"
#include <stdexcept>
#include "math.h"
#define M_PI 3.14159
using namespace std;
namespace TriangleFuncs
{
	double MyTriangleFuncs::Cos(double a)
	{
		a = a * M_PI / 180;
		return cos(a);
	}
	double MyTriangleFuncs::Sin(double a)
	{
		a = a * M_PI / 180;
		return sin(a);
	}
	double MyTriangleFuncs::Square(double a)
	{
		a = sqrt(a);
		return a;
	}
	double MyTriangleFuncs::Pow(double a, int b)
	{
		for (int i = 0; i < b - 1; i++)
			a *= a;
		if (b == 0)
			return 1;
		else
			return a;
	}
}