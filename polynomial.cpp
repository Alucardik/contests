#include "polynomial_dense.h"

template <typename T>
void printIt(const Polynomial<T>& p) {
    if (p.begin() == p.end()) {
        std::cout << "0\n";
        return;
    }
    for (auto it = p.begin(); it != p.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

template <typename T>
void print(const Polynomial<T>& p) {
    if (p.Degree() == -1) {
        std::cout << "0\n";
        return;
    }
    for (size_t i = 0; i <= p.Degree(); ++i)
        std::cout << p[i] << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> v1={0, 9, 2, -1, 1, 1, 2, 0, 0, 0}, v2={-1, 2, 1, 1, 0, 0, 2},
        v3={1, 2, 3}, v4={2, 1}, v0={0,0,0,0,0,0,0}, v5={0, 0, 0, 0, -2};
    Polynomial<int> p1(v1), p2(42), p3, p4(v2.begin()+2, v2.end()), p5(v3), p6(v4),
        p7(v3.rbegin()+1, v3.rend()), p8(v1.begin(), v1.begin()+7), p0(v0), p10(v5), p11(0);

    std::cout << "p1 = 2*x^6+x^5+x^4-x^3+2*x^2+9*x\np2 = 42\np3 = 0\np4 = 2*x^4+x+1\np5 = 3*x^2+2*x+1\np6 = x+2\np7 = x+2\np8 = 2*x^6+^5+x^4-x^3+2*x^2+9*x\n\n";

    std::cout << "p6[20] = " << p6[20] << "\n\n";
    std::cout << "p3[0] = " << p3[0] << "\n\n";
    std::cout << "p1[2] = " << p1[2] << "\n\n";

    std::cout << "p6 == p7: 1\n" << (p6 == p7) << "\n\n";
    std::cout << "p3 == p7: 0\n" << (p3 == p7) << "\n\n";
    std::cout << "p1 == p4: 0\n" << (p1 == p4) << "\n\n";
    std::cout << "p1 == p8: 1\n" << (p1 == p8) << "\n\n";

    std::cout << "p3: 0 = "; printIt(p3);
    std::cout << "p11: 0 = "; printIt(p11);
    std::cout << "\n";

    auto p9 = p1 - p1;
    std::cout << "p9 = p1 - p1: "; print(p9);
    std::cout << "\n";

    std::cout << "p1: "; print(p1);
    std::cout << "p2: "; printIt(p2);
    std::cout << "p1 + p2: "; print(p1 + p2);
    std::cout << "\n";

    std::cout << "p4: "; print(p4);
    std::cout << "p4+2: "; print(p4+2);
    std::cout << "2+p4: "; print(2+p4);
    std::cout << "p4: "; print(p4);
    std::cout << "\n";

    std::cout << "p3: "; print(p3);
    std::cout << "p5: "; print(p5);
    std::cout << "p5+p3: "; print(p5+p3);
    std::cout << "p3+p5: "; print(p3+p5);
    std::cout << "p3: "; print(p3);
    std::cout << "p5: "; print(p5);
    std::cout << "\n";

    std::cout << "p10: "; print(p10);
    std::cout << "p4: "; print(p4);
    std::cout << "p4+p10: "; print(p4+p10);
    std::cout << "p10-p4: "; print(p10-p4);
    std::cout << "\n";


    std::cout << "p1: "; print(p1);
    std::cout << "p6: "; print(p6);
    std::cout << "p1+p6: "; print(p1+p6);
    std::cout << "p6+p1: "; print(p6+p1);
    std::cout << "p1: "; print(p1);
    std::cout << "p6: "; print(p6);
    std::cout << "\n";

    std::cout << "p4(3) = 166\n" << p4(3) << "\n\n";
    std::cout << "p3(1234) = 0\n" << p3(1234) << "\n\n";
    std::cout << "p1(-2) = 110\n" << p1(-2) << "\n\n";
    std::cout << "p6(0) = 2\n" << p6(0) << "\n\n";

    p7 -= (p6 + p6);
    p7 += p6;
    p7 -= p6;

    std::cout << "p1=" << p1 << "\n"
              << "p2=" << p2 << "\n"
              << "p3=" << p3 << "\n"
              << "p4=" << p4 << "\n"
              << "p5=" << p5 << "\n"
              << "p6=" << p6 << "\n"
              << "p7=" << p7 << "\n\n";

    std::cout << "(" << p1 << ")*(" << p2 << ")=" << p1*p2 << "\n\n";
    std::cout << "(" << p2 << ")*(" << p1 << ")=" << p2*p1 << "\n\n";
    std::cout << "(" << -3 << ")*(" << p4 << ")=" << (-3)*p4 << "\n\n";
    std::cout << "(" << p4 << ")*(" << 0 << ")=" << p4*0 << "\n\n";
    std::cout << "(" << p3 << ")*(" << p2 << ")=" << p3*p2 << "\n\n";
    std::cout << "(" << p6 << ")*(" << p3 << ")=" << p6*p3 << "\n\n";
    std::cout << "(" << p4 << ")*(" << p5 << ")=" << p4*p5 << "\n\n";
    std::cout << "(" << p5 << ")*(" << p6 << ")=" << p5*p6 << "\n\n";
    std::cout << "(" << p1 << ")*(" << p7 << ")=" << p1*p7 << "\n\n";
    std::cout << "(" << p6 << ")*(" << p6 << ")=" << p6*p6 << "\n\n";

    p7 *= Polynomial<int>(-1);
    std::cout << "1 = " << (p7 == p6) << "\n\n";

    std::cout << "p6 *= p6,   p6=(" << p6 << ")^2=";
    p6 *= p6;
    std::cout << p6 << "\n\n";

    std::vector<int> o1={1, 2, 3, 4, 1, -1};
    Polynomial<int> out1(o1), out2 = -1 * out1;
    std::cout << "-x^5+x^4+4*x^3+3*x^2+2*x+1 = " << out1 << "\n\n";
    std::cout << "x^5-x^4-4*x^3-3*x^2-2*x-1 = " << out2 << "\n\n";
}

