/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:08:56 by nolecler          #+#    #+#             */
/*   Updated: 2025/08/06 11:02:24 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    public :
        Fixed();
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed& ex);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
    
    private :
        int _nbr;
        static const int _fractBits = 8;
};

#endif
