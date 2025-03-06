#include <iostream>
using namespace std;

int main(){
	
	
	//Arithmatic Operators
	
	int x = 5 , y = 3 ;
	
	int sum =  x + y ; // sum = 8
	int diff = x - y ; // diff = 2
	int product = x * y ; // product = 15
	int div = x / y ; // div = 1
	int rem = x % y ; // remainder = 2
	
//	 Assignment Operators

    x += y;  //8
	x -= 1;    //4
	x *= 1 ;   //5
	x /= 1  ;  //5 
	x %= 1   ; //0
	
  // Comparsion Operators

	bool eq =  x == y ; // false
//	cout << eq;
	bool neg =  x != y; // neg = true
//	cout << neg;
	bool lt = x < y ; // lt = false
	bool gt = x > y ;  // gt = true
	bool lteq =  x <= y ;  //lteq = false
	bool gteq =  x >= y ;  //lteq = false
	cout << gteq;
	
	// Logical Operators
	
	bool a = true , b = false , c = true;
	
	bool andResult =  a && b ; // andResult = faLse
	bool orResult =  a || b ; // orResult = true
	bool notResult =  !a ; // notResult = faLse
	
	return 0;
}
