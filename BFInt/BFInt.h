#pragma once
#include "stdafx.h"

class BFInt
{
public:
	static constexpr int arraysize = 1024;
	BFInt();
	BFInt(const int value);
	BFInt(const unsigned long long value);
	BFInt(const BFInt &);
	BFInt(const BFInt &&);
	BFInt &operator =(const BFInt &rhs);
	BFInt &operator =(const BFInt &&rhs);
	BFInt &operator =(int rhs);
	BFInt &operator =(unsigned long long rhs);
	friend bool operator ==(const BFInt &lhs, const BFInt &rhs);
	friend bool operator ==(const BFInt &lhs, const int rhs);
	friend bool operator !=(const BFInt &lhs, const BFInt &rhs);
	friend bool operator >(const BFInt &lhs, const BFInt &rhs);
	friend bool operator >=(const BFInt &lhs, const BFInt &rhs);
	friend bool operator <(const BFInt &lhs, const BFInt &rhs);
	friend bool operator <=(const BFInt &lhs, const BFInt &rhs);
	friend std::ostream &operator <<(std::ostream &out, const BFInt &bfintout);
	friend BFInt operator <<(BFInt lhs, unsigned int rhs);
	BFInt &operator <<=(const unsigned int rhs);
	friend BFInt operator >>(const BFInt lhs, const unsigned int rhs);
	BFInt &operator >>=(unsigned int rhs);
	friend BFInt operator +(BFInt lhs, const BFInt &rhs);
	BFInt &operator +=(const BFInt &rhs);
	friend BFInt operator -(BFInt op);
	friend BFInt operator -(const BFInt lhs, const BFInt &rhs);
	BFInt &operator -=(const BFInt &rhs);
	friend BFInt operator *(const BFInt lhs, const BFInt &rhs);
	BFInt &operator *=(const BFInt &rhs);
	friend BFInt operator /(BFInt lhs, const BFInt &rhs);
	BFInt &operator /=(const BFInt &rhs);
	friend BFInt operator %(const BFInt lhs, const BFInt &rhs);
	BFInt &operator %=(const BFInt &rhs);
	BFInt &operator ++();
	BFInt operator ++(int);
	bool isPrime();
	friend BFInt sqrt(const BFInt &a);
	BFInt abs(const BFInt &a);
	void randomfill(unsigned int in_size);
	friend BFInt karatsuba(const BFInt &a, const BFInt &b);
	BFInt toBCD();
	~BFInt();
private:
	friend BFInt inverse(const BFInt &a, unsigned int precision);
	bool positive;
	unsigned int size;
	unsigned char bigint[arraysize];
	unsigned int countbits() const;
	void shrink();
	void copychars(const unsigned char[], unsigned int size);
	void reverse();
	void zerochars();
	void zerochars(int);
};
void         mul(const unsigned char *lhs, unsigned int lhs_size, const unsigned char *rhs, unsigned int rhs_size, unsigned char *result);
unsigned int add(const unsigned char *lhs, unsigned int lhs_size, const unsigned char *rhs, unsigned int rhs_size, unsigned char *result);
unsigned int sub(const unsigned char *lhs, unsigned int lhs_size, const unsigned char *rhs, unsigned int rhs_size, unsigned char *result);
unsigned int getsizeofint(int in);
unsigned int getsizeofull(unsigned long long in);