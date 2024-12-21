#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Fixed
{
    private:
    int _fixed;
    static const int _bits = 8;

    public:
    Fixed(); //default const
    ~Fixed();//destruct
    Fixed(const Fixed &inst);//copy const
    Fixed& operator=(const Fixed &inst); //copy assignemnt oper
    int getRawBits(void) const;
    void setRawBits(int val);
    //ex01
    Fixed(const int fixedVal);
	Fixed(const float fixedVal);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif

