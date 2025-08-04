/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:44:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/08/04 14:02:45 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

#include <cmath>

Fixed::Fixed() : _nbr(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int i)
{
    this->_nbr = i << _fractBits;
}

//constructeur qui permet de convertir un float en nbr a virgule fixe
//va arroundir avec roundf et va stocker le chiffre arrondi dans _nbr
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
    //std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const // de 42 a 42.42
{
    float x = (float)_nbr / (float)(1 << _fractBits);
    return (x);
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


//sert a comparer la valeur _nbr de deux objets
// l objet courant this et l objet other qui est donnee en parametre
// si _nbr de this est plus grand que le _nbr de l'objet donnee en param on return true
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


// on additionne la valeur _nbr de l objet courant this et le _nbr de l'objet donnee en param
// on stocke la somme dans un nouveau objet et on la retourne
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

    result._nbr = this->_nbr / other._nbr;
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;

    result._nbr = this->_nbr * other._nbr;
    return (result);
}

Fixed& Fixed::operator++() //++a;
{
    this->_nbr += 1; // on incremente puis on retourne l'objet avec sa valeur qui a ete incrementee
    return (*this);
}

Fixed& Fixed::operator--() //--a;
{
    this->_nbr -= 1;
    return (*this);
}

// on fait une copie de l'objet courant
// on incremente la valeur de l objet courant
// on retourne la copie de l'objet cad l'objet courant avec la valeur avant l'incrementation
Fixed Fixed::operator++(int) //a++;
{
   Fixed copyObj(*this); // appel au constructeur de copie
   
   this->_nbr += 1;
   return (copyObj);
}


Fixed Fixed::operator--(int) //a--;
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