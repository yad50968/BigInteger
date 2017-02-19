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
    
    
    BigNumber no {"---"};
    cout << no.getSign() << endl;
    cout << no.getNumber() << endl;
    
    cout << endl;
    
    /*---------------------------------------*/
    
    
    BigNumber zero {"0"};
    zero.setSign("true");
    zero.setNumber("10000");
    cout << zero.getSign() << endl;
    cout << zero.getNumber() << endl;
    
    cout << endl;
    
    /*---------------------------------------*/
    
    
    zero.absolute();
    cout << zero.getSign() << endl;
    cout << zero.getNumber() << endl;
    
    cout << endl;
    
    
    /*---------------------------------------*/
    
    
    BigNumber equalval {};
    
    equalval = BigNumber {"99999"};
    
    cout << equalval.getSign() << endl;
    cout << equalval.getNumber() << endl;
    
    cout << endl;
    
    /*---------------------------------------*/
    
    
    BigNumber equalvaltwo {};
    equalvaltwo = BigNumber {"99999"};
    
    cout << (equalval == equalvaltwo) << endl;
    cout << (equalval != equalvaltwo) << endl;

    equalvaltwo.setSign("true");
    cout << (equalval == equalvaltwo) << endl;
    cout << (equalval != equalvaltwo) << endl;
    cout << endl;
    
    /*---------------------------------------*/
    
    
    BigNumber a {"111112222233333444445555566666777778888899999"};
    cout << a.getSign() << endl;
    cout << a.getNumber() << endl;
    
    cout << endl;
    
    /*---------------------------------------*/
    
    BigNumber b {"-111112222233333444445555566666777778888899999"};
    cout << b.getSign() << endl;
    cout << b.getNumber() << endl;

    cout << endl;
    
    /*---------------------------------------*/
    
    BigNumber c = a + b;
    
    cout << c.getSign() << endl;
    cout << c.getNumber() << endl;
    
    cout << endl;
    
    /*---------------------------------------*/
    cout << string(c);
    
    cout << endl;
    
}
