/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:44:47 by nolecler          #+#    #+#             */
/*   Updated: 2025/08/05 09:41:01 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    public :

        Fixed(); // constructeur par defaut (fixed a;)
        Fixed(const Fixed& other); // constructeur de recopie (fixed b(a);  je crrer b en copiant a)
        Fixed &operator=(const Fixed& ex); // operateur d'affectation (b = a)
        ~Fixed();

        Fixed(const int i); 
        Fixed(const float f);

        bool operator>(const Fixed& other) const; 
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        // et retourne une référence vers le plus petit. Donc modifiable
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b); // static : pas besoin d un objet this
        static Fixed& max(Fixed& a, Fixed& b); 
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;


     private :
        int _nbr;
        static const int _fractBits = 8; // toute valeur reelle est multiplier par 2^8 donc 256 puis arrondi au plus proche
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif


