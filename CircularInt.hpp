//
// Created by ehud on 15/04/18.
//
#include <iostream>
using namespace std;
#ifndef CPP_4_CIRCULATINT_H
#define CPP_4_CIRCULATINT_H

#endif //CPP_4_CIRCULATINT_H
class CircularInt{
private:
     int start;
     int end;
     int modulo;
public:
    int get_start()const;
    int get_end()const;
    int get_cur()const;
    void set_cur(int a);
    friend int  gRange(int start,int end,int cur);
     int inRange(int result);
    CircularInt(int st,int en);
    CircularInt& operator*=(int a);
    int cur;
    int  operator-();
    int operator++(int);
    int operator--(int);
    CircularInt&operator+=(int a);
    CircularInt& operator-=(int a);
    int operator+();
    bool operator!()const;
    bool operator&&(const CircularInt& c);
    bool operator||(const CircularInt& c);
    friend int operator-(int a,CircularInt& c);
//    friend int operator-(CircularInt& c,int a);
    CircularInt& operator=(int a);
    friend int operator+(CircularInt& a,CircularInt& b);
    friend int operator/(CircularInt& c,int a);
    friend ostream& operator<<(ostream& output,const CircularInt& x);
    int operator+(int a);
    int operator-(int a);
    int operator*(int a);
    CircularInt&operator--();
    CircularInt&operator++();
    CircularInt& operator%= (const int divisor);
    void operator=(CircularInt const& circularInt);
    bool operator ==(CircularInt const& circularInt);
    bool operator !=(CircularInt const& circularInt);
    bool operator> (CircularInt const& circularInt) const;
    bool operator< (CircularInt const& circularInt) const;
    bool operator<= (CircularInt const& circularInt) const;
    bool operator>= (CircularInt const& circularInt) const;
    int operator~();
    int operator&(int a);
    int operator|(int a);
    int operator^(int a);
    int operator<<(int a);
    int operator>>(int a);

};
