#include "Fraction.hpp"
#include <iostream>
#include <stdio.h>
#include <climits>

using namespace ariel;
using namespace std;

    int Fraction::gcd(int t,int b){
        if (b == 0)
        {
            return t;
        }
        return gcd(b, t % b);
    }


    void Fraction::reduse(){
        int g=abs(gcd(abs(_t),abs(_b)));
        this->_t/=g;
        this->_b/=g;
        if (this->_b < 0){
                this->_t *= -1;
                this->_b *= -1;
            
        }
    }

    Fraction::Fraction(int top, int bottom)
    :_t(top), _b(bottom)
    {   
        if(_b==0)
            throw std::invalid_argument("cant devide by 0!");
        this->reduse();
    }

    Fraction::Fraction(float num){
        int val = num * 1000;
        float float_val = (float)val / 1000;
        *this = Fraction(float_val * 1000, 1000);
    }

    Fraction::Fraction(double num){
        *this= Fraction(float(num));
    }

    Fraction::Fraction(){
        _t = 1;
        _b = 1;
    }
    
       
    //overload the operator + for 2 fractions. 
    Fraction Fraction::operator+(const Fraction &frac2) const{
        long int a=_t*frac2._b;
        long int b= _b*frac2._t;
        if ((a+b < INT_MIN) || (a+b > INT_MAX))
            throw overflow_error("int out of range"); 
        Fraction new_f((_t*frac2._b+_b*frac2._t),(_b*frac2._b));
        new_f.reduse();
        return new_f;
    }
    //overload the operator - for 2 fractions. 
    Fraction Fraction::operator-(const Fraction &frac2) const{
        long int a=_t*frac2._b;
        long int b= _b*frac2._t;
        if ((a-b < INT_MIN) || (a-b > INT_MAX))
            throw overflow_error("int out of range"); 
        Fraction new_f((_t*frac2._b-_b*frac2._t),(_b*frac2._b));
        new_f.reduse();
        return new_f;
    }
    //overload the operator * for 2 fractions. 
    Fraction Fraction::operator*(const Fraction &frac2) const{
        long long int a = this->_t;
        long long int b = frac2._t; //this->_b*frac2._b;
        if ((a*b < INT_MIN) || (a*b > INT_MAX))
            throw overflow_error("int out of range"); 
        a=this->_b;
        b=frac2._b;
        if ((a*b < INT_MIN) || (a*b > INT_MAX))
            throw overflow_error("int out of range");
        Fraction new_f(this->_t*frac2._t,this->_b*frac2._b);
        new_f.reduse();
        return new_f;
    }
    //overload the operator / for 2 fractions. 
    Fraction Fraction::operator/(const Fraction &frac2) const{
        if(frac2._t==0)
            throw runtime_error("can't devide by 0");
        Fraction new_f(frac2._b,frac2._t);
        return this->operator*(new_f);
    }
    //overload the operator == for 2 fractions. 
    bool Fraction::operator==(const Fraction &frac2) const{
        bool frac1pos = false, frac2pos = false;
        //if top is 0
        if((this->_t==0 && frac2._t!=0) || (this->_t!=0 && frac2._t==0))
            return false;
        else if(this->_t==0 && frac2._t==0)
            return true;
        //checks for positivity
        if((this->_t>=0))
            frac1pos=true;
        if((frac2._t>=0))
            frac2pos=true;
        //if diff sign return false
        if ((frac1pos==false&&frac2pos==true)||(frac1pos==true&&frac2pos==false))   
            return false;
        //because in reduse we are simplifing the fraction to be same format of neg and pos
        else{
            if((this->_t != frac2._t) || this->_b != frac2._b)
                return false;
            return true;
        }
    }
    //overload the operator != for 2 fractions. 
    bool Fraction::operator!=(const Fraction &frac2) const{
        return !(this->operator==(frac2));
    }
    //overload the operator > for 2 fractions. 
    bool Fraction::operator>(const Fraction &frac2) const{
        // because a/b > c/d == a*d > b*c
        if ((this->_t * frac2._b) > (this->_b * frac2._t))
            return true;
        return false;
    }
    //overload the operator < for 2 fractions. 
    bool Fraction::operator<(const Fraction &frac2) const{
        // because a/b < c/d == a*d < b*c
        if ((this->_t * frac2._b) < (this->_b * frac2._t))
            return true;
        return false;
    }
    //overload the operator >= for 2 fractions. 
    bool Fraction::operator>=(const Fraction &frac2) const{
        if((this->operator>(frac2))||(this->operator==(frac2)))
            return true;
        return false;
    }
    //overload the operator <= for 2 fractions. 
    bool Fraction::operator<=(const Fraction &frac2) const{
       if((this->operator<(frac2))||(this->operator==(frac2)))
            return true;
        return false;
    }


    //overload the operator + for fraction and float. 
    Fraction Fraction::operator+(float num) const{
        Fraction frac2(num);
        return this->operator+(frac2);
    }
    //overload the operator - for fraction and float. 
    Fraction Fraction::operator-(float num) const{
        Fraction frac2(num);
        return this->operator-(frac2);
    }
    //overload the operator * for fraction and float. 
    Fraction Fraction::operator*(float num) const{
        Fraction frac2(num);
        return this->operator*(frac2);
    }
    //overload the operator / for fraction and float. 
    Fraction Fraction::operator/(float num) const{
        if(num==0.0)
            throw runtime_error("can't devide by 0");
        Fraction frac2(num);
        return this->operator/(frac2);
    }
    //overload the operator == for fraction and float.
    bool Fraction::operator==(float num) const{
        Fraction frac2(num);
        return this->operator==(frac2);
    }
    //overload the operator != for fraction and float.
    bool Fraction::operator!=(float num) const{
        Fraction frac2(num);
        return this->operator!=(frac2);
    }
    //overload the operator > for fraction and float.
    bool Fraction::operator>(float num) const{
        Fraction frac2(num);
        return this->operator>(frac2);
    }
    //overload the operator < for fraction and float. 
    bool Fraction::operator<(float num) const{
        Fraction frac2(num);
        return this->operator<(frac2);
    }
    //overload the operator >= for fraction and float. 
    bool Fraction::operator>=(float num) const{
        Fraction frac2(num);
        return this->operator>=(frac2);
    }
    //overload the operator <= for fraction and float. 
    bool Fraction::operator<=(float num) const{
        Fraction frac2(num);
        return this->operator<=(frac2);
    }



    //overload the operator + for float and fraction. 
    Fraction ariel::operator+(float num,const Fraction &frac2){
        Fraction frac1(num);
       return frac1.operator+(frac2);
    }
    //overload the operator - for float and fraction. 
    Fraction ariel::operator-(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator-(frac2);
    }
    //overload the operator * float and fraction. 
    Fraction ariel::operator*(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator*(frac2);
    }
    //overload the operator / float and fraction. 
    Fraction ariel::operator/(float num,const Fraction &frac2){
        if(frac2.getNumerator()==0)
            throw runtime_error("can't devide by 0");
        Fraction frac1(num);
        return frac1.operator/(frac2);
    }
    //overload the operator == float and fraction. 
    bool ariel::operator==(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator==(frac2);
    }
    //overload the operator != float and fraction. 
    bool ariel::operator!=(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator!=(frac2);
    }
    //overload the operator > float and fraction. 
    bool ariel::operator>(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator>(frac2);
    }
    //overload the operator < float and fraction. 
    bool ariel::operator<(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator<(frac2);
    }
    //overload the operator >= float and fraction. 
    bool ariel::operator>=(float num,const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator>=(frac2);
    }
    //overload the operator <= float and fraction. 
    bool ariel::operator<=(float num, const Fraction &frac2){
        Fraction frac1(num);
        return frac1.operator<=(frac2);
    }
    
     //overload the operator prefix ++. 
    Fraction &Fraction::operator++(){
        this->_t += this->_b;
        return *this;
    }
    //overload the operator prefix --. 
    Fraction &Fraction::operator--(){
        this->_t -= this->_b;
        return *this;
    }
    //overload the operator postfix ++. 
    Fraction Fraction::operator++(int){
        Fraction new_f= *this;
        this->operator++();
        return new_f;
    }
    //overload the operator postfix --. 
    Fraction Fraction::operator--(int){
        Fraction new_f= *this;
        this->operator--();
        return new_f;
    }

    //overload the operator << for fraction. 
    std::ostream &ariel::operator<<(std::ostream &os, const Fraction &fraction){
        if(fraction._b<0){
            os << (-1)*fraction._t << "/" << (-1)*fraction._b ;
        }
        else{
            os << fraction._t << "/" << fraction._b ;
        }
        return os;
    }
    //overload the operator >>. 
    std::istream &ariel::operator>>(std::istream &is, Fraction &fraction){
        int top=0;
        int bottom=0;
        is >> top >> bottom;
        if(bottom==0)
            throw runtime_error("not enogh parameters");
        fraction._t=top;
        fraction._b=bottom;
        fraction.reduse();
        return is;
    }



    