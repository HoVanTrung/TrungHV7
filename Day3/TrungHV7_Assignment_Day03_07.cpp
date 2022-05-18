#include <iostream>

using namespace std;

float Plus(float a, float b) {
	return a + b;
}
float Sub(float a, float b) {
	return a - b;
}
float Multifly(float a, float b) {
	return a * b;
}
float Divide(float a, float b) {
	if (b != 0)
		return a / b;
	else return NULL;
	
}
void operation(float a, float b, float(*p2Func)(float a,float b)) {
	cout << p2Func(a, b);
}
int main() {
	float a, b;
	cout << "Enter number A: ";
	cin >> a;
	cout << "Enter number B: ";
	cin >> b;
	cout << "\nPlus two number is: ";
	operation(a, b, &Plus);
	cout << "\nSub two number is: ";
	operation(a, b, &Sub);
	cout << "\nMultifly two number is: ";
	operation(a, b, &Multifly);
	cout << "\nDivide two number is: ";
	operation(a, b, &Divide);
	return 0;
}