/**
 *
 *    @file  arrayLength.cpp
 *   @brief  Template to return the size of an array
 *
 *    @date  01/22/16
 *  @author  Paolo Di Giglio (github.com/pdigiglio),
 *           <p.digiglio91@gmail.com>
 *
 */

#include <iostream>

template <typename T, size_t N>
constexpr size_t getArrayLength( T (&a)[N] ) noexcept {
	return N;
}

int main () {
	const char name[] = "P. Di Giglio";

	std::cout << "'" << name <<"' has "
		<< getArrayLength(name) - 1 << " characters." << std::endl;
	return 0;
}
