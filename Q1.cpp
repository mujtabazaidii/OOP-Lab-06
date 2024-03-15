#include<iostream>
#include<corecrt_math.h>
using namespace std;
class Complex {
	int* real;
	int* imaginary;
public:
	Complex(int x = 0, int y = 0) {
		real = &x;
		imaginary = &y;
	}
	void Input(int x,int y) {
		real = &x;
		imaginary = &y;
	}
	int* getReal() {
		return real;
	}
	int* getImaginary() {
		return imaginary;
	}
	void Output() {
		cout << "Complex Number =  " << *real << " + " << *imaginary << "i " << endl << endl;
	}
	float Magnitude() {
		int x, y;
		x = *real;
		y = *imaginary;
		x = x*x;
		y = y*y;
		int z = x + y;
		float Magnitude = sqrt(z);
		cout <<"Magnitude = " << Magnitude;
		return Magnitude;
	}
	~Complex() {
		delete[]real;
		delete[]imaginary;
	}
};
int main() {
	Complex c1, cPtr;
	cPtr.Output();
	c1.Input(4, 6);
	c1.Output();
	cout << endl;
	Complex *c = new Complex(3,5);
	cPtr = *c;
	cPtr.Output();
	cPtr.Magnitude();
	cout << endl << endl;
	Complex s[5];
	Complex s1[5];
	int a, b;
	for (int i = 0; i < 5; i++) {
		cin >> a >> b;
		s[i].Input(a, b);
		s[i].Output();
		s[i].Magnitude();
		cout << endl << endl;
	}




	cout << endl << endl << endl;
	return 0;
}