/**
 *
 *    @file  virtualOverrideFinal.cpp
 *   @brief  
 *
 *    @date  01/28/16
 *  @author  Paolo Di Giglio (github.com/pdigiglio),
 *           <p.digiglio91@gmail.com>
 *
 */

#include <iostream>

class A {
	public:
		virtual ~A() { std::cout << "dtor A\n" << std::endl; };
};

class B: public A {
	public:
		~B() override { std::cout << "dtor B" << std::endl; };
};

class C: public A {
	public:
		~C() override final { std::cout << "dtor C" << std::endl; };
};

class D: public B { //XXX !! Cannot inheritate from C as ~C() is final !!
	public:
		~D() override final { std::cout << "dtor D" << std::endl; };
};

int main () {
	A a;
	B b;
	C c;
	D d;

	return 0;
}
