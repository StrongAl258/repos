#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
#include <vector>
using namespace std;

template <typename T, unsigned int N>
class BoundedDynamicArray {
private:
    vector<unique_ptr <T>> arr;
public:
    void push_back(T* v) {
        if (arr.size() == 3)
            throw out_of_range("Array is full");  
        arr.emplace_back(v);
    }
    T& operator[](unsigned int i) {
        return *arr[i];
    }
};

class Resource {
    static int count;
    int id{ 0 };
    int used{ 0 };
public:
    Resource() { id = (count++) + 1; }
    void use() { used++; cout << "Use resource " << id << " was used " << used << " times" << endl; }
    ~Resource() { used = 0; cout << "Delete resource " << id << endl; }
};

int Resource::count = 0;

int main() {
    const int ArraySize = 3;
    BoundedDynamicArray<Resource, ArraySize> arr;
    arr.push_back(new Resource());
    arr[0].use();
    try {
        arr.push_back(new Resource());
        arr[1].use();
        arr.push_back(new Resource());
        arr.push_back(new Resource());
    }
    catch (out_of_range & ex) {
        cout << "Problem: ";
        cout << ex.what() << endl;
    }
    arr[1].use();
    arr[2].use();

    return 0;
}
