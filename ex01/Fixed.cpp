/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:34:31 by nolecler          #+#    #+#             */
/*   Updated: 2025/07/30 14:36:53 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#include <cmath>


// a retenir :

//     Si on veux garder la précision → utilise un float ou double

//     Si on veux juste la valeur entière (sans virgule) → utilise un int, donc tronqué

//     En C++, toute division entre deux int donne un int (donc tronqué)

//     Dès qu’un des deux opérandes est un float, le résultat est un float

Fixed::Fixed() : _nbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
    // rajouter un message d annonce
    std::cout << "Int constructor called" << std::endl;
    //this->_nbr = i * 256;
    // on decale de 8bits(_fracBits) a gauche le int i  = i * 256 
    // cette valeur represente un nombre a virgule fixe grace au decalage de 8
    this->_nbr = i << _fractBits;
}



// Fixed c(42.42f);

//     f = 42.42

//     f * 256 = 10859.52

//     roundf(...) = 10860

//     _nbr = 10860

//la classe Fixed garde en mémoire 10860 comme représentation “virgule fixe” de 42.42.


Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    // on multiplie le nombre flottant f * 256 = 256 car 
    // roundf arrondit le résultat à l’entier le plus proche. (ex 11.5 = 12 avec roundf)
    // roundf car on stocke un entier dans _nbr alors que f est un float d ou l utilisation roundf
    // Cette ligne transforme un float en nombre à virgule fixe en multipliant par 256 et arrondissant avant de stocker.
    this->_nbr = roundf(f * (1 << _fractBits));


}

//  ➤ Convertit la valeur à virgule fixe en nombre flottant (float). ( de 42 a 42.42)
// on ne tronque pas = on veut la valeur avec virgule 
    float Fixed::toFloat(void) const
    {
        // on convertit un entier en float et on retourne ce float
        // 1 << _fractBits signifie 2^8 = 256 
        return ((float)_nbr / (float)(1 << _fractBits));

        // ou return (_nbr / 256.0f);
    }

//    ➤ Convertit la valeur à virgule fixe en entier (int). (de 42.42 a 42)
// nombre fixe = nombre a virgule

int Fixed::toInt(void) const
{
    // decalage a droite de 8bits(_fractBits) pour enlever la partie decimale)
    return (_nbr >> _fractBits);
}


int Fixed::getRawBits(void) const
{
    return (this->_nbr);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
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


std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat(); // affiche la valeur en float
    return (out); // retourne le flux

}