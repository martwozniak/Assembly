#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

double getDurationMs(const steady_clock::time_point start, const steady_clock::time_point end) {
	return duration<double, milli>(end-start).count();
}

int rnd(int min = 0, int max = 100) {
	return rand() % (max - min) + min;
}

int main() {
	srand((unsigned)time(0));
	steady_clock::time_point start, end;

	int a = rnd(), b = rnd(), c;
	start = steady_clock::now();
	__asm {
		pushad
		pushfd

		mov eax, a
		add eax, b
		mov c, eax

		popfd
		popad
	}
	end = steady_clock::now();

	cout << a << " + " << b << " = " << c << endl;
	cout << "Duration: " << getDurationMs(start, end) << " ms" << endl;

	system("pause");
	return 0;
}
