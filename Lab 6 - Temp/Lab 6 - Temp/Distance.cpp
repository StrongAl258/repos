#include <iostream>
#include <cmath>
#include <vector>
#include<array>
using namespace std;

class Real {
    double a;
public:
    size_t dim() { return  1; }
    Real(double x) : a{ x } {}
    double& operator[](int x) {
        array<double, 1> r;
        r[0] = a;
        return r[x];
    }
};

class Complex {
    double a;
    double b;
public:
    size_t dim() { return  2; }
    Complex(double x, double y) : a{ x }, b{ y } {}
    double operator[](int x) {
        array<double, 2> com;
        com[0] = a;
        com[1] = b;
        return com[x];
    }
};

class Vector3D {
    vector <double> vec;
public:
    size_t dim() { return  3; }
    Vector3D(double a, double b, double c) {
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
    }
    double operator[](int x) {
        return vec[x];
    }
};


template<typename A>
double distance(A x, A y) {
    double r = 0;
    for (int i = 0; i < x.dim(); i++) {
           r = r + pow(x[i] - y[i], 2);
    }
    return pow(r, .5);
}


int main()
{
    Real n1{ 1.0 }, n2{ 2.0 };
    Complex c1{ 1.0, 2.0 }, c2{ 2.0, 1.0 };
    Vector3D v1{ 1.0, 2.0, 3.0 }, v2{ 3.0, 2.0, 1.0 };

    cout << "Distance between n1 and n2 is " << distance(n1, n2) << endl;
    cout << "Distance between c1 and c2 is " << distance(c1, c2) << endl;
    cout << "Distance between v1 and v2 is " << distance(v1, v2) << endl;

    return 0;
}