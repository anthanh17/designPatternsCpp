#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_block (int n, char c) {
	mtx.lock();
	for (int i = 0; i < n; i++)
		std::cout << c;
	std::cout << std::endl;
	mtx.unlock();
}

int main() {

	std::thread th1 (print_block, 10, '*');
	std::thread th2 (print_block, 20, '$');
	
	th1.detach();
	th2.detach();
	if (th1.joinable())
		th1.join();
	if (th2.joinable())
		th2.join();

	std::cout << "helllo!"
	return 0;
}
