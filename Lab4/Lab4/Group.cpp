#include <iostream>
using namespace std;

class Real {

protected:
    double x = 0.0;
public:
    Real() {};
    Real(double a) {
        x = a;
    }
    Real operator/(const Real& a) {
        return this->x / a.x;
    }
    friend ostream& operator<<(ostream& o, const Real& a) {
        o << a.x;
        return o;
    }
    Real operator-(const Real& a) {
        return x - a.x;
    }
    Real operator+(const Real& a) {
        return x + a.x;
    }
    Real operator*(const Real& a) {
        return x * a.x;
    }
    Real operator>(double a) {
        return x > a;
    }
    double getReal() {
        return x;
    }

};

class Complex : private Real {
    Real l;
    Real r;
public:
    Complex() {}
    Complex(double a, double b) : l(a), r(b) {}
    Complex(Real a, Real b) : l(a), r(b) {}

    friend ostream& operator<<(ostream& o, const Complex& a) {

        if (a.l.x > 0.0)
            o << a.l << '+' << a.r << 'i';
        else
            o << a.l << a.r << 'i';
        return o;
    }
    Complex operator*(Complex& a) {
        
        Complex tt((l.getReal() * a.l.getReal() + (r.getReal() * a.r.getReal() * -1)), (l.getReal() * a.l.getReal() + r.getReal() * a.l.getReal()));
        return tt;
    }

};

class Trinomial : public Real {
    Real l;
    Real m;
    Real r;
public:
    Trinomial(double a, double b) : l(a), m(b), r(0.0) {}
    Trinomial(double a,double b, double c) : l(a), m(b), r(c) {};
    friend ostream& operator<<(ostream& o, const Trinomial& a) {
        if (a.m.getReal() > 0.0)
        o << l << "x^2+" << m << "x+" << r;
        else 
            o << l << "x^2+" << m << "x" << r;
        return o;
    }
    Trinomial operator+(const Trinomial a) {
        return Trinomial(l.getReal() + a.l.getReal(), m.getReal() + a.m.getReal(),
            r.getReal() + a.r.getReal());
    }
};



int main()
{
    Real a{ 30.0 };
    Real b{ 20.0 };
    // next line shows: 30/20 = 1.5
    cout << a << " / " << b << " = " << (a / b) << endl;

    Complex d{ 3.0, 1.0 };  // 3 + i
    Complex e{ 2.0, -2.0 }; // 2 - 2i
    // next line shows: (3+1i)*(2-2i) = 8-4i
    cout << "(" << d << ") * (" << e << ") = " << (d * e) << endl;
    Trinomial h{ 2,1,1 };    // 2x^2+1x+1
    Trinomial i{ 1,-1,0 };   // 1x^2-1x
    // next line shows: (2x^2+1x+1) + (1x^2-1x) = 3x^2+1
    cout << "(" << h << ") + (" << i << ") = " << (h + i) << endl;

}

