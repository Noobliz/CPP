#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits;

    public:
        Fixed(); // default constr
        Fixed(const Fixed &other); // copy constr
        Fixed &operator=(const Fixed &other); // copy assignment operator overload (replace object's datas by an other one)
        ~Fixed();

        int getRawBits(void) const;
        void setRwaBits(int const raw);

};

#endif