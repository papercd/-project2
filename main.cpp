#include<iostream>
#include "inf_int.h"

using namespace std; 

int main() {

	inf_int a("-671");
	inf_int b("8");
	a = a * b;
	
	cout << a;
	return 0;
}