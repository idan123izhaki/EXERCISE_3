#include <iostream>
#include "vector.hpp"

int main()
{
	Vector v1;
	v1.push_back(8);
	v1.push_back(4);
	v1.push_back(6);
	v1.push_back(9);
	v1.push_back(7);
	v1.push_back(3);
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "The vector elements are: " << v1;
	v1.pop_back();
	v1.pop_back();
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "The vector elements are: " << v1;

	std::string result = v1.empty() ? "true" : "false";
	std::cout << "The vector is empty? " << result << std::endl;
	
	v1.resize(6, 100);

	std::cout << v1;
	Vector v2;
	v2 = v1;
	std::cout << v2;
	(v2 == v1) ? std::cout << "Elements in both vectors are equals." << std::endl : std::cout << "Not equal vectors..." << std::endl;

	return 0;
}
