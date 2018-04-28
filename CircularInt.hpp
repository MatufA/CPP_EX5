//
// Created by ehud on 15/04/18.
//
#include <iostream>
using namespace std;
#ifndef CPP_4_CIRCULATINT_H
#define CPP_4_CIRCULATINT_H

#endif //CPP_4_CIRCULATINT_H
/*
 * was inspired regarding operators i had missing from @Orel Shalom and @Samuel Bismuth
 */

class CircularInt{
private:
     int start;
     int end;
     int modulo;
public:

    //getters and setters
    int get_start()const;
    int get_end()const;
    int get_cur()const;
    void set_cur(int a);

    //helper functions
    friend int  gRange(int start,int end,int cur);
    int inRange(int result);

    //builder, int cur
    CircularInt(int st,int en);
    int cur;



    void operator= (CircularInt circularInt);
    void operator= (int number);
    CircularInt operator+ (const CircularInt circularInt);
    CircularInt operator+ (const int increment);
    CircularInt operator- (const CircularInt circularInt);
    CircularInt operator- (const int decrement);
    CircularInt operator+ ();
    CircularInt operator- ();
    CircularInt operator* (const CircularInt circularInt);
    CircularInt operator* (const int multiplier);
    CircularInt operator/ (const CircularInt circularInt);
    CircularInt operator/ (const int divisor);
    CircularInt operator% (const CircularInt circularInt);
    CircularInt operator% (const int modulo);
    CircularInt& operator++ ();
    CircularInt operator++ (int increment);
    CircularInt& operator-- ();
    CircularInt operator-- (const int decrement);

    // Comparison operators/relational operators.

    bool operator== (const CircularInt& circularInt);
    bool operator== (const int& number);
    bool operator!= (const CircularInt& circularInt);
    bool operator!= (const int& number);
    bool operator> (const CircularInt& circularInt) const;
    bool operator> (const int& number) const;
    bool operator< (const CircularInt& circularInt) const;
    bool operator< (const int& number) const;
    bool operator>= (const CircularInt& circularInt) const;
    bool operator>= (const int& number) const;
    bool operator<= (const CircularInt& circularInt) const;
    bool operator<= (const int& number) const;


    bool operator! () const;
    bool operator&& (const CircularInt circularInt);
    bool operator&& (const int number);
    bool operator|| (const CircularInt circularInt);
    bool operator|| (const int number);


    CircularInt operator~ ();
    CircularInt operator& (const CircularInt circularInt);
    CircularInt operator& (const int number);
    CircularInt operator| (const CircularInt circularInt);
    CircularInt operator| (const int number);
    CircularInt operator^ (const CircularInt circularInt);
    CircularInt operator^ (const int number);
    CircularInt operator<< (const CircularInt circularInt);
    CircularInt operator<< (const int number);
    CircularInt operator>> (const CircularInt circularInt);
    CircularInt operator>> (const int number);


    CircularInt& operator+= (const CircularInt circularInt);
    CircularInt& operator+= (const int increment);
    CircularInt& operator-= (const CircularInt circularInt);
    CircularInt& operator-= (const int decrement);
    CircularInt& operator*= (const CircularInt circularInt);
    CircularInt& operator*= (const int multiplier);
    CircularInt& operator/= (const CircularInt circularInt);
    CircularInt& operator/= (const int divisor);
    CircularInt& operator%= (const CircularInt circularInt);
    CircularInt& operator%= (const int divisor);
    CircularInt& operator&= (const CircularInt circularInt);
    CircularInt& operator&= (const int number);
    CircularInt& operator|= (const CircularInt circularInt);
    CircularInt& operator|= (const int number);
    CircularInt& operator^= (const CircularInt circularInt);
    CircularInt& operator^= (const int number);
    CircularInt& operator<<= (const CircularInt circularInt);
    CircularInt& operator<<= (const int number);
    CircularInt& operator>>= (const CircularInt circularInt);
    CircularInt& operator>>= (const int number);



    friend CircularInt operator+ (const int increment, const CircularInt& circularInt);
    friend CircularInt operator- (const int decrement, const CircularInt& circularInt);
    friend CircularInt operator/ (const int divisor, const CircularInt& circularInt);
    friend bool operator== (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
    friend bool operator!= (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
    friend bool operator> (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
    friend bool operator< (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
    friend bool operator>= (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
    friend bool operator<= (const int& number, const CircularInt& circularInt); //Only worried about currentNumber.
    friend ostream& operator<< (ostream& os, const CircularInt& circularInt);
    friend istream& operator>> (istream& is, CircularInt& circularInt);
};
