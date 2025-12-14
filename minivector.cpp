#include<iostream>
#include<algorithm>
#include "minivector.hpp"
#include<stdexcept>

//1. default constructor implementation
minivector::minivector():data(nullptr), size(0), capacity(0) //initializer list
{
  
}

//2. destructor: releasing resource when is object destroyed
minivector::~minivector()
{
    delete []data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

//3. copy constructor implementation
minivector::minivector(const minivector&other): size(other.size), capacity(other.capacity) // taking: Lvalue reference
{
    if(capacity == 0)
    {
        data = nullptr;
        return;
    }

    //deep copy
    data = new int[capacity];
    std::copy(other.data, other.data+size, data); 
}

//4. copy assignment operator implementation
minivector& minivector::operator=(const minivector &other) 
{
    if(this == &other) // both are same object i.e a = a [ someone try this]
    {
        return *this;
    }

    //relasing existing memory resource
    delete []this->data;
    this->data = nullptr;

    //copy from other
    this->size = other.size;
    this->capacity = other.capacity;

    if(capacity == 0)
    {
        data = nullptr;
        return *this;
    }

    // allocating new memory : deep copy
    data = new int[capacity];
    std::copy(other.data, other.data+size, this->data);

    return *this;
}
//5. move constructor implementation
minivector::minivector(minivector &&other) noexcept:data(other.data), size(other.size), capacity(other.capacity)
{
    //taking resource, as these already assigned to "this"
    other.data = nullptr;
    other.size = 0;
    other.capacity =0;
}


// 6. move assignement operator implementation
minivector& minivector::operator=(minivector &&other) noexcept
{
    if(this == &other)
    {
        return *this;
    }

    delete []this->data;


    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}


//7. resize - utility function
void minivector::resize(size_t new_cap)
{
    //allocating new memory
    
     int *temp = new int[new_cap];

     //copy data to newly allocate memory
     if(data != nullptr)
        std::copy(data, data+size, temp);

    //deleting old data
     delete []data;

     //updating data with new memory
     data = temp;
     capacity = new_cap;

}

//8: push_back() feature : add new element
void minivector::push_back(int val)
{
    if(capacity == 0) this->resize(1);
    else if(size == capacity) this->resize(2*capacity);
    
    data[size]=val;
    size+=1;
}

//9. know size() feature
size_t minivector::getSize() const
{
    return this->size;
}

//10. know capacity() feature
size_t minivector::getCapacity() const
{
    return this->capacity;
}

//11. [] -> implemenation [ mutable]
int& minivector::operator[](size_t index)
{
    return data[index];
}

//12. [] -> implemenation [ immutable]
const int& minivector::operator[](size_t index) const{
    return data[index];
}


//12. print() : show me vector
void minivector::print() const
{
    for(int i=0;i<size;i++)
    {
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

//13. at() - non const
int& minivector::at(size_t index)
{
    if(index >= size)
    {
        throw std::out_of_range("minivector::at - index out of range");
    }
    return this->data[index];
}

//14: at() - const 
const int& minivector::at(size_t index) const{
    if(index >=size)
    {
        throw std::out_of_range("minivector::at - index out of range");
    }
    return this->data[index];
}

//15 clear() - clear the content, capacity not changed, 
// size changed to 0, so that no need to reallocate new memoory and we can re-use the current allocate memeory

void minivector::clear()
{
    size = 0;
}


//16. to reserve memory : to avoid reallocations
void minivector::reserve(size_t newcap)
{
    if(newcap > this->capacity)
    {
        resize(newcap);
    }
    return;
}

//17 shrink_to_fit

void minivector::shrink_to_fit()
{
    if(this->size == this->capacity) {
        return;
    }

    if(this->size == 0)
    {
        delete []this->data;
        this->data = nullptr;
        size = 0;
        capacity = 0;
        return;
    }

    int *temp = new int[size];
    std::copy(data, data+size, temp);
    delete []data;
    capacity = size;
    data = temp;
    
}

iterator minivector::begin()
{
    return (iterator)data;
}

iterator minivector::end()
{
    return (iterator)(data+size);
}