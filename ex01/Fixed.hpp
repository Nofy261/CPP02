/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:34:28 by nolecler          #+#    #+#             */
/*   Updated: 2025/07/30 14:36:37 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
//  a remplacer par pragma once 

#include <iostream>

// Un constructeur qui prend un entier constant (int) en paramètre.
// Il convertira cet entier en valeur à virgule fixe.

// Un constructeur qui prend un nombre flottant constant (float) en paramètre.
// Il convertira ce float en valeur à virgule fixe.


//  Fonctions membres publiques :

//  float toFloat(void) const;
//  ➤ Convertit la valeur à virgule fixe en nombre flottant (float).

//   int toInt(void) const;
//    ➤ Convertit la valeur à virgule fixe en entier (int).


//  Surcharge d’opérateur :

//  Une surcharge de l’opérateur << (insertion dans un flux)
//  ➤ Elle doit afficher la représentation flottante du nombre à virgule fixe dans le std::ostream fourni.


class Fixed {
    public :
        Fixed(); // constructeur par defaut
        Fixed(const Fixed& other); // constructeur de recopie
        Fixed &operator=(const Fixed& ex); // operateur d'affectation, const car on copie depuis un objet qu on ne doit pas modifier

        Fixed(const int i); 
        Fixed(const float f);

        float toFloat(void) const;
        int toInt(void) const;

        int getRawBits( void ) const;
        void setRawBits(int const raw);
        ~Fixed();


    
    private :
        int _nbr;
        static const int _fractBits = 8;
};

// permet d ecrire std::cout << ex; ex=objet Fixed
// fct qui affiche un objet Fixed avec << 
// ici const car on ne modifiera pas l'objet ex 
// je dit à C++ : "Voici comment afficher un Fixed quand on écrit std::cout << fixedObject"
std::ostream &operator<<(std::ostream &out, const Fixed &obj);




#endif