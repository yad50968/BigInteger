# BigInteger

### Description
An Implementation of BigNumber library in C++ <br>
Develop with Xcode

### Usage

#### Include
```C++ 
#include "BigNumber.hpp" 
```

#### Init
```C++

    BigNumber a {};
    BigNumber a {"12345"};
    BigNumber a {"-12345"};

```

#### Access
```C++

    BigNumber a {"-12345"};
    bool b = a.getSign(); // true
    string s = a.getNumber(); // "12345"
    string ss = a.getString(); // "-12345"
    string sss = string(a); //  "-12345"

    BigNumber b {};
    b.setSign("false");
    b.setNumber("999");
    string(b); // "999"
```

#### Operators


##### Equal
```C++
    BigNumber a {"11111"};
    BigNumber b = a;
    string(b); // "11111"

```
##### Add
```C++
    BigNumber a {"11111"};
    BigNumber b {"22222"};
    BigNumber c = a + b // "33333"

    BigNumber d = {"-33333"}
    BigNumber e = c + d; // "0"

    BigNumber k += e; 

```
##### Sub
```C++
    BigNumber a {"22222"};
    BigNumber b {"11111"};
    
    BigNumber c = a - b; // "11111"

    a -= b; // "11111"
```

##### Mul
```C++
    BigNumber a {"100"};
    BigNumber b {"100"};

    BigNumber c = a * b; // "10000"
    a *= b; // "10000"
```

##### Div
```C++
    CAN DIV NUMBER LARGE THAN "long long int"
    
    BigNumber a {"1000"};
    BigNumber b {"100"};

    BigNumber c = a / b; // "10"
    a /= b; // "10"

```

##### Mod
```C++

    CAN MOD NUMBER LARGE THAN "long long int"

    BigNumber a {"12"};
    BigNumber b {"5"};

    BigNumber c = a % b; // "2"
    a %= b; // "2"
```


##### Abs
```C++
    BigNumber d = {"-33333"};
    d.absolute();
    string(d); // 33333

    BigNumber e = {"-100"};
    BigNumber k = e.getAbsolute();
    string(k); // "100"
    string(e); // "-100"
```


##### Comparison
```C++
    BigNumber a {"11111"};
    BigNumber b {"22222"};

    if(a == b) // false
    if(a != b) // true
    if(a < b)  // true
    if(a <= b) // true
    if(a > b)  // false
    if(a >= b)  // false
    
```
### Will do

1. More operator
2. Error Handler

### Test
Use Catch <br>
```
http://hiltmon.com/blog/2014/10/26/simple-c-plus-plus-testing-with-catch-in-xcode/
https://github.com/philsquared/Catch
```

### Reference
``` https://github.com/panks/BigInteger ```
