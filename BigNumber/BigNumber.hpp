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
    BigNumber absolute(); // convert to abs
    void operator = (BigNumber);
    bool operator == (BigNumber);
    bool operator != (BigNumber);  // ok
    bool operator > (BigNumber);  // ok
    bool operator < (BigNumber);  // ok
    bool operator >= (BigNumber); // ok
    bool operator <= (BigNumber); // ok
    BigNumber operator + (BigNumber); // ok
    BigNumber operator - (BigNumber);  // ok
    BigNumber operator * (BigNumber);
    BigNumber operator / (BigNumber);
    BigNumber operator % (BigNumber);
    operator string(); // for conversion from BigNumber to string
    
private:
    string number;
    bool sign;
    bool checkString(const string&);
    string add(string, string);
    string sub(string, string);
    string mul(string, string);
    
};


#endif /* BIGNUMBER */
