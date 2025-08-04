✅ ❌

To-Do List pour Fixed.cpp

1. Constructeurs et destructeur
✅   Implémenter le constructeur par défaut
✅   Implémenter le constructeur de copie
✅   Implémenter le constructeur à partir d’un int
✅   Implémenter le constructeur à partir d’un float
✅   Implémenter le destructeur


2. Opérateur d’affectation
✅   Implémenter l’opérateur= (affectation)


3. Getters et setters
✅   Implémenter la méthode getRawBits() const
✅   Implémenter la méthode setRawBits(int const raw)


4. Conversion
✅    Implémenter la méthode toFloat() const
✅    Implémenter la méthode toInt() const


5. Opérateurs de comparaison
✅        Implémenter operator>(const Fixed& other) const
 ✅        Implémenter operator<(const Fixed& other) const
 ✅        Implémenter operator>=(const Fixed& other) const
 ✅        Implémenter operator<=(const Fixed& other) const
 ✅        Implémenter operator==(const Fixed& other) const
 ✅        Implémenter operator!=(const Fixed& other) const


6. Opérateurs arithmétiques
 ✅        Implémenter operator+(const Fixed& other) const
 ✅        Implémenter operator-(const Fixed& other) const
  ✅       Implémenter operator*(const Fixed& other) const
 ✅        Implémenter operator/(const Fixed& other) const


7. Opérateurs d’incrémentation/décrémentation
  ✅       Implémenter la pré-incrémentation operator++()
 ✅        Implémenter la post-incrémentation operator++(int)
  ✅       Implémenter la pré-décrémentation operator--()
  ✅       Implémenter la post-décrémentation operator--(int)

8. Fonctions membres statiques
        Implémenter static Fixed& min(Fixed& a, Fixed& b)
        Implémenter static const Fixed& min(const Fixed& a, const Fixed& b)
        Implémenter static Fixed& max(Fixed& a, Fixed& b)
        Implémenter static const Fixed& max(const Fixed& a, const Fixed& b)

9. Opérateur de flux externe

   ✅  Implémenter l’opérateur << pour l’affichage (std::ostream &operator<<(std::ostream &out, const Fixed &obj))