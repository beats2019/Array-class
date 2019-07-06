#include <iostream>
#include "Array.h"
using namespace std;



    int main()
    {
        matrix obj( 3, 3 );
        matrix obj2( 4, 3 );
        matrix obj3( obj );
/*
        obj2 = obj;

        if( obj != obj2 )
            cout << "They are different!";
        if( obj == obj2 )
            cout << "They are same!";

*/
        cout << obj3;




        return 0;
    }



