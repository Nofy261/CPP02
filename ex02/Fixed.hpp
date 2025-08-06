/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:44:47 by nolecler          #+#    #+#             */
/*   Updated: 2025/08/05 13:23:49 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    public :

        Fixed();
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed& ex);
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

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b); 
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;


     private :
        int _nbr;
        static const int _fractBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif


