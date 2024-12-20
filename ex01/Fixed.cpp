#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &inst)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed = inst._fixed;
}

Fixed& Fixed::operator=(const Fixed& inst)
{
    std::cout << "Copy assignement operator called" << std::endl;
        if (this != &inst) 
        {
            (this->_fixed) = (inst._fixed);
        }
        return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "Function getRawBits called" << std::endl;
    std::cout << this->_fixed << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits(int val)
{
    std::cout << "Function setRawBits called" << std::endl;
    this->_fixed = val;
    return;
}

Fixed::Fixed(const int intVal)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed = intVal << this->_bits;
}

Fixed::Fixed(const float floVal)
{
    std::cout << "Float constructor called" << std::endl;
    float copy;
    this->_fixed = roundf(floVal * (1 << this->_bits)) ;
}

float Fixed::toFloat(void) const
{
	return float(this->_fixed) / (1 << this->_bits);
}

int Fixed::toInt(void) const
{
	return this->_fixed >> this->_bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}


