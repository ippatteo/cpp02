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

Fixed& Fixed::operator=(const Fixed&inst)
{
    std::cout << "Copy assignment operator called" << std::endl;
        if (this != &inst) 
        {
            (this->_fixed) = (inst._fixed);
			inst.getRawBits();
        }
        return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits(int raw)
{
    std::cout << "Function setRawBits called" << std::endl;
    this->_fixed = raw;
    return;
}
