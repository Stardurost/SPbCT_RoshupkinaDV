#pragma once

#ifdef TRIANGLELIBRARY_EXPORTS
#define TRIANGLELIBRARY_API __declspec(dllexport)
#else
#define TRIANGLELIBRARY_API __declspec(dllimport)
#endif
namespace TriangleFuncs
{
	class MyTriangleFuncs
	{
	public:

		static  TRIANGLELIBRARY_API double Cos(double a);
		// Returns a * b
		static  TRIANGLELIBRARY_API double Sin(double a);
		// Returns a / b
		// Throws const std::invalid_argument& if b is 0
		static  TRIANGLELIBRARY_API double Square(double a);

		static  TRIANGLELIBRARY_API double Pow(double a, int b);
	};
}