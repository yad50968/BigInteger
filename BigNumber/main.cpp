//
//  BigInterger.cpp
//  Test
//
//  Created by Liu Tzu Yuan on 2017/2/19.
//  Copyright © 2017年 Liu Tzu Yuan. All rights reserved.
//

#include <iostream>
#include <string>
#include "BigNumber.hpp"
using namespace std;






int main() {
    
    BigNumber a {"-1111999"};
    BigNumber b {"1999"};
    BigNumber c = a + b;
    BigNumber d = a - b;
    cout << string(c) << " " << string(d) << endl;
    
    BigNumber a1 {"-1111"};
    BigNumber b1 {"2222"};
    BigNumber c1 = a1 + b1;
    
    BigNumber d1 = a1 - b1;
    cout << string(c1) << " " << string(d1) << endl;
    
    
    BigNumber a2 {"1111"};
    BigNumber b2 {"-2222"};
    BigNumber c2 = a2 + b2;
    
    BigNumber d2 = a2 - b2;
    cout << string(c2) << " " << string(d2) << endl;
    
    
    BigNumber a3 {"-1111"};
    BigNumber b3 {"-2222"};
    BigNumber c3 = a3 + b3;
    
    BigNumber d3 = a3 - b3;
    cout << string(c3) << " " << string(d3) << endl;
    
}
