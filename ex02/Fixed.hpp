// banniere


#ifndef FIXED_HPP
# define FIXED_HPP

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


