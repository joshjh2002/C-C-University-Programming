#include <iostream>
#include <typeinfo>

class Fraction
{
public:
	Fraction(double num, double den);

	double GetNumerator();

	double GetDenominator();

	template <typename T>
	T ReturnAsType()
	{
		T output = numerator/denominator;
		return output;
	}

	template <typename T>
	void print()
	{
		T out = numerator / denominator;
		std::cout << "as type " << typeid(T).name() << " -> " << numerator << "/" << denominator << " = " << out << "\n";
	}

	Fraction& simplify();

	void operator--();
	void operator++();
private:
	double numerator, denominator;
};

Fraction &operator+ (Fraction& f1, Fraction& f2);
Fraction &operator* (Fraction& f1, Fraction& f2);
Fraction &operator- (Fraction& f1, Fraction& f2);
Fraction &operator/ (Fraction& f1, Fraction& f2);