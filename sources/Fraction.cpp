#include "Fraction.hpp"
#include <iostream>
#include <stdio.h>

using namespace ariel;
using namespace std;

    int Fraction::gcd(int t,int b){
        if(t<0)
            t=t*-1;
        if(b<0)
            b=b*-1;
        if(t == 0)
            return b;
        else if(b == 0)
            return t;
        if(t < b)
            return gcd(t, b % t);
        else
            return gcd(b, t % b);
    }


    void Fraction::reduse(){
        int g=gcd(_t,_b);
        _t=_t/g;
        _b=_b/g;
    }

    Fraction::Fraction(int top, int bottom)
    :_t(top), _b(bottom)
    {
        if(_b==0)
            throw std::invalid_argument("cant devide by 0!");
        this->reduse();
    }

    Fraction::Fraction(float num)//in part b i will add fuction to convert float to fraction
    {
        if(num==0.0){
            *this= Fraction(0,1);
        }
        else{
            int accuracy=1000;
            num=num*accuracy;
            int new_num=(int)num;
            int g = gcd(new_num,accuracy);
            Fraction a(new_num/g,accuracy/g);
            a.reduse();
            *this=a;
        }

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
        Fraction new_f((_t*frac2._b+_b*frac2._t),(_b*frac2._b));
        new_f.reduse();
        return new_f;
    }
    //overload the operator - for 2 fractions. 
    Fraction Fraction::operator-(const Fraction &frac2) const{
        Fraction new_f((_t*frac2._b-_b*frac2._t),(_b*frac2._b));
        new_f.reduse();
        return new_f;
    }
    //overload the operator * for 2 fractions. 
    Fraction Fraction::operator*(const Fraction &frac2) const{
        Fraction new_f(this->_t*frac2._t,this->_b*frac2._b);
        new_f.reduse();
        return new_f;
    }
    //overload the operator / for 2 fractions. 
    Fraction Fraction::operator/(const Fraction &frac2) const{
        Fraction new_f(this->_t*frac2._b,this->_b*frac2._t);
        new_f.reduse();
        return new_f;
    }
    //overload the operator == for 2 fractions. 
    bool Fraction::operator==(const Fraction &frac2) const{
        bool frac1pos = false, frac2pos = false;
        if((this->_t>=0 && this->_b>=0)||(this->_t<=0 && this->_b<=0))
            frac1pos=true;
        if((frac2._t>=0 && frac2._b>=0)||(frac2._t<=0 && frac2._b<=0))
            frac2pos=true;
        //diff sign
        if (frac1pos ^ frac2pos)   
            return false;
        //both neg
        else if (frac1pos==false && frac2pos==false){
            if(((this->_t*(-1)) != frac2._t) && (this->_b*(-1)) != frac2._b)
                return false;
            return true;
        }
        else{
            if(((this->_t) != frac2._t) && (this->_b) != frac2._b)
                return false;
            return true;
        }
    }
    //overload the operator != for 2 fractions. 
    bool Fraction::operator!=(const Fraction &frac2) const{
        if(this->_t!=frac2._t&&this->_b!=frac2._b)
            return true;
        return false;
    }
    //overload the operator > for 2 fractions. 
    bool Fraction::operator>(const Fraction &frac2) const{
        if((this->operator-(frac2)).getNumerator()>0)
            return true;
        return false;
    }
    //overload the operator < for 2 fractions. 
    bool Fraction::operator<(const Fraction &frac2) const{
        if((this->operator-(frac2)).getNumerator()<0)
            return true;
        return false;
    }
    //overload the operator >= for 2 fractions. 
    bool Fraction::operator>=(const Fraction &frac2) const{
        if((this->operator-(frac2)).getNumerator()>=0)
            return true;
        return false;
    }
    //overload the operator <= for 2 fractions. 
    bool Fraction::operator<=(const Fraction &frac2) const{
       if((this->operator-(frac2)).getNumerator()<=0)
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
            throw std::invalid_argument("cant devide by 0!");
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
            throw std::invalid_argument("cant devide by 0!");
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
        return is;
    }



    