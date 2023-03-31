/// @file pa12.cpp
/// @author Sujin Lee
/// @date 2/20/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Catch unot testing framework for Container classes
/// @note 30hr
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <cassert>
#include <sstream>
#include "Container.h"
#include "Container.h" //include guard
using std::cout;

TEST_CASE("Container::constructor(default)") {
    const Container container1;

    CHECK(container1.empty() == true);
    CHECK(container1.size() == 0);

}

TEST_CASE("Container::constructor(copy)") {
    Container container1;

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
    }

    Container container2(container1);  // declare container2

    CHECK(container1.size() == container2.size());

}

TEST_CASE("Container::Initializer List constructor") {
    // create and initialize a Container
    Container container1 { 8, 7, 3, 1, 0, 9, 4, 6, 5, 2 };

    for ( auto item : container1 ) {
        CHECK(item == *(container1.begin()));
    }
}

TEST_CASE("Container::Destructor") {
    Container container1;

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
    }

    CHECK(container1.size() == 5);

    container1.~Container(); // container1->~Container();?? Same??

    CHECK(container1.size() == 0);
}

TEST_CASE("Container::size") {
    Container container1;

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
    }

    CHECK(container1.size() == 5);
}


TEST_CASE("Container::empty") {
    Container container1;

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
    }

    CHECK(container1.size() == 5);

    container1.empty();

    CHECK(container1.size() == 0);

}

TEST_CASE("Container::begin") {
    Container container1;
    Container::pointer ptr = container1.begin();

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
        CHECK(*ptr == i);
        ptr++;
    }
}

TEST_CASE("Container::end") {
    Container container1;

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
    }
    CHECK(container1.end() == (container1.begin() + 4));
}

TEST_CASE("Container::push_back") {
    Container container1;
    Container::pointer ptr = container1.begin();

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
        CHECK(*ptr == i);
        ptr++;
    }
    CHECK(container1.size() == 5);
}


TEST_CASE("Container::erase") {
    Container container1;
    Container::pointer ptr = container1.begin();
    Container::pointer eptr = container1.end();

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
        CHECK(*ptr == i);
        ptr++;
    }
    CHECK(container1.size() == 5);

    for ( int i = 4; i >= 0; i-- ) {
        container1.erase(eptr);
        eptr--;
    }
    CHECK(container1.size() == 0);
}

TEST_CASE("Container::clear") {
    Container container1;
    Container::pointer ptr = container1.begin();

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
        CHECK(*ptr == i);
        ptr++;
    }

    CHECK(container1.size() == 5);
    container1.clear();
    CHECK(container1.size() == 0);
}

TEST_CASE("Container::swap") {
    Container container1;
    Container container2 { 8, 7, 3, 1, 0, 9, 4, 6, 5, 2 };

    container1.swap(container2);

    CHECK(container1.size() == 10);
    CHECK(container2.size() == 0);
}

TEST_CASE("Container::find") {
    Container container1;
    Container::pointer ptr = nullptr;

    for ( int i = 0; i < 5; i++ ) {
        container1.push_back(i);  // assign 0 to 4 to container1
    }

    CHECK(container1.find(5, ptr) == container1.end());
    CHECK(container1.find(0, ptr) == container1.begin());

}
