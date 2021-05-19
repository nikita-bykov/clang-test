#include <algorithm>
#include <vector>
#include <random>
#include <thread>

void hello()
{
	// Reproduces build failure on clang 3.9
	std::mt19937 m_rgen;
	std::vector<int> v;
	std::shuffle(v.begin(), v.end(), m_rgen);
}

int main()
{
	// Reproduces segfault on clang 9 (?)
	std::thread t(hello);
	t.join();
	return 0;
}