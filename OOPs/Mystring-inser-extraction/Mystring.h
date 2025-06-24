#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring{
    friend std::ostream &operator << (std::ostream &os, const Mystring &rhs);
    friend std::istream &operator >> (std::istream &in,Mystring &rhs);
};

#endif //_MYSTRING_H_