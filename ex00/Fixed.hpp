/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:08:56 by nolecler          #+#    #+#             */
/*   Updated: 2025/07/30 14:10:53 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    public :
        Fixed(); // constructeur par defaut
        Fixed(const Fixed& other); // constructeur de recopie
        Fixed &operator=(const Fixed& ex); // operateur d'affectation
        int getRawBits( void ) const;
        void setRawBits(int const raw);
        ~Fixed();
    
    private :
        int _nbr;
        static const int _fractBits = 8;
};

#endif
