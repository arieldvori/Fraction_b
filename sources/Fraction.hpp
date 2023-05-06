#pragma once
#include <iostream>
#include <stdio.h>

namespace ariel{
    class Fraction
    {
    private:
        int _t; // top
        int _b; // bottom

    public:

        Fraction(int t, int b);
        Fraction(float num);
        Fraction(double num);
        Fraction()
        {
            _t = 1;
            _b = 1;
        }

        void reduse();//redused form
        int gcd(int top, int bottom);//returns the greatest common divisor

        int getNumerator() const{
            return this->_t;
        }
        int getDenominator() const{
            return this->_b;
        }
        void setNumerator(int num)
        {
            this->_t = num;
        }
        void setDenominator(int num) 
        {
            this->_b = num;
        }

        //overload the operator + for 2 fractions. 
        Fraction operator+(const Fraction &frac2) const;
        //overload the operator - for 2 fractions. 
        Fraction operator-(const Fraction &frac2) const;
        //overload the operator * for 2 fractions. 
        Fraction operator*(const Fraction &frac2) const;
        //overload the operator / for 2 fractions. 
        Fraction operator/(const Fraction &frac2) const;
        //overload the operator == for 2 fractions. 
        bool operator==(const Fraction &frac2) const;
        //overload the operator != for 2 fractions. 
        bool operator!=(const Fraction &frac2) const;
        //overload the operator > for 2 fractions. 
        bool operator>(const Fraction &frac2) const;
        //overload the operator < for 2 fractions. 
        bool operator<(const Fraction &frac2) const;
        //overload the operator >= for 2 fractions. 
        bool operator>=(const Fraction &frac2) const;
        //overload the operator <= for 2 fractions. 
        bool operator<=(const Fraction &frac2) const;



        //overload the operator + for fraction and float. 
        Fraction operator+(float num) const;
        //overload the operator - for fraction and float. 
        Fraction operator-(float num) const;
        //overload the operator * for fraction and float. 
        Fraction operator*(float num) const;
        //overload the operator / for fraction and float. 
        Fraction operator/(float num) const;
        //overload the operator == for fraction and float.
        bool operator==(float num) const;
        //overload the operator != for 2 fractions. 
        bool operator!=(float num) const;
        //overload the operator > for fraction and float.
        bool operator>(float num) const;
        //overload the operator < for fraction and float. 
        bool operator<(float num) const;
        //overload the operator >= for fraction and float. 
        bool operator>=(float num) const;
        //overload the operator <= for fraction and float. 
        bool operator<=(float num) const;



        //overload the operator + for float and fraction. 
        friend Fraction operator+(float num,const Fraction &frac2);
        //overload the operator - for float and fraction. 
        friend Fraction operator-(float num,const Fraction &frac2);
        //overload the operator * float and fraction. 
        friend Fraction operator*(float num,const Fraction &frac2);
        //overload the operator / float and fraction. 
        friend Fraction operator/(float num,const Fraction &frac2);
        //overload the operator == float and fraction. 
        friend bool operator==(float num,const Fraction &frac2);
        //overload the operator != for 2 fractions. 
        friend bool operator!=(float num,const Fraction &frac2);
        //overload the operator > float and fraction. 
        friend bool operator>(float num,const Fraction &frac2);
        //overload the operator < float and fraction. 
        friend bool operator<(float num,const Fraction &frac2);
        //overload the operator >= float and fraction. 
        friend bool operator>=(float num,const Fraction &frac2);
        //overload the operator <= float and fraction. 
        friend bool operator<=(float num,const Fraction &frac2);
        
        //overload the operator prefix ++. 
        Fraction &operator++();
        //overload the operator prefix --. 
        Fraction &operator--();
        //overload the operator postfix ++. 
        Fraction operator++(int);
        //overload the operator postfix --. 
        Fraction operator--(int);

        //overload the operator << for fraction. 
        friend std::ostream& operator<<(std::ostream &ostream_, const Fraction &fraction);
        //overload the operator >>. 
        friend std::istream& operator>>(std::istream &istream_, Fraction &fraction);


    };
}   


