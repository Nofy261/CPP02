/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:44:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/08/06 12:56:08 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#include <cmath>

Fixed::Fixed() : _nbr(0)
{
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::Fixed(const int i)
{
    this->_nbr = i << _fractBits;
}

Fixed::Fixed(const float f)
{
    this->_nbr = roundf(f * (1 << _fractBits));
}

int Fixed::getRawBits(void) const
{
    return (this->_nbr);
}

void Fixed::setRawBits(int const raw)
{
    this->_nbr = raw;
}

Fixed& Fixed::operator=(const Fixed& ex)
{
    if (this != &ex)
        this->_nbr = ex.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
    return ((float)_nbr / (1 << _fractBits));
}

int Fixed::toInt(void) const
{
    return (_nbr >> _fractBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_nbr > other._nbr);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_nbr < other._nbr);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_nbr >= other._nbr);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_nbr <= other._nbr);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_nbr == other._nbr);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_nbr != other._nbr);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    
    result._nbr = this->_nbr + other._nbr;
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    
    result._nbr = this->_nbr - other._nbr;
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;

    if (other._nbr == 0) // protection pour la division par zero
       return (this->_nbr >> _fractBits); // affiche la vrai valeur
    result._nbr = (this->_nbr << _fractBits) / other._nbr;
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;

    result._nbr = (this->_nbr * other._nbr) >> _fractBits;
    return (result);
}

Fixed& Fixed::operator++()
{
    this->_nbr += 1;
    return (*this);
}

Fixed& Fixed::operator--()
{
    this->_nbr -= 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
   Fixed copyObj(*this);
   
   this->_nbr += 1;
   return (copyObj);
}

Fixed Fixed::operator--(int)
{
    Fixed copyObj(*this);
    
    this->_nbr -= 1;
    return (copyObj);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);    
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);    
}