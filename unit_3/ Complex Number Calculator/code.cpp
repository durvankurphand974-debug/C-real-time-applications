#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    // Operator overloading for +
    Complex operator+(const Complex& c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // Operator overloading for -
    Complex operator-(const Complex& c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // Operator overloading for *
    Complex operator*(const Complex& c)
    {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Display complex number
    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main()
{
    Complex c1(4, 3);
    Complex c2(2, 5);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    cout << "Multiplication: ";
    product.display();

    return 0;
}
