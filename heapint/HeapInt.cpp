#include "HeapInt.hpp"

HeapInt::HeapInt(int v) { _value = new int(v); };

HeapInt::HeapInt(const HeapInt &hi) { _value = new int(*hi._value); }

HeapInt::~HeapInt() { delete _value; }

HeapInt &HeapInt::operator=(int v)
{
    *_value = v;
    return *this;
}

HeapInt &HeapInt::operator=(const HeapInt &hi)
{
    *_value = *hi._value;
    return *this;
}

HeapInt HeapInt::operator+(const HeapInt &hi) const { return HeapInt(*_value + *hi._value); }

HeapInt HeapInt::operator-(const HeapInt &hi) const { return HeapInt(*_value - *hi._value); }

bool HeapInt::operator==(const HeapInt &hi) const { return *_value == *hi._value; }
