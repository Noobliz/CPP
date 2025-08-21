
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

        int getRawBits(void) const;
        void setRwaBits(int const raw);
        float toFloat(void) const;
		int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &other);
//#endif