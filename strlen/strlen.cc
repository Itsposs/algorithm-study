
#include <chrono>   // now()
#include <cassert>  // assert()
#include <cstddef>  // size_t

size_t strlen(const char *str) {

	assert(str != nullptr);
	const char *s;
	//for(s = str; *s; ++s) { }
	s = str;
	while (*s) {
		++s;
	}
	return (s - str); // (s - str) type ?
}

#include <iostream>  // test

void test_strlen() {
	
	size_t len = strlen("hello world!");
	std::cout << "len:" << len << std::endl;
}


int main(int argc, char *argv[]) {

	using namespace std::chrono;
	auto beg = system_clock::now();

	test_strlen();
	
	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count() 
			  << " ms."   << std::endl;
	return 0;
}
