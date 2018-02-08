// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BFInt.h"
#include <chrono>

using namespace std;

int main() {
	
	BFInt a, b, c, d, e, f;
	char q;
	
	c = 0x12345678;
	d = 0x77654321;

	cout.flags(ios::hex);

	e.randomfill(64);
	f.randomfill(64);

	auto smallstart = chrono::high_resolution_clock::now();
	a = c * d;
	auto smallfinish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed1 = smallfinish - smallstart;
	auto normalstart = chrono::high_resolution_clock::now();
	b = e * f;
	auto normalfinish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed2 = normalfinish - normalstart;
	auto karatsubastart = chrono::high_resolution_clock::now();
	c = karatsuba(e, f);
	auto karatsubafinish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed3 = karatsubafinish - karatsubastart;

	cout << "Small:     " << elapsed1.count() * 1000000 << "us" << endl;
	cout << "a =        "<< endl << a << endl;
	cout << "Normal:    " << elapsed2.count() * 1000000 << "us" << endl;
	cout << "b =        " << endl << b << endl;
	cout << "Karatsuba: " << elapsed3.count() * 1000000 << "us" << endl;
	cout << "c =        " << endl << c << endl;
	cout << "b - c =    " << b - c << endl;
	d = (e * f) / f;
	cout << "(e * f) / f - e =  " << endl << d - e << endl;
	cout << "(e * f) % e - e =  " << endl << (e * f) % e - e << endl;
	cout << "(e * f) % f - f =  " << endl << (e * f) % f - f << endl;
//	q = getchar();
	cout << "Primes!" << endl;
	BFInt num = 1, stop = 0x400;
	num <<= 0;
	stop <<= 0;
//	int i = 0;
	BFInt p = 0;
//	auto startall = chrono::high_resolution_clock::now();

	while (num < stop) {
//		auto start = chrono::high_resolution_clock::now();
		if (num.isPrime()) {
			p++;
//			auto finish = chrono::high_resolution_clock::now();
			cout << num.toBCD() << endl;
//			chrono::duration<double> elapsed1 = finish - start;
//			cout << " Time: " << elapsed1.count() * 1000 << "ms" << endl;
		}
		num++;

//		num *= 10ull;
//		i++;

//		c = getchar();
//		if (c == 'p')
//			return 0;
	}

//	cout << endl << "num = " << num << " = 10^" << i << endl;

//	auto finishall = chrono::high_resolution_clock::now();
//	chrono::duration<double> elapsed2 = finishall - startall;
	cout << " All finished! Found " << p.toBCD() << " primes between 1 and " << stop.toBCD() << endl;
//	cout << " Time: " << elapsed2.count()  << " seconds" << endl;

//	b = 7;
//	num = 1;
//	num <<= 62;
//	cout << "root(" << num / 7 << ") = " << sqrt(num / b) << endl;
//	cout << "root(2^62 / 7) = " << " 0x306123cd" << endl;
//	num = 1234567812345678ull;
//	cout << num << "=" << num.toBCD() << endl;

	q = getchar();
	return 0;
}