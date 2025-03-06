#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number for the multiplication table: ";
    cin >> n;

    cout << "Multiplication Table for " << n << ":" << endl;
    
    int i = 1 ;
    
    while (i <=20 ){
    	
    	cout << n << " * " << i << " = " << n * i << endl;
    	
    	i++;
    	
	}

	
    

    return 0;
}

