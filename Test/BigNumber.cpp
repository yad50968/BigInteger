//
//  BigNumber.cpp
//  BigNumber
//
//  Created by Liu Tzu Yuan on 2017/2/20.
//  Copyright © 2017年 Liu Tzu Yuan. All rights reserved.
//

#include "BigNumber.hpp"

BigNumber::BigNumber ()
{
    number = "0";
    sign = false;
}

BigNumber::BigNumber(string s) {
    
    if(checkString(s)) {
        if(s[0] == '-') {
            setSign(true);
            setNumber(s.substr(1));
        } else {
            setSign(false);
            setNumber(s);
        }
    } else {
        cout << "wrong string" << endl;
    }
}

void BigNumber::setNumber(string s) {
    number = s;
}

const string& BigNumber::getNumber() {
    return number;
}

void BigNumber::setSign(bool s) {
    sign = s;
}

const bool& BigNumber::getSign() {
    return sign;
}


const string BigNumber::getString() {
    string signedString = getSign() ? "-" : "";
    signedString += getNumber();
    return signedString;
}



BigNumber BigNumber::getAbsolute() {
    BigNumber result;
    result.setSign(false);
    result.setNumber(this->getNumber());
    
    return result;
}


// convert to abs
void BigNumber::absolute() {
    setSign(false);
}

void BigNumber::operator = (BigNumber input) {
    setNumber(input.getNumber());
    setSign(input.getSign());
}

bool BigNumber::operator == (BigNumber input) {
    return equals((*this) , input);
}

bool BigNumber::operator != (BigNumber input) {
    return ! equals((*this) , input);
}
bool BigNumber::operator > (BigNumber input) {
    
    return greater((*this) , input);
}


bool BigNumber::operator < (BigNumber input) {
    
    return less((*this) , input);
    
}
bool BigNumber::operator >= (BigNumber input) {
    
    return equals((*this) , input) || greater((*this), input);
}

bool BigNumber::operator <= (BigNumber input) {
    
    return equals((*this) , input) || less((*this), input);
}

BigNumber BigNumber::operator +(BigNumber input) {
    
    BigNumber result;
    
    if(getSign() == input.getSign()) {
        
        result.setSign(getSign());
        result.setNumber(add(getNumber(), input.getNumber()));
        
    } else {
        if( this->getAbsolute() > input.getAbsolute() ) {
            result.setNumber( sub(getNumber(), input.getNumber() ) );
            result.setSign( getSign() );
        } else if( this->getAbsolute() < input.getAbsolute() ){
            result.setNumber( sub(input.getNumber(), getNumber() ) );
            result.setSign( input.getSign() );
        } else {
            result.setNumber("0");
            result.setSign(false);
            
        }
    }
    
    return result;
}

BigNumber BigNumber::operator -(BigNumber input) {
    
    // x - y = x + (-y)
    BigNumber tmp = input;
    tmp.setSign(!tmp.getSign());
    
    return (*this) + tmp;
    
}

BigNumber BigNumber::operator *(BigNumber input) {
    BigNumber result;
    
    result.setNumber(mul(getNumber(), input.getNumber()));
    
    
    if(result.getNumber() == "0") // avoid (-0) problem
        result.setSign(false);
    else
        result.setSign( getSign() != input.getSign() );
    
    return result;
}

BigNumber BigNumber::operator / (BigNumber input)
{
    long long int den = toInt( input.getNumber() );
    BigNumber result;
    
    
    result.setNumber( div(getNumber(), den).first );
    
    if(result.getNumber() == "0") // avoid (-0) problem
        result.setSign(false);
    else
        result.setSign( getSign() != input.getSign() );
    
    
    return result;
}
//-------------------------------------------------------------
// Warning: Denomerator must be within "long long" size not "BigInteger"
BigNumber BigNumber::operator % (BigNumber input)
{
    long long int den = toInt( input.getNumber() );
    
    BigNumber result;
    long long int rem_int = div(number, den).second;
    result.setNumber( toString(rem_int) );
    
    if(result.getNumber() == "0") // avoid (-0) problem
        result.setSign(false);
    else
        result.setSign( getSign() != input.getSign() );
    
    return result;
}

//pair(qutiont, remainder)
pair<string, long long int> BigNumber::div(string s, long long int in) {
    
    
    long long int reminder = 0;
    string result;
    result.resize(10000);
    
    for(long long int i=0, len = s.length(); i<len; ++i) {
        reminder = (reminder * 10) + (s[i] - '0');
        result[i] = reminder / in + '0';
        reminder %= in;
    }
    result.resize( s.length() );
    
    while(result[0] == '0' && result.length() != 1)
        result.erase(0,1);
    
    if(result.length() == 0)
        result = "0";
    
    return make_pair(result, reminder);
    
}

BigNumber& BigNumber::operator += (BigNumber input) {
    (*this) = (*this) + input;
    return (*this);
}

