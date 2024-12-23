#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &inst)
{
   // std::cout << "Copy constructor called" << std::endl;
    this->_fixed = inst._fixed;
}

Fixed& Fixed::operator=(const Fixed& inst)
{
    //std::cout << "Copy assignement operator called" << std::endl;
        if (this != &inst) 
        {
            (this->_fixed) = (inst._fixed);
        }
        return *this;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "Function getRawBits called" << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits(int val)
{
    //std::cout << "Function setRawBits called" << std::endl;
    this->_fixed = val;
    return;
}

Fixed::Fixed(const int intVal)
{
   // std::cout << "Int constructor called" << std::endl;
    this->_fixed = intVal << this->_bits;
}

Fixed::Fixed(const float floVal)
{
    //std::cout << "Float constructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &os, const Fixed &inst)
{
	os << inst.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed& inst)
{
	return this->_fixed < inst._fixed; 
}

bool Fixed::operator>(const Fixed& inst)
{
	return this->_fixed > inst._fixed;
}

bool Fixed::operator<=(const Fixed& inst)
{
	return this->_fixed <= inst._fixed;
}

bool Fixed::operator>=(const Fixed& inst)
{
	return this->_fixed >= inst._fixed;
}

bool Fixed::operator==(const Fixed& inst)
{
	return this->_fixed == inst._fixed;
}

bool Fixed::operator!=(const Fixed& inst)
{
	return this->_fixed != inst._fixed;
}

Fixed Fixed::operator+(const Fixed& inst)
{
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() + inst.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(const Fixed& inst)
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - inst.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed& inst)
{
	Fixed tmp;

	tmp.setRawBits((int)(((long) this->getRawBits() * (long) inst.getRawBits()) >> this->_bits));
	return tmp;
}

Fixed Fixed::operator/(const Fixed& inst)
{
	Fixed tmp;

	tmp.setRawBits((int)(((long) this->getRawBits() / (long) inst.getRawBits()) >> this->_bits));
	return tmp;
}

Fixed& Fixed::min(Fixed& instA, Fixed& instB)
{
	if (instA._fixed < instB._fixed)
		return instA;
	else if (instA._fixed > instB._fixed)
		return instB;
	return instA;
}

const Fixed& Fixed::min(const Fixed& instA, const Fixed& instB) //they are the same, but one exist to create the const compatibility
{
	if (instA._fixed < instB._fixed)
		return instA;
	else if (instA._fixed > instB._fixed)
		return instB;
	return instA;
}


Fixed& Fixed::max(Fixed& instA, Fixed& instB)
{
	if (instA._fixed < instB._fixed)
		return instB;
	else if (instA._fixed > instB._fixed)
		return instA;
	return instA;
}

const Fixed& Fixed::max(const Fixed& instA, const Fixed& instB)
{
	if (instA._fixed < instB._fixed)
		return instB;
	else if (instA._fixed > instB._fixed)
		return instA;
	return instA;
}

Fixed& Fixed::operator++() //++a
{
	this->_fixed++; //Incrementa the current object directly
	return *this; //Return a reference to the now-incremented object (*this)
}

Fixed& Fixed::operator--()
{
	this->_fixed--; 
	return *this;
}

Fixed Fixed::operator++(int) //a++
{
	Fixed tmp(*this);

	this->_fixed++; //but after the call, a becomes a++
	return tmp; //Return the copy of what the object looked like before incrementing
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->_fixed--;
	return tmp;
}

