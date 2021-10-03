#include <iostream>
#include "Mixed.h"
using namespace std;

int main() {
    Mixed m0(1, 1, 1);     //  1 1/1 == 2
    m0.Simplify();
    cout << m0 << endl;    //  prints 2
    m0.ToFraction();
    cout << m0 << endl;    //  prints 2/1
    Mixed m1(1, 2, 3);	   //  1 2/3
    m1.Print();            //  prints 1 2/3
    cout << m1++ << endl;  //  prints 1 2/3, m1 is now 2 2/3
    cout << ++m1 << endl;  //  prints 3 2/3, m1 is now 3 2/3
    Mixed m2(2, 5, 3);	   //  2 5/3
    cout << m2 << endl;    //  prints 2 5/3
    cout << m2.Evaluate() << endl; //  prints 3.6666
    m2.Simplify();         //  m2 is now 3 2/3
    cout << m2 << endl;    //  prints 3 2/3
    Mixed m3 = m1 + m2;    //  m3 is now 7 1/3
    cout << m3 << endl;    //  prints 7 1/3
    cout << m3.Evaluate() << endl; //  prints 7.3333
    Mixed m4(1, 2, 3);	   //  1 2/3
    m4.ToFraction();
    cout << m4 << endl;    //  prints 5/3
    Mixed m5 = m4 + Mixed(1);
    cout << m5 << endl;    //  prints 2 2/3
    Mixed m6(1);
    cout << m6 << endl;    //  prints 1
    m6.ToFraction();
    cout << m6 << endl;    //  prints 1
    cout << m6 - m4 << endl; //  prints -2/3
    Mixed m7(0, 3, 4);
    cout << m5 * m7 << endl; //  prints 2 (= 8/3 * 3/4)
    cout << m5 / m7 << endl; //  prints 3 5/9 (32/9 = 8/3 * 4/3)
    cout << "m4 == m4: " << boolalpha << (m4 == m4) << endl;
    cout << "m5 != m4: " << boolalpha << (m5 != m4) << endl;
    cout << "m5 > m4: " << boolalpha << (m5 > m4) << endl;
    cout << "m5 >= m4: " << boolalpha << (m5 >= m4) << endl;
    cout << "m4 < m5: " << boolalpha << (m4 < m5) << endl;
    cout << "m4 <= m4: " << boolalpha << (m4 <= m4) << endl;
}