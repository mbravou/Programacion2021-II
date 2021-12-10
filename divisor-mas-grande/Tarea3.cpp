#include <iostream>

int main (void)
{
	long int N;
	N = 600851475147;
	std::cout << "N = " << N << "\n";
	std::cout << "Divisores de N" << "\n";

	long int x = 1;   //divisores
	long int dmg; //divisor más grande

	for(x = 1; x <= N/3; x++)
	{
		if(N%x == 0)
		{
			std::cout << "Divisor = " << x << "\n";
			dmg = x;
		}

	}
	std::cout << "Divisor más grande de N = " << dmg << "\n";

	return 0;
}
