// Computing dot product
#include <iostream>

int main(int argc, char **argv)
{
	// memoria = stack(estatico) + heap(dinamica)
	
	// primitive arrays //limited by stack size
	int N = 10000;
	double v1[N]{9.87, -0.65, 7.65432};
	double * ptr = nullptr;
	ptr = &v1[0];
	std::cout << v1[0] << std::endl; // 9.87
	std::cout << &v1[0] << std::endl; // dir memoria primer elemento
	std::cout << &v1[1] << std::endl; // dir memoria segundo elemento (dir anterior + 8 byte)
	std::cout << ptr << std::endl; // dir memoria primer elemento
	std::cout << ptr[0] << std::endl; // 9.87
	std::cout << ptr[1] << std::endl; // -0.65
	std::cout << *(ptr + 2) << std::endl; // 7.65432
	std::cout << *(v1 + 2) << std::endl; // 7.65432
	std::cout << v1 << std::endl; // dir memoria
	
	return 0;
}
