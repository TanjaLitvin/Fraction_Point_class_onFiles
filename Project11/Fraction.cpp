#include "Fraction.h"


int Fraction::getInteger()const
{
	return this->Integer;
}
int Fraction::getNumerator()const
{
	return this->Numerator;
}
int Fraction::getDenominator()const
{
	return this->Denominator;
}
void Fraction::setInteger(int Integer)
{
	this->Integer = Integer;
}
void Fraction::setNumerator(int Numerator)
{
	this->Numerator = Numerator;
}
void Fraction::setDenominator(int Denominator)
{
	if (Denominator == 0)this->Denominator = 1;
	else this->Denominator = Denominator;
}
//Constructors:
Fraction::Fraction()
{
	this->Integer = 0;
	this->Numerator = 0;
	this->Denominator = 1;
	cout << "DefConstruct:\t" << this << endl;
}
Fraction::Fraction(int Integer)
{
	this->Integer = Integer;
	this->Numerator = 0;
	this->Denominator = 1;
	cout << "SingleArgConstruct:" << this << endl;
}
Fraction::Fraction(int Numerator, int Denominator)
{
	this->Integer = 0;
	this->Numerator = Numerator;
	this->Denominator = Denominator;
	cout << "Construct:\t" << this << endl;
}
Fraction::Fraction(int Integer, int Numerator, int Denominator)
{
	this->Integer = Integer;
	this->Numerator = Numerator;
	this->Denominator = Denominator;
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->Integer = other.Integer;
	this->Numerator = other.Numerator;
	this->Denominator = other.Denominator;
	cout << "CopyConstruct:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}
//Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->Integer = other.Integer;
	this->Numerator = other.Numerator;
	this->Denominator = other.Denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
//Methods:
void Fraction::ToProper()
{
	//переводит дробь в правильную
	Integer += Numerator / Denominator;
	Numerator %= Denominator;//Numerator=Numerator%Denominator
}
void Fraction::ToImproper()
{
	//переводит дробь в неправильную.это нужно для операций умножения 
	//и деления дробей
	Numerator += Integer * Denominator;
	Integer = 0;
}
void Fraction::Reduce()
{
	//сокращает простую дробь
	int more;//большее значение
	int less;//меньшее значение
	int reminder;//остаток от деления большего на меньшее
	if (Numerator < Denominator)
	{
		less = Numerator;
		more = Denominator;
	}
	else
	{
		less = Denominator;
		more = Numerator;
	}
	do
	{
		reminder = more % less;
		more = less;
		less = reminder;
	} while (reminder);
	int GCD = more;//Greatest Common Divisor-наибольший общий делитель
	Numerator /= GCD;
	Denominator /= GCD;
}


void Fraction::Print()const
{
	if (Integer != 0)cout << Integer;
	if (Numerator != 0)
	{
		if (Integer) cout << "(";
		cout << Numerator << "/" << Denominator;
		if (Integer) cout << ")";
	}
	if (Integer == 0 && Numerator == 0)
	{
		cout << 0;
	}
	cout << endl;
}

Fraction operator*(Fraction left, Fraction right)
{
	Fraction res;
	left.Reduce();
	right.Reduce();
	left.ToImproper();
	right.ToImproper();
	res.setNumerator(left.getNumerator()*right.getNumerator());
	res.setDenominator(left.getDenominator()*right.getDenominator());
	return res;
}
Fraction operator/(Fraction left, Fraction right)
{
	left.Reduce();
	right.Reduce();
	left.ToImproper();
	right.ToImproper();
	Fraction res
	(
		left.getNumerator()*right.getDenominator(),
		left.getDenominator()*right.getNumerator()
	);
	return res;
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.getInteger() != 0)cout << obj.getInteger();
	if (obj.getNumerator() != 0)
	{
		if (obj.getInteger()) cout << "(";
		cout << obj.getNumerator() << "/" << obj.getDenominator();
		if (obj.getInteger()) cout << ")";
	}
	if (obj.getInteger() == 0 && obj.getNumerator() == 0)
	{
		cout << 0;
	}
	return os;
}