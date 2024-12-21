#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
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
    this->_fixed = roundf(floVal * (1 << this->_bits)) ; //float = 1/256 * x
}

float Fixed::toFloat(void) const
{
	return float(this->_fixed) / (1 << this->_bits); //inversa di floval
}

int Fixed::toInt(void) const
{
	return this->_fixed >> this->_bits; //shifta di 8 bits e ba, cosi i bit si trovano in pos
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat(); //converto in float e immetto nello stream
	return os;
}


