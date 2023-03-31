/// @file Container.h
/// @author Sujin Lee
/// @date 2/16/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Header file for Container.cpp
/// @note 15hr
#ifndef CONTAINER_H
#define CONTAINER_H
#include <cassert>
#include <iostream>
/// A Bag is a general-purpose container that stores a set of possibly
/// non-unique values of type int. Internally, the items are not maintained
/// in any particular order.
/// A Container stores a set of values The storage of the Container
/// is handled automatically, being expanded as needed.

class Container {
public:
    /// Member types.
    using value_type    = int;
    using size_type     = std::size_t;
    using pointer       = value_type*;
    using const_pointer = const value_type*;

    /// Default ctor.
    Container(size_type count = 0) {
        data = new int[count];
        used = 0;
        capacity = count;
    }

    /// Copy ctor.
    Container(const Container& other);

    /// Initializer List ctor
    Container(const std::initializer_list<value_type>& init);

    /// Destructor.
    ~Container();

    /// Returns the number of elements in the container.
    size_type size() const { return used; }

    /// Checks if the container has no elements, e.g begin() == end()
    /// @returns true if the container is empty, false otherwise.
    bool empty() const { return size() == 0; }

    /// Returns a pointer to the first element.
    pointer begin() { return data; }
    const_pointer begin() const { return data; }

    /// Returns a pointer to the end (the element following the last element).
    pointer end() { return begin() + size(); }
    const_pointer end() const;

    /// Adds an element to the end.
    void push_back(const value_type& value);

    /// Removes a single item from the container.
    void erase(pointer pos);

    /// After this call, size() returns zero. The capacity remains unchanged.
    void clear();

    /// Exchanges the contents of the container with those of other.
    void swap(Container& other);

    /// Finds the first element equal to the given target. Search begins at pos.
    /// @returns pointer to the element if found, or end() if not found.
    pointer find(const value_type& target, pointer pos = nullptr) {
        assert (begin() <= pos && pos < end());
        bool flag = false;
        for (pointer iter = begin(); iter != end() && !flag; ++iter) {
            if (*iter == target) {
                flag = true;
                pos = iter;
            }
        }  // end for
        if (flag) {
            return pos;
        }
        else {
            return end();
        }
    }

private:
    size_type capacity;  ///< Physical capacity of container.
    size_type used;      ///< Number of items in container.
    pointer   data;      ///< Array of items.
};

// related non-member functions

/// Checks the contents of lhs and rhs are equal, that is, they have the same
/// number of elements and each element in lhs compares equal with the element
/// in rhs at the same position.
bool equal(const Container& lhs, const Container& rhs);

/// Performs stream output on Containers, using "{1,2,3}" format.
void write(std::ostream& output, const Container& container);

#endif /* CONTAINER_H */
