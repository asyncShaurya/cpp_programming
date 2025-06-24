#include <iostream>
#include <cstring>
#include "Mystring.h"

//overloaded insertion operator
std::ostream &operator << (std::ostream &os, const Mystring &rhs){
    os<< rhs.str;
    return os;
}

//overloaded extraction operator
std::istream &operator >> (std::istream &in, Mystring &rhs){
    char *buff = new buff[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}