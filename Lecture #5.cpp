#include <iostream>
#include <typeinfo>
using namespace std;


int main(){
	
	int num1 = 5;
	float num2 ;
	
	num2 =  num1;
	
	cout << typeid(num1).name() << endl;
	cout << typeid(num2).name() << endl;
	
	cout << num2;

	return 0;
}
