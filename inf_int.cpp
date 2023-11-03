#include "inf_int.h"

//default constructor sets initial value as 0  
inf_int::inf_int() {
	digits += '0';
	length = 1;
	thesign = true; 
}

//constructor when integer is given 
inf_int::inf_int(int n) {
	if (n < 0)
	{
		thesign = false; 
		n = -n;
	}
	else
	{
		thesign = true;
	}
	int count = 0;
	while (n>0)
	{
		digits += char(n % 10 + 48);
		n /= 10;
		count++; 
	}

	//�Է��� 0�϶� 
	if (count == 0)
	{
		digits += '0';
		length = 1;
		thesign = true;
	}
	else
	{
		length = count; 
	}
}

//constructor when string is given
inf_int::inf_int(const string str) {
	if (str[0] == '-')
	{
		thesign = false;
		for (int i = str.length() - 1; i >0; i--)
		{
			digits += str[i];
		}
		length = str.length() - 1;
	}
	else {
		thesign = true;
		for (int i = str.length()-1; i >= 0; i--)
		{
			digits += str[i];
		}
		length = str.length();
	}
}


//copy constructor 
inf_int::inf_int(const inf_int& base) {
	this->digits = base.digits;
	this->length = base.length; 
	this->thesign = base.thesign;
}

inf_int::~inf_int() {
	digits.erase();
}

inf_int& inf_int :: operator=(const inf_int& a) {
	this->digits = a.digits;
	this->length = a.length; 
	this->thesign = a.thesign; 

	return *this;
}


bool operator==(const inf_int& a, const inf_int& b) {
	return a.digits.compare(b.digits) && a.thesign == b.thesign;
}
bool operator!=(const inf_int& a, const inf_int& b) {
	return !operator==(a,b); 
}
bool operator>(const inf_int& a, const inf_int& b) {
	if (a.thesign == b.thesign)
	{
		if (a.length > b.length)
		{
			return true; 
		}
		else if (a.length < b.length) {
			return false;
		}
		else {
			for (int i = a.length-1; i >= 0 ; i--)
			{
				if (a.digits[i] != b.digits[i]) {
					return a.digits[i] > b.digits[i];
				}
			}
			return false;
		}
	}
	else {
		if (a.length > b.length)
		{
			return false;
		}
		else if (a.length < b.length) {
			return true;
		}
		else {
			for (int i = a.length - 1; i >= 0; i--)
			{
				if (a.digits[i] != b.digits[i]) {
					return a.digits[i] < b.digits[i];
				}
			}
			return false;
		}
	}
}
bool operator<(const inf_int& a, const inf_int& b) {
	if (operator>(a, b) || operator==(a, b))
	{
		return false;
	}
	else return true;
}

inf_int operator+(const inf_int& a, const inf_int& b) {

	inf_int c;

	if (a.thesign ==b.thesign)
	{
		for (int i = 0; i < a.length; i++)
		{
			
			c.add(a.digits[i],i+1);
		}
		for (int i = 0; i < b.length; i++)
		{
		
			c.add(b.digits[i], i + 1);
		}
		c.thesign = a.thesign; 
		
		return c; 
	}
	else
	{
		c = b;
		c.thesign = a.thesign;
		return a - c;
	}
}
inf_int operator-(const inf_int& a, const inf_int& b) {
	
	inf_int c;
	
	if (a.thesign != b.thesign)
	{
		c = b;
		c.thesign = a.thesign;
		return a + c;
	}
	else
	{
		if (a.thesign == true)
		{
			c = b;
			while (c.length < a.length)
			{
				c.digits += '0';
				c.length++;
			}
			c.digits += '0';
			c.length++; 
			for (int i = 0; i <c.length-1; i++)
			{
				if (c.digits[i] != '0')
				{
					c.digits[i] = char(106-c.digits[i]);
					c.add('1',i+2);
				}
			}
			
			c.digits[c.length-1] ='0'; 
			for (int i = 0; i < a.length; i++)
			{
				c.add(a.digits[i],i+1);
			}
			
			
			if (c.digits[c.length-1] == '1')
			{
				c.digits.pop_back();
				c.length--;
				while (c.digits[c.length-1] == '0')
				{
					c.digits.pop_back();
					c.length--;
				}
				c.thesign = true;
				return c; 
			}else{
				
				for (int i = 0; i < c.length-1; i++)
				{
					if (c.digits[i] != '0')
					{
						
						c.digits[i] = char(106-c.digits[i]);
						c.add('1',i+2);
					}
					
				}
				c.digits.pop_back();
				c.length--;
				
				while (c.digits[c.length - 1] == '0')
				{
					c.digits.pop_back();
					c.length--;

				}
				c.thesign = false;
				return c;
			}
		}
		else {
			c = a;
			while (c.length < b.length)
			{
				c.digits += '0';
				c.length++;
			}
			c.digits += '0';
			c.length++;
			for (int i = 0; i < c.length - 1; i++)
			{
				if (c.digits[i] != '0')
				{
					c.digits[i] = char(106 - c.digits[i]);
					c.add('1', i + 2);
				}
			}

			c.digits[c.length - 1] = '0';
			for (int i = 0; i < b.length; i++)
			{
				c.add(b.digits[i], i + 1);
			}


			if (c.digits[c.length - 1] == '1')
			{
				c.digits.pop_back();
				c.length--;
				while (c.digits[c.length - 1] == '0')
				{
					c.digits.pop_back();
					c.length--;
				}
				c.thesign = true;
				return c;
			}
			else {

				for (int i = 0; i < c.length - 1; i++)
				{
					if (c.digits[i] != '0')
					{

						c.digits[i] = char(106 - c.digits[i]);
						c.add('1', i + 2);
					}

				}
				c.digits.pop_back();
				c.length--;

				while (c.digits[c.length - 1] == '0')
				{
					c.digits.pop_back();
					c.length--;

				}
				c.thesign = false;
				return c;
			}
		}
	}
}

inf_int operator*(const inf_int& a, const inf_int& b) {
	inf_int c; 

	for (int i = 0; i < b.length; i++)
	{
		int count = b.digits[i] -48;
		for (int k = 0; k < count; k++)
		{
			for (int j = 0; j < a.length; j++)
			{
				c.add(a.digits[j], j + 1+i);
			}
		}
	}

	if (a.thesign != b.thesign)
	{
		c.thesign = false;
	}
	else c.thesign = true; 
	
	return c; 
}

ostream& operator<<(ostream& out, const inf_int& a) {
	if (a.thesign == false)
	{
		out << '-';
	}
	for (int i = a.length-1; i >=0; i--)
	{
		out << a.digits[i];
	}
	return out;
}
