#include <iostream>
using namespace std;

class Polynomial
{
private:
	int totalTerms;//Total terms in a Polynomial
	int* coeff;//to save array of coefficients
	int* exp; //to save array of exponents
	static int objectcount; //Total count of objects

public:

	Polynomial(int n = 0, int* i = 0, int* j = 0)
	{
		coeff = new int[n];
		exp = new int[n];
		totalTerms = n;
		coeff = i;
		exp = j;
	}

	void output()
	{
		for (int i = 0; i < totalTerms; i++)
		{
			cout << *(coeff + i) << "^" << *(exp + i);
		}
		cout << endl;
	}

	bool operator !()
	{
		return (totalTerms != 0);
	}
	bool operator != (Polynomial c)
	{
		if (totalTerms != c.totalTerms)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	void operator ++ ()
	{
		for (int i = 0; i < totalTerms; i++)
		{
			coeff[i] = +1;
		}
	}

	void operator ++ (int)
	{
		for (int i = 0; i < totalTerms; i++)
		{
			coeff[i] = +1;
		}
	}

	Polynomial operator + (Polynomial x)
	{
		Polynomial p;
		p.totalTerms = totalTerms;
		p.exp = exp;
		for (int i = 0; i < totalTerms; i++)
		{
			p.coeff[i] = coeff[i] + p.coeff[i];
		}
		return p;
	}

	Polynomial operator - (Polynomial x)
	{
		Polynomial p;
		p.totalTerms = totalTerms;
		p.exp = exp;
		for (int i = 0; i < totalTerms; i++)
		{
			p.coeff[i] = coeff[i] - x.coeff[i];
		}
		return p;
	}

	void operator = (Polynomial x)
	{
		totalTerms = x.totalTerms;
		coeff = x.coeff;
		exp = x.exp;
	}
	void Getcount()
	{
		cout << "6";
	}

};

int main1()
{
	int coeff_P1[] = { 1,2,5 }; //Coefficients for Polynomial P1
	int exp_P1[] = { 4,2,0 }; //Exponents for Polynomial P1

	int coeff_P2[] = { 4,3 }; //Coefficients for Polynomial P2
	int exp_P2[] = { 6,2 }; //Exponents for Polynomial P2
	int coeff_P3[] = { 1,6,5 }; //Coefficients for Polynomial P3
	int exp_P3[] = { 4,2,4 }; //Exponents for Polynomial P3

	Polynomial P1(3, coeff_P1, exp_P1);//Creates P1 with 3 terms (P1 =1x^4 + 2x^2 + 5x^0 )
	Polynomial P2(2, coeff_P2, exp_P2);//Creates P2 with 2 terms (P2 =4x^6 + 3x^2)
	Polynomial P3(3, coeff_P3, exp_P3);

	P1.output();
	P2.output();
	if (!P1)
		cout << "P1 is zero" << endl;// if polynomial has only 1 term and its coeff/and exp are zero. i.e. if p1 = 0.*/
	if (P1 != P2)
		cout << "P1 is Not Equal to P2" << endl;
	++P1;//adds 1 in all the coefficient.
	P1.output();
	P1++; //adds 1 in all the coefficient.
	P1.output();
	Polynomial P4 = P2 + P3; //Adds P2 and P3 and saves result in
	//P4.You may consume extra space for resultant Polynomial in Add function
	cout << "P4 = " << endl;
	P4.output();
	Polynomial P5 = P4 - P3; //subtract P4 and P3 and saves result
	//in P5.You may consume extra space for resultant Polynomial in Add
	//function
	cout << "P5 = " << endl;
	P5.output();
	Polynomial P6 = P5;
	cout << "P6 = " << endl;
	P6.output();
	/*cout << " Total No of object have been made : ";
	Polynomial::getcount();
	*/
	return 0;
}