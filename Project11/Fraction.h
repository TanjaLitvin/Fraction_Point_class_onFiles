#pragma once
#include<iostream>
using namespace std;
class Fraction;
ostream& operator<<(ostream& os, const Fraction& obj);

class Fraction
{
	int Integer;    //целая
	int Numerator;  //числитель
	int Denominator;//знаменатель
public:
	int getInteger()const;
	int getNumerator()const;

	int getDenominator()const;
	void setInteger(int Integer);
	void setNumerator(int Numerator);
	void setDenominator(int Denominator);

	//Constructors:
	Fraction();
	Fraction(int Integer);
	Fraction(int Numerator, int Denominator);
	Fraction(int Integer, int Numerator, int Denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//Operators:
	Fraction& operator=(const Fraction& other);
	//Methods:
	void ToProper();
	void ToImproper();
	void Reduce();

	void Print()const;
};
