
#pragma once
# include <iostream>
# include <math.h>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits;

    public:
        Fixed(); // default constr
        Fixed(const int intVal);
        Fixed(const float floatVal);
        Fixed(const Fixed &other); // copy constr
        Fixed &operator=(const Fixed &other); // copy assignment operator overload (replace object's datas by an other one)
        ~Fixed();

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();        // pré++
        Fixed operator++(int);      // post++
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);


        int getRawBits(void) const;
        void setRwaBits(int const raw);
        float toFloat(void) const;
		int toInt(void) const;


};

std::ostream &operator<<(std::ostream &out, const Fixed &other);
//#endif