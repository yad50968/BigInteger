//
//  BigNumber.hpp
//  BigNumber
//
//  Created by Liu Tzu Yuan on 2017/2/20.
//  Copyright © 2017年 Liu Tzu Yuan. All rights reserved.
//

#ifndef BIGNUMBER
#define BIGNUMBER

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;


class BigNumber {
    
    
public:
    BigNumber(); // empty constructor initializes zero
    BigNumber(string); // "string" constructor
    void setNumber(string);
    const string& getNumber(); // retrieves the number
    void setSign(bool);
    const bool& getSign();
    const string getString();
    BigNumber getAbsolute();
    void absolute(); // convert to abs
    void operator = (BigNumber);
    bool operator == (BigNumber);
    bool operator != (BigNumber);
    bool operator > (BigNumber);
    bool operator < (BigNumber);
    bool operator >= (BigNumber);
    bool operator <= (BigNumber);
    BigNumber operator + (BigNumber);
    BigNumber operator - (BigNumber);
    BigNumber operator * (BigNumber);
    BigNumber operator / (BigNumber);
    BigNumber operator % (BigNumber);
    BigNumber& operator += (BigNumber);
    BigNumber& operator -= (BigNumber);
    BigNumber& operator *= (BigNumber);
    BigNumber& operator /= (BigNumber);
    BigNumber& operator %= (BigNumber);
    operator string(); // for conversion from BigNumber to string
    
private:
    string number;
    bool sign;
    bool checkString(const string&);
    string add(string, string);
    string sub(string, string);
    string mul(string, string);
    pair<string, long long int> div(string, long long int);
    bool equals(BigNumber, BigNumber);
    bool less(BigNumber, BigNumber);
    bool greater(BigNumber, BigNumber);
    long long toInt(string);
    string toString(long long int);
    
};


#endif /* BIGNUMBER */
