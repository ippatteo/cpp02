#ifndef FIXED.HPP
# define FIXED.HPP

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
    Fixed();
    ~Fixed();
    Fixed(const Fixed &inst);
    Fixed& operator=(const Fixed &inst);
    int getRawBits(void) const;
    void setRawBits(int val);
    //
    Fixed(const int fixedVal);
	Fixed(const float fixedVal);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif

