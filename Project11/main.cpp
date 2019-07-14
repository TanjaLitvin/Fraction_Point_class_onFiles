#include<iostream>
using namespace std;

class Fraction
{
	int Integer;    //целая
	int Numerator;  //числитель
	int Denominator;//знаменатель
public:
	int getInteger()const
	{
		return this->Integer;
	}
	int getNumerator()const
	{
		return this->Numerator;
	}
	int getDenominator()const
	{
		return this->Denominator;
	}
	void setInteger(int Integer)
	{
		this->Integer = Integer;
	}
	void setNumerator(int Numerator)
	{
		this->Numerator = Numerator;
	}
	void setDenominator(int Denominator)
	{
		if (Denominator == 0)this->Denominator = 1;
		else this->Denominator = Denominator;
	}
	//Constructors:
	Fraction()
	{
		this->Integer = 0;
		this->Numerator = 0;
		this->Denominator = 1;
		cout << "DefConstruct:\t" << this << endl;
	}
	Fraction(int Integer)
	{
		this->Integer = Integer;
		this->Numerator = 0;
		this->Denominator = 1;
		cout << "SingleArgConstruct:" << this << endl;
	}
	Fraction(int Numerator, int Denominator)
	{
		this->Integer = 0;
		this->Numerator = Numerator;
		this->Denominator = Denominator;
		cout << "Construct:\t" << this << endl;
	}
	Fraction(int Integer, int Numerator, int Denominator)
	{
		this->Integer = Integer;
		this->Numerator = Numerator;
		this->Denominator = Denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->Integer = other.Integer;
		this->Numerator = other.Numerator;
		this->Denominator = other.Denominator;
		cout << "CopyConstruct:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->Integer = other.Integer;
		this->Numerator = other.Numerator;
		this->Denominator = other.Denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	//Methods:
	void ToProper()
	{
		//переводит дробь в правильную
		Integer += Numerator / Denominator;
		Numerator %= Denominator;//Numerator=Numerator%Denominator
	}
	void ToImproper()
	{
		//переводит дробь в неправильную.это нужно для операций умножения 
		//и деления дробей
		Numerator += Integer * Denominator;
		Integer = 0;
	}
	void Reduce()
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


	void Print()const
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
};
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

void main()
{
	setlocale(LC_ALL, "");
	//Fraction a(5,1,2);
	///*a.setNumerator(1);
	//a.setDenominator(0);
	//cout << a.getNumerator() / a.getDenominator() << endl;*/
	//a.Print();
	//Fraction b = a;
	//b.Print();
	//b.ToImproper();
	//b.Print();
	//b.ToProper();
	//b.Print();
	/*Fraction a(3, 100, 200);
	a.Print();
	a.Reduce();
	a.Print();
	Fraction b(5, 240, 100);
	b.Print();
	b.Reduce();
	b.Print();
	Fraction c(840,3600);
	c.Print();
	c.Reduce();
	c.Print();*/

	int a = 2;
	int b = 3;
	a + b;
	Fraction A(1, 2);
	Fraction B(3, 4);
	/*Fraction C = A * B;
	C.Print();
	C = A / B;
	C.Print();*/
	cout << A << endl;

}
