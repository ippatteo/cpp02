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
    static const int _bits;

    public:
    Fixed(); //default const
    ~Fixed();//destruct
    Fixed(const Fixed &inst);//copy const
    Fixed& operator=(const Fixed &inst); //copy assignemnt oper
    int getRawBits(void) const;
    void setRawBits(int val);
};

#endif

