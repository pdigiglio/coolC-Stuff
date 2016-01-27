/**
 *
 *    @file  conversions.cpp
 *   @brief  Try out some cast operator with classes
 *
 *    @date  01/27/16
 *  @author  Paolo Di Giglio (github.com/pdigiglio),
 *           <p.digiglio91@gmail.com>
 *
 */

#include <iostream>

class B {
	public:
		B(): _b(0.) {};
		B(int input): _b(input) {};
		~B() {};

		inline int getVar() const { return _b; };
	private:
		const int _b;
};

class A {
	public:
		A(): _a(0.) {};
		A(double input): _a(input) {};
		~A() {};

		inline double getVar() const { return _a; };

		/** @brief Implicit cast operator `B` to `A`. */
		A(const B& input): _a(input.getVar()) {};
	private:
		const double _a;
};

class C {
	public:
		C(float input): _c(input) {};

		inline float getVar() const { return _c; };

		/** @brief Explicit cast operator `C` to `A`. */
		explicit operator A() const {
			A a(static_cast<int>(_c));
			return a;
		};

	private:
		const float _c;
};

double f (A a) {
	return a.getVar();
}

int main (void) {

	A a(1);
	B b(2);
	C c(3);

	std::cout << f(a) << std::endl;

	// This will fail at compile time unless A has a cast operator
	// XXX !! This will be an implicit cast !!
	std::cout << f(b) << std::endl;
	
	// This has to be manually casted!
	std::cout << f(static_cast<A>(c)) << std::endl;

	return 0;
}
