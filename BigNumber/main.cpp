//
//  BigInterger.cpp
//  Test
//
//  Created by Liu Tzu Yuan on 2017/2/19.
//  Copyright © 2017年 Liu Tzu Yuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <regex>

using namespace std;


class BigInteger {
    
    
public:
    BigInteger(); // empty constructor initializes zero               ok
    BigInteger(string); // "string" constructor                     ok
    void setNumber(string);                                    //   ok
    const string& getNumber(); // retrieves the number                ok
    void setSign(bool);                                        //   ok
    const bool& getSign();                                       //   ok
    BigInteger absolute(BigInteger&); // returns the absolute value ok
    void operator = (BigInteger);                               //    ok
    bool operator == (BigInteger);                              // ok
    bool operator != (BigInteger);  // ok
    bool operator > (BigInteger);  // ok
    bool operator < (BigInteger);  // ok
    bool operator >= (BigInteger); // ok
    bool operator <= (BigInteger); // ok
    BigInteger operator + (BigInteger);
    BigInteger operator - (BigInteger);
    BigInteger operator * (BigInteger);
    BigInteger operator / (BigInteger);
    BigInteger operator % (BigInteger);
    operator string(); // for conversion from BigInteger to string   ok
    
private:
    string number;
    bool sign;
    bool checkString(const string&);
    string add(string, string);
    string sub(string, string);
    string mul(string, string);
    
};

BigInteger::BigInteger ()
{
    number = "0";
    sign = false;
}

BigInteger::BigInteger(string s) {
    
    if(checkString(s)) {
        if(s[0] == '-') {
            setSign(true);
            setNumber(s.substr(1));
        } else {
            setSign(false);
            setNumber(s);
        }
    }
}

void BigInteger::setNumber(string s) {
    number = s;
}

const string& BigInteger::getNumber() {
    return number;
}

void BigInteger::setSign(bool s) {
    sign = s;
}

const bool& BigInteger::getSign() {
    return sign;
}



BigInteger BigInteger::absolute(BigInteger& input) {
    if(input.getSign() == true) {
        input.setSign(false);
    } else {
        input.setSign(false);
    }
    
    return input;
}

void BigInteger::operator = (BigInteger input) {
    setNumber(input.getNumber());
    setSign(input.getSign());
}

bool BigInteger::operator == (BigInteger input) {
    return getNumber() == input.getNumber() && getSign() == input.getSign();
}

bool BigInteger::operator != (BigInteger input) {
    return (getNumber() != input.getNumber()) || (getSign() != input.getSign());
}
bool BigInteger::operator > (BigInteger input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(sign1 && !sign2) return true;
    else if(!sign1 && sign2) return false;
    else if(sign1 && sign2) return getNumber() > input.getNumber();
    else return getNumber() < input.getNumber();
}


bool BigInteger::operator < (BigInteger input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(!sign1 && sign2) return true;
    else if(sign1 && !sign2) return false;
    else if(sign1 && sign2) return getNumber() < input.getNumber();
    else return getNumber() > input.getNumber();
    
}
bool BigInteger::operator >= (BigInteger input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(sign1 && !sign2) return true;
    else if(!sign1 && sign2) return false;
    else if(sign1 && sign2) return getNumber() >= input.getNumber();
    else return getNumber() <= input.getNumber();
}

bool BigInteger::operator <= (BigInteger input) {
    
    bool sign1 {getSign()},
    sign2 {input.getSign()};
    
    if(!sign1 && sign2) return true;
    else if(sign1 && !sign2) return false;
    else if(sign1 && sign2) return getNumber() <= input.getNumber();
    else return getNumber() >= input.getNumber();
}

BigInteger BigInteger::operator+(BigInteger input) {
    
    BigInteger result;
    
    if(getSign() && input.getSign()) {
        
        result.setSign(false);
        result.setNumber(add(getNumber(), input.getNumber()));
        
    } else if(getSign() && !input.getSign()) {
        
        if(getNumber() > input.getNumber()) {
            result.setSign(false);
            result.setNumber(sub(getNumber(), input.getNumber()));
        } else {
            result.setSign(true);
            result.setNumber(sub(input.getNumber(), getNumber()));
        }
        
        
    } else if(!getSign() && input.getSign()) {
        
        if(getNumber() > input.getNumber()) {
            result.setSign(true);
            result.setNumber(sub(getNumber(), input.getNumber()));
        } else {
            result.setSign(false);
            result.setNumber(sub(input.getNumber(), getNumber()));
        }
        
    } else {
        
        result.setSign(true);
        result.setNumber(add(getNumber(), input.getNumber()));
        
    }
    
    return result;
}

BigInteger::operator string() {
    string signedString = getSign() ? "-" : "";
    signedString += getNumber();
    return signedString;
}

bool BigInteger::checkString(const string& str) {
    
    regex input_regex("-?[0-9]*");
    if(regex_match(str, input_regex))
        return true;
    else
        return false;
}

string BigInteger::add(string n1, string n2) {
    string result = "";
    
    return result;
}


string BigInteger::sub(string n1, string n2) {
    string result = "";
    
    return result;
}

string BigInteger::mul(string n1, string n2) {
    string result = "";
    
    return result;
}


int main() {
    BigInteger a {"-21345"};
    cout << a.getNumber();
    
}
