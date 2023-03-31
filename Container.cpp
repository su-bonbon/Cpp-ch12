/// @file Container.cpp
/// @author Sujin Lee
/// @date 2/16/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Source file for Container.cpp
/// @note 15hr
#include <iostream>
#include "Container.h"
#include "Container.h"  // header file guard
#include <initializer_list>
using namespace std;

/// Copy constructor copy all the elements from other.data to data
/// assigns private variables from other Container to current Container
/// @param Container
Container::Container(const Container& other) {
    data = new int[other.size()];
    capacity = other.size();
    used = other.size();

    data = other.data;


}

/// Initializer List ctor
/// copy all the elements from init.begin() to init.end() to data
/// @param const std::initializer_list<value_type>&
Container::Container(const std::initializer_list<value_type>& init) {
    data = new int[init.size()];
    capacity = init.size();
    used = init.size();
    Container container_fake(init);

    for (Container::pointer iter = container_fake.begin();
         iter != container_fake.end(); ++iter) {
        data = container_fake.begin();  // deep copy
        data++;
    }
}

/// Deconstructor
/// @param None
Container::~Container() {
    delete [] data;
    // ~ data = nullptr;
    // ~ used = 0;
    // ~ capacity = 0;
}

/// Returns a pointer to the end (the element following the last element).
/// @param None
/// @returns pointer (end address)
Container::const_pointer Container::end() const {
    return begin() + size();
}

/// Adds an element to the end.
/// @param const value_type& value
/// @returns None
void Container::push_back(const value_type& value) {
    Container::value_type num = value;
    if (used == capacity) {
        Container::pointer data_New = new int[size() + 8];

        for (Container::pointer iter = begin(); iter <= end(); ++iter) {
            data_New = begin();  // deep copy
            data_New++;

            if ( iter == end() ){
                *data_New = num;
            }
        delete [] data;
        data = data_New;
        }  // end for loop
    }  // end if
    *(data + used) = num;
}

/// Removes a single item from the container.
/// @param ponter pos
/// @returns None
void Container::erase(pointer pos) {
    for (Container::pointer iter = begin(); iter != end(); ++iter) {
        if (iter == pos){
            for (Container::pointer iter2 = iter; iter2 != end(); ++iter2) {
                iter2 = iter2+1;
            }
            used -= 1;
        }
    }
}

/// After this call, size() returns zero. The capacity remains unchanged.
/// @param None
/// @returns None
void Container::clear() {
    used = 0;
}

/// Exchanges the contents of the container with those of other.
/// @param object Container
/// @returns None
void Container::swap(Container& other){
    Container temp(other);

    other.used = used;
    other.data = data;
    other.capacity = capacity;

    used = temp.used;
    data = temp.data;
    capacity = temp.capacity;
}

