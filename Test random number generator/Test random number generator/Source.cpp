#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 1000000);
    int a = dist(mt);
    std::cout << a << '\n';
}