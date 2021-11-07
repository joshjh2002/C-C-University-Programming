#include "Fraction.h"

Fraction::Fraction(double num, double den)
{
	numerator = num;
	denominator = den;
}

double Fraction::GetNumerator()
{
	return numerator;
}

double Fraction::GetDenominator()
{
	return denominator;
}

Fraction &operator+(Fraction &f1, Fraction &f2)
{
	double num = f1.GetNumerator() * f2.GetDenominator() + f2.GetNumerator() * f1.GetDenominator();
	double den = f1.GetDenominator() * f2.GetDenominator();

	Fraction *output = new Fraction(num, den);
	return *output;
}

Fraction &operator-(Fraction &f1, Fraction &f2)
{
	double num = f1.GetNumerator() * f2.GetDenominator() - f2.GetNumerator() * f1.GetDenominator();
	double den = f1.GetDenominator() * f2.GetDenominator();

	Fraction *output = new Fraction(num, den);
	return *output;
}

Fraction &operator*(Fraction &f1, Fraction &f2)
{
	double num = f1.GetNumerator() * f2.GetNumerator();
	double den = f1.GetDenominator() * f2.GetDenominator();

	Fraction *output = new Fraction(num, den);
	return *output;
}

Fraction &operator/(Fraction &f1, Fraction &f2)
{
	Fraction recip(f2.GetDenominator(), f2.GetNumerator());
	return f1 * recip;
}

Fraction &Fraction::simplify()
{
	int num = this->numerator;
	int den = this->denominator;

	int div = num;

	for (div = num; div > 1; div--)
	{
		if (den % div == 0 && num % div == 0)
		{
			//int oldnum = num;
			num = num / div;
			den = den / div;
		}
	}
	Fraction *f1 = new Fraction(num, den);

	return *f1;
}

void Fraction::operator--()
{
	this->numerator -= denominator;
}

void Fraction::operator++()
{
	this->numerator += denominator;
}