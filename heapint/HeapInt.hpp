#ifndef HEAPINT_H
#define HEAPINT_H

#include <iostream>

class HeapInt
{
private:
    int *_value;

public:
    HeapInt() : HeapInt(0) {}
    HeapInt(int v);
    HeapInt(const HeapInt &hi);
    ~HeapInt();
    HeapInt &operator=(int v);
    HeapInt &operator=(const HeapInt &hi);
    HeapInt operator+(const HeapInt &hi) const;
    HeapInt operator-(const HeapInt &hi) const;
    bool operator==(const HeapInt &hi) const;
    friend std::istream &operator>>(std::istream &in, const HeapInt &hi)
    {
        in >> *hi._value;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const HeapInt &hi)
    {
        out << *hi._value;
        return out;
    }
};

#endif