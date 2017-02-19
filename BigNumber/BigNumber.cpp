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

// convert to abs
BigNumber BigNumber::absolute() {
    
    setSign( !getSign() );
    return *this;
}

void BigNumber::operator = (BigNumber input) {
    setNumber(input.getNumber());
    setSign(input.getSign());
}

bool BigNumber::operator == (BigNumber input) {
    return getNumber() == input.getNumber() && getSign() == input.getSign();
}

bool BigNumber::operator != (BigNumber input) {
    return (getNumber() != input.getNumber()) || (getSign() != input.getSign());
}
bool BigNumber::operator > (BigNumber input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(sign1 && !sign2) return true;
    else if(!sign1 && sign2) return false;
    else if(sign1 && sign2) return getNumber() > input.getNumber();
    else return getNumber() < input.getNumber();
}


bool BigNumber::operator < (BigNumber input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(!sign1 && sign2) return true;
    else if(sign1 && !sign2) return false;
    else if(sign1 && sign2) return getNumber() < input.getNumber();
    else return getNumber() > input.getNumber();
    
}
bool BigNumber::operator >= (BigNumber input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(sign1 && !sign2) return true;
    else if(!sign1 && sign2) return false;
    else if(sign1 && sign2) return getNumber() >= input.getNumber();
    else return getNumber() <= input.getNumber();
}

bool BigNumber::operator <= (BigNumber input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(!sign1 && sign2) return true;
    else if(sign1 && !sign2) return false;
    else if(sign1 && sign2) return getNumber() <= input.getNumber();
    else return getNumber() >= input.getNumber();
}

BigNumber BigNumber::operator+(BigNumber input) {
    
    BigNumber result;
    
    if(getSign() && input.getSign()) {
        
        result.setSign(false);
        result.setNumber(add(getNumber(), input.getNumber()));
        
    } else if(getSign() && !input.getSign()) {
        
        if(getNumber() > input.getNumber()) {
            result.setSign(false);
            result.setNumber(sub(getNumber(), input.getNumber()));
        } else if (getNumber() < input.getNumber()) {
            result.setSign(true);
            result.setNumber(sub(input.getNumber(), getNumber()));
        } else {
            result.setSign(false);
            result.setNumber("0");
        }
        
        
    } else if(!getSign() && input.getSign()) {
        
        if(getNumber() > input.getNumber()) {
            result.setSign(true);
            result.setNumber(sub(getNumber(), input.getNumber()));
        } else if(getNumber() < input.getNumber()) {
            result.setSign(false);
            result.setNumber(sub(input.getNumber(), getNumber()));
        } else {
            result.setSign(false);
            result.setNumber("0");
        }
        
    } else {
        
        result.setSign(true);
        result.setNumber(add(getNumber(), input.getNumber()));
        
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
    char carry = '0';
    int differenceInLength = abs( (int) (n1.size() - n2.size()) );
    
    if(n1.size() > n2.size())
        n2.insert(0, differenceInLength, '0'); // put zeros from left
    
    else if(n1.size() < n2.size())
        n1.insert(0, differenceInLength, '0');
    
    for(long i = n1.size() - 1; i >= 0; --i) {
        result[i] = ( (carry - '0') + (n1[i] - '0') + (n2[i] - '0') ) + '0';
        
        if(i != 0) {
            if(result[i] > '9') {
                result[i] -= 10;
                carry = '1';
            } else
                carry = '0';
        }
    }
    if(result[0] > '9') {
        result[0]-= 10;
        result.insert(0,1,'1');
    }
    return result;
}


string BigNumber::sub(string n1, string n2) {
    
    // always n1.size >= n2.size
    
    string result = n1;
    int differenceInLength = abs( (int)(n1.size() - n2.size()) );
    
    n2.insert(0, differenceInLength, '0');
    
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
