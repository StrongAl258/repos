#include <iostream>
#include "mixed.h"

int main()
{
	Mixed m0(1, 1, 1);
	m0.Simplify();
	cout << m0 << endl;
	m0.ToFraction();
	cout << m0 << endl;
	Mixed m1(1, 2, 3);
	m1.Print();
	cout << m1++ << endl;
	cout << ++m1 << endl;
	Mixed m2(2, 5, 3);
	cout << m2 << endl;
	cout << m2.Evaluate() << endl;
	m2.Simplify();
	cout << m2 << endl;
	Mixed m3 = m1 + m2;
	cout << m3 << endl;
	cout << m3.Evaluate() << endl;
	Mixed m4(1, 2, 3);
	m4.ToFraction();
	cout << m4 << endl;
	Mixed m5 = m4 + Mixed(1);
	cout << m5 << endl;
	Mixed m6(1);
	cout << m6 << endl;
	m6.ToFraction();
	cout << m6 << endl;
	cout << m6 - m4 << endl;
	Mixed m7(0, 3, 4);
	cout << m5 * m7 << endl;
	cout << m5 / m7 << endl;
	cout << "m4 == m4: " << boolalpha << (m4 == m4) << endl;
	cout << "m5 != m4: " << boolalpha << (m5 != m4) << endl;
	cout << "m5 > m4: " << boolalpha << (m5 > m4) << endl;
	cout << "m5 >= m4: " << boolalpha << (m5 >= m4) << endl;
	cout << "m4 < m5: " << boolalpha << (m4 < m5) << endl;
	cout << "m4 <= m4: " << boolalpha << (m4 <= m4) << endl;


}