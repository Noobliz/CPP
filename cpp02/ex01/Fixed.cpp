#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0){
    std::cout<<"Default constructor called"<<std::endl;
}


Fixed::Fixed(const Fixed &other){
    std::cout<<"Copy constructor called"<<std::endl;
    this->_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &other)
    {
        std::cout<<"copy from an other instance"<<std::endl;
        this->_value = other.getRawBits();
    }
    return (*this);
}
//having a cake that we always want to divide in x equal slices
//ex: 5 * 256 same as 5 << _fractionalBits
// once converted, we can get the int back with intVal = _value >> _fractionalBits
// pas de 1 << n car on garde les bits a 0 car par de fraction
Fixed::Fixed(const int intVal)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->_value = intVal << _fractionalBits;
}

//set the fractional part with 8 bits instead of floating
Fixed::Fixed(const float floatVal)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->_value = roundf(floatVal * (1 <<_fractionalBits));
}

Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
}
//-------------------------------------------------member functions
int Fixed::getRawBits(void) const{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->_value);
}

void Fixed::setRwaBits(int const raw){
    std::cout<<"setRawBits member function called"<<std::endl;
    this->_value = raw;
}
//ex: stocking 340cl, if i want to know how many liters: 340 / 100 = 3.40L
float Fixed::toFloat(void) const
{
    float res;
    res = (float)this->_value / (1 << _fractionalBits);
    return (res);
}

//removing fractional part 
int Fixed::toInt(void) const
{
    int res;
    res = this->_value >> _fractionalBits;
    return (res);
}

//-------------------------------------------------------operand
std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
    out<<other.toFloat();
    return (out);
}

