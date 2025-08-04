/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:44:47 by nolecler          #+#    #+#             */
/*   Updated: 2025/08/04 12:57:48 by nolecler         ###   ########.fr       */
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


        // methode qui va comparer deux objets , const a la fin car cette methode ne modifiera pas *this
        // arg passer en parmatre const car on ne modifiera pas l objet , juste comparer
        // return true ou false
        bool operator>(const Fixed& other) const; 
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const; // fixed result = a + b ou a.operator+(b);
        Fixed operator-(const Fixed& other) const; // fixed result = a - b ou a.operator-(b);
        Fixed operator/(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;


        Fixed& operator++(); // pre incrementation ++a, incremente a puis retourne a modifiee
        //fixed a, ++a, fixed b = ++a; b a la valeur de a qui ete incrementee 
        // on ajoute epsilon quand on fait a++ ou ++a , et epsilon = 1 / 2 ^ _fractBits soit 1/256 
        Fixed& operator--(); // pre decrementation --a , retourne un reference
        Fixed operator++(int); // post incrementation a++, copie a puis incremente a et retourne la copie qui n a pas ete incrementee
        // fixed a, fixed b = a++ , b vaut la copie de a qui n a pas ete incremtee et a vaut une valeur qui a ete incrementee
        Fixed operator--(int); // post decrementation a--; retourne une copie



        // Une fonction membre statique min qui prend deux références vers des nombres à virgule fixe comme paramètres, 
        // et retourne une référence vers le plus petit. Donc modifiable
        static Fixed& min(Fixed& a, Fixed& b); // compare deux objets qu on lui donne sans modifier ni utiliser l objet courant d ou le static

        // Une fonction membre statique min qui prend deux références constantes vers des nombres à virgule fixe comme paramètres, 
        // retourne une référence constante vers le plus petit. Donc non modifiable car const
        static const Fixed& min(const Fixed& a, const Fixed& b); // static : pas besoin d un objet this

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


