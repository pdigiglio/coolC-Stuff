/**
 *
 *    @file  types.cpp
 *   @brief  Show that typedefs are not always type-safe.
 *
 *    @date  01/29/16
 *  @author  Paolo Di Giglio (github.com/pdigiglio),
 *           <p.digiglio91@gmail.com>
 *
 */

#include <iostream>

typedef struct B {
	typedef unsigned short myType;
	myType _b = 1;
} B;

typedef struct C {
	typedef double myType;
	myType _c = 2;
} C;

B::myType f( B::myType b ) {
	return b;
}

int main () {
	B b;
	C c;

	std::cout << f( b._b ) << std::endl;
	// XXX !! This is not typesafe! c._c has type C::myType !!
	// That's because the compiler knows how to convert double
	// into unsigned short
	std::cout << f( c._c ) << std::endl;
}
