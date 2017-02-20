//
//  main.cpp
//  Test
//
//  Created by Liu Tzu Yuan on 2017/2/20.
//  Copyright © 2017年 Liu Tzu Yuan. All rights reserved.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "BigNumber.hpp"

TEST_CASE("Testing Init") {
    
    
    
    SECTION("Test 1") {
        BigNumber i;
        REQUIRE(i.getSign() == false);
        REQUIRE(i.getNumber() == "0");
        REQUIRE(i.getString() == "0");
    }
    
    SECTION("Test 2") {
        BigNumber i {"10000"};
        REQUIRE(i.getSign() == false);
        REQUIRE(i.getNumber() == "10000");
        REQUIRE(i.getString() == "10000");
    }
    
    
    SECTION("Test 3") {
        BigNumber i {"-10000"};
        REQUIRE(i.getSign() == true);
        REQUIRE(i.getNumber() == "10000");
        REQUIRE(i.getString() == "-10000");
    }

}

TEST_CASE("Testing ACCESS") {
    
    SECTION("Test 1") {
        BigNumber i;
        REQUIRE(i.getSign() == false);
        REQUIRE(i.getNumber() == "0");
        REQUIRE(i.getString() == "0");
        
        i.setSign("true");
        i.setNumber("12345");
        REQUIRE(i.getString() == "-12345");
    }
    
    SECTION("Test 2") {
        BigNumber j {"-999"};
        REQUIRE(string(j) == "-999");
        
    }
}

TEST_CASE("Testing Equal") {
    
    SECTION("Test 1") {
        BigNumber a {"-1000"};
        BigNumber b = a;
        
        REQUIRE(string(b) == "-1000");
    }
}
TEST_CASE("Testing ADD") {
    
    SECTION("Test 1") {
        BigNumber a {"99999"};
        BigNumber b {"1"};
        BigNumber c = a + b;
        
        REQUIRE(string(c) == "100000");
    }
    
    SECTION("Test 2") {
        BigNumber a {"99999"};
        BigNumber b {"-100000"};
        BigNumber c = a + b;
        
        REQUIRE(string(c) == "-1");
    }
    
    SECTION("Test 3") {
        BigNumber a {"91"};
        BigNumber b {"-99991"};
        BigNumber c = a + b;
        
        REQUIRE(string(c) == "-99900");
    }
    
    SECTION("Test 4") {
        BigNumber a {"-9"};
        BigNumber b {"-99991"};
        BigNumber c = a + b;
        
        REQUIRE(string(c) == "-100000");
    }
    
    SECTION("Test 5") {
        BigNumber a {"99999"};
        BigNumber b {"-99999"};
        BigNumber c = a + b;
        
        REQUIRE(string(c) == "0");
    }
    
    SECTION("Test 6") {
        BigNumber a {"99999"};
        BigNumber b {"-99999"};
        a += b;
        
        REQUIRE(string(a) == "0");
    }
}

TEST_CASE("Testing SUB") {
    
    SECTION("Test 1") {
        BigNumber a {"99999"};
        BigNumber b {"100000"};
        BigNumber c = a - b;
        
        REQUIRE(string(c) == "-1");
    }
    
    SECTION("Test 2") {
        BigNumber a {"1"};
        BigNumber b {"-99999"};
        BigNumber c = a - b;
        
        REQUIRE(string(c) == "100000");
    }
    
    SECTION("Test 3") {
        BigNumber a {"-99999"};
        BigNumber b {"100000"};
        BigNumber c = a - b;
        
        REQUIRE(string(c) == "-199999");
    }
    
    SECTION("Test 4") {
        BigNumber a {"-99999"};
        BigNumber b {"-100000"};
        BigNumber c = a - b;
        
        REQUIRE(string(c) == "1");
    }
    
    SECTION("Test 5") {
        BigNumber a {"99999"};
        BigNumber b {"99999"};
        BigNumber c = a - b;
        
        REQUIRE(string(c) == "0");
    }
    
    SECTION("Test 6") {
        BigNumber a {"99999"};
        BigNumber b {"100000"};
        a -= b;
        
        REQUIRE(string(a) == "-1");
    }
}

TEST_CASE("Testing Abs") {
    
    SECTION("Test 1") {
        BigNumber d = {"-33333"};
        d.absolute();
        
        REQUIRE(string(d) == "33333");
    }
    
    SECTION("Test 2") {
        
        BigNumber e = {"-100"};
        BigNumber k = e.getAbsolute();
        REQUIRE(string(e) == "-100");
        REQUIRE(string(k) == "100");
    }
}

TEST_CASE("Test Comparison") {
    
    BigNumber a {"100"};
    BigNumber b {"-100"};
    
    SECTION("Test 1") {
        
        REQUIRE( (a == b) == false);
    }
    
    SECTION("Test 2") {
        
        REQUIRE( (a != b) == true);
    }
    
    SECTION("Test 3") {
        
        REQUIRE( (a < b) == false);
    }
    
    SECTION("Test 4") {
        
        REQUIRE( (a <= b) == false);
    }
    
    SECTION("Test 5") {
        
        REQUIRE( (a > b) == true);
    }
    
    SECTION("Test 6") {
        
        REQUIRE( (a >= b) == true);
        
    }
    
    
    
}