BigNumber& BigNumber::operator -= (BigNumber input) {
    (*this) = (*this) - input;
    return (*this);
}

BigNumber& BigNumber::operator *= (BigNumber input) {
    (*this) = (*this) * input;
    return (*this);
}

BigNumber& BigNumber::operator /= (BigNumber input) {
    (*this) = (*this) / input;
    return (*this);
}

BigNumber& BigNumber::operator %= (BigNumber input) {
    (*this) = (*this) % input;
    return (*this);
}
BigNumber::operator string() {
    string signedString = getSign() ? "-" : "";
    signedString += getNumber();
    return signedString;
}

bool BigNumber::checkString(const string& str) {
    
    regex input_regex("-?[0-9]*");
    if(regex_match(str, input_regex))
        return true;
    else
        return false;
}

string BigNumber::add(string n1, string n2) {
    string result = (n1.length() > n2.length()) ?  n1 : n2;
    
    int carry = 0;
    int differenceInLength = abs( (int) (n1.size() - n2.size()) );
    
    if(n1.size() > n2.size())
        n2.insert(0, differenceInLength, '0'); // put zeros from left
    
    else if(n1.size() < n2.size())
        n1.insert(0, differenceInLength, '0');
    
    for(long i = n1.size() - 1; i >= 0; --i) {
        
        int tmp = carry + (n1[i] - '0') + (n2[i] - '0');
        
        carry = tmp / 10;
        result[i] = tmp % 10 + '0';
        
    }
    if(carry) {
        result = "1" + result;
        
    }
    return result;
}


string BigNumber::sub(string n1, string n2) {
    
    string result = (n1.length() > n2.length()) ?  n1 : n2;
    
    int differenceInLength = abs( (int)(n1.size() - n2.size()) );
    if(n1.size() > n2.size())
        n2.insert(0, differenceInLength, '0'); // put zeros from left
    else
        n1.insert(0, differenceInLength, '0');
    
    
    for(long i = n1.length() - 1; i >= 0; --i) {
        if(n1[i] < n2[i]) {
            n1[i] += 10;
            n1[i-1]--;
        }
        result[i] = ( (n1[i] - '0') - (n2[i] - '0') ) + '0';
    }
    
    while(result[0] == '0' && result.length() != 1)
        // erase leading zeros
        result.erase(0,1);
    
    return result;
}

string BigNumber::mul(string n1, string n2) {
    
    if(n1.length() > n2.length())
        n1.swap(n2);
    
    string result = "0";
    for(long i = n1.length() - 1; i >= 0; --i) {
        string temp = n2;
        int currentDigit = n1[i] - '0';
        int carry = 0;
        
        for(long j = temp.length() - 1; j >= 0; --j) {
            temp[j] = ((temp[j] - '0') * currentDigit) + carry;
            
            carry = temp[j] / 10;
            temp[j] %= 10;
            temp[j] += '0';
            
        }
        
        if(carry > 0)
            temp.insert(0, 1, (carry + '0'));
        
        temp.append((n1.length() - i - 1), '0'); // as like mult by 10, 100, 1000, 10000 and so on
        
        result = add(result, temp); // O(n)
    }
    
    while(result[0] == '0' && result.length() != 1) // erase leading zeros
        result.erase(0,1);
    
    return result;
}


bool BigNumber::equals(BigNumber n1, BigNumber n2) {
    return n1.getNumber() == n2.getNumber() && n1.getSign() == n2.getSign();
}

bool BigNumber::less(BigNumber n1, BigNumber n2) {
    bool sign1 = n1.getSign();
    bool sign2 = n2.getSign();
    
    if(sign1 && ! sign2) // if n1 is -ve and n2 is +ve
        return true;
    
    else if(! sign1 && sign2)
        return false;
    
    else if(! sign1) { // both +ve
        if(n1.getNumber().length() < n2.getNumber().length() )
            return true;
        if(n1.getNumber().length() > n2.getNumber().length() )
            return false;
        return n1.getNumber() < n2.getNumber();
    } else { // both -ve
        if(n1.getNumber().length() > n2.getNumber().length())
            return true;
        if(n1.getNumber().length() < n2.getNumber().length())
            return false;
        return n1.getNumber().compare( n2.getNumber() ) > 0; // greater with -ve sign is LESS
    }
}

bool BigNumber::greater(BigNumber n1, BigNumber n2) {
    return ! equals(n1, n2) && ! less(n1, n2);
}


string BigNumber::toString(long long int n)
{
    stringstream ss;
    string temp;
    
    ss << n;
    ss >> temp;
    
    return temp;
}

//-------------------------------------------------------------
// converts string to long long
long long int BigNumber::toInt(string s)
{
    long long int sum = 0;
    
    for(int i=0; i<s.length(); i++)
        sum = (sum*10) + (s[i] - '0');
    
    return sum;
}
