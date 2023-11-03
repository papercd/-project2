#ifndef _INF_INT_H_ 
#define _INF_INT_H_ 

#include <iostream>
using namespace std; 

class inf_int
{
private:
    string digits; // char* digits;  // You may modify this to "string digits;" if you want.
    unsigned int length;
    bool thesign;   // true if positive , false if negative.
    void add(char num,int pos) {
        while (length < pos)
        {
            digits.append("0");
            length++;
        }
        if (int(digits[pos-1])+int(num)-96 >= 10)
        {
            digits[pos - 1] = char(int(digits[pos - 1]) + int(num) - 48 - 10);
            this->add('1', pos + 1);
        }
        else
        {
            digits[pos - 1] = char(int(digits[pos - 1]) + int(num) - 48);
        }
    }
    void sub(char num,int pos){

    }
    // ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
    // ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
    // You may modify or add private members of inf_int class. So, it is OK to insert Add() private member function in inf_int class. However, You may not modify public members of inf_int class.

public:
    inf_int();               // assign 0 as a default value
    inf_int(int n);
    inf_int(const string str);   // you may modify this to "inf_int(const string);"
    inf_int(const inf_int& base); // copy constructor
    ~inf_int(); // destructor

    inf_int& operator=(const inf_int& a); // assignment operator

    friend bool operator==(const inf_int& a, const inf_int& b);
    friend bool operator!=(const inf_int& a, const inf_int& b);
    friend bool operator>(const inf_int& a, const inf_int& b);
    friend bool operator<(const inf_int& a, const inf_int& b);

    friend inf_int operator+(const inf_int& a, const inf_int& b);
    
    friend inf_int operator-(const inf_int& a, const inf_int& b);
    
    friend inf_int operator*(const inf_int& a, const inf_int& b);
    // friend inf_int operator/(const inf_int& , const inf_int&); // not required

    friend ostream& operator<<(ostream& out, const inf_int& a);
    // friend istream& operator>>(istream& , inf_int&);    // not required
};



#endif 