
#include "../header/Fixed.hpp"

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

Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->_value);
}

void Fixed::setRwaBits(int const raw){
    std::cout<<"setRawBits member function called"<<std::endl;
    this->_value = raw;
}
