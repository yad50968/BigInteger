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

BigNumber BigNumber::getAbsolute(BigNumber input) {
    BigNumber result;
    result.setSign(false);
    result.setNumber(input.getNumber());
    
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

BigNumber BigNumber::operator+(BigNumber input) {
    
    BigNumber result;
    
    if(getSign() == input.getSign()) {
        
        result.setSign(getSign());
        result.setNumber(add(getNumber(), input.getNumber()));
        
    } else {
        if( getAbsolute(*this) > getAbsolute(input) ) {
            result.setNumber( sub(getNumber(), input.getNumber() ) );
            result.setSign( getSign() );
        } else if( getAbsolute(*this) < getAbsolute(input) ){
            result.setNumber( sub(input.getNumber(), getNumber() ) );
            result.setSign( input.getSign() );
        } else {
            result.setNumber("0");
            result.setSign(false);

        }
    }
    
    return result;
}

BigNumber BigNumber::operator-(BigNumber input) {
    
    // x - y = x + (-y)
    BigNumber tmp = input;
    tmp.setSign(!tmp.getSign());
    
    return (*this) + tmp;
    
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
