#include <iostream>
#include "heap.h"

int main(int argc, char *argv[])
{
	Heap heap;
	char ch;
	int num;
	int min;

	while (std::cin >> ch) {

		switch (ch) {
			case 'i':
				std::cout << "숫자를 입력하세요: ";
				std::cin >> num;
				heap.insert(num);
				break;
			case 'm':
				try {
					min = heap.min();
					std::cout << "최솟값: " << min << std::endl;
				} catch (const char *e) {
					std::cout << *e << std::endl;
				}
				break;
			case 'r':
				try { 
					heap.remove();
				} catch (const char *e) {
					std::cout << *e << std::endl;
				}
				break;
			case 's':
				heap.sort();
				break;
		}
	}

	return EXIT_SUCCESS;
}
