#include <iostream>
using namespace std;

class AllKinds {
private:
	int a;
	long b;
	float c;
public:
	AllKinds(int i = 1, long l = 123456, float f = 5.5) {
		a = i;
		b = l;
		c = f;
	}
	void setInt(int x){
		a = x;
	}
	void setLong(long x) {
		b = x;
	}
	void setFloat(float x) {
		c = x;
	}
	int getInt() {
		return a;
	}
	long getLong() {
		return b;
	}
	float getFloat() {
		return c;
	}
	template <typename T>
	T addInt(T v, int x) {
		return v + x;
	}
	template <typename T>
	T addLong(T v, long x) {

		return v + x;
	}
	template <typename T>
	T addFloat(T v, float x) {
		return v + x;
	}
};

int main() {
	AllKinds one(15, 444444, 12.12);
	
	cout << "The Int: " << one.getInt() << ", The Long: " << one.getLong() << ", The Float: " 
		<< one.getFloat() << endl;
	
	one.setInt(78); one.setLong(56244); one.setFloat(54.59);

	cout << "The Int: " << one.getInt() << ", The Long: " << one.getLong() << ", The Float: " 
		<< one.getFloat() << endl;

	cout << "float + int = " <<one.addInt<float>(one.getFloat(), one.getInt()) << endl;
	cout << "float + long = " << one.addLong<float>(one.getFloat(), one.getLong()) << endl;
	cout << "int + float = " << one.addFloat<int>(one.getInt(), one.getFloat()) << endl;
	cout << "int + long = " << one.addLong<int>(one.getInt(), one.getLong()) << endl;
	cout << "long + int = " << one.addInt<long>(one.getLong(), one.getInt()) << endl;
	cout << "long + float = " << one.addFloat <long>(one.getLong(), one.getFloat()) << endl;
	return 0;
}
