#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;


class Array
{
    friend ostream &operator<<( ostream &, const Array & );
    friend istream &operator>>( istream &, Array & );

        public:
            Array( int = 10 );
            Array( const Array &);
            ~Array();
            int getSize() const;
            const Array & operator = ( const Array &right );
            bool operator ==( const Array &right ) const;
            int & operator []( int subscript );
            int operator[]( int subscript ) const;


        private:
            int size;
            int *ptr;
};

#endif // ARRAY_H
