#pragma once
#include<cstddef>

using iterator = int*;

class minivector
{
  private:
    int *data;
    size_t size;
    size_t capacity;
  
  public:
    minivector(); // default constructor

    ~minivector(); // Rule 1 of (3/5): destructor

    minivector(const minivector &other); // Rule 2 of (3/5) : copy constructor implementation

    minivector& operator=(const minivector &other); // Rule 3 of (3/5) : copy assignment operator implementation

    minivector(minivector&& other) noexcept; // Rule 4 of (5): move constructor

    minivector& operator=(minivector &&other) noexcept; // Rule 5 of 5: move assignement operator implementation

    void push_back(int value);

    int& operator[](size_t index);

    const int& operator[](size_t index) const;

    size_t getSize() const;

    size_t getCapacity() const;

    void print() const;

    int& at(size_t index);

    const int& at(size_t index) const;

    void clear();

    void reserve(size_t newcap);
    
    void shrink_to_fit();

    iterator begin();
    iterator end();
    

  private:
    void resize(size_t capacity);
};