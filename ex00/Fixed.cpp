/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:46:33 by nolecler          #+#    #+#             */
/*   Updated: 2025/07/30 14:22:01 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _nbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nbr);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _nbr = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& ex)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ex)
        this->_nbr = ex.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    this->_nbr = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

