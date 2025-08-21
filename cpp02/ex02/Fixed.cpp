
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


// ----------------------------------operators
bool Fixed::operator>(const Fixed &other) const
{
    if (this->_value > other._value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->_value < other._value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->_value >= other._value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->_value <= other._value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->_value == other._value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (this->_value != other._value)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result = this->toFloat() + other.toFloat();
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result = this->toFloat() - other.toFloat();
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result = this->toFloat() * other.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result = this->toFloat() / other.toFloat();
    return result;
}

// return ref because we return it after incre
Fixed& Fixed::operator++()
{
    this->_value += 1;
    return *this;
}

// return copy because we want the value before incre
Fixed Fixed::operator++(int){
    Fixed tmp = *this;
    this->_value += 1;
    return tmp;
}

Fixed& Fixed::operator--(){
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp = *this;
    this->_value -= 1;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a > b)
        return a;
    return b;
}

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}