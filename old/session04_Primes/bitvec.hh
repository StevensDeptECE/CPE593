#pragma once

class Bitvec {
private:
	uint32_t size;
	uint64_t* bits;
public:
	Bitvec(uint32_t size, bool b) : size(size), bits(new uint64_t[(size+63)/64]) {
		uint64_t val = b ? 0xFFFFFFFFFFFFFFFF : 0;
		for (int i = 0; i < size; i++)
			bits[i] = val;
	}
	~Bitvec() { delete [] bits; }
	Bitvec(const Bitvec& orig) = delete;
	Bitvec& operator =(const Bitvec& orig) = delete;
	/*
		0000000000x00000
    0000000000000001 << pos
    0000000000100000

	 */
  void set(uint32_t i) {
		bits[i / 64] |= 1 << (i % 64);
		//		bits[i >> 6] |= 1 << (i & 0x3f);
	}

  	/*
		yyyyyyyyyyxyyyyy
    1111111111111110 << pos
    1111111111011111

	 */
	void clear(uint32_t i) {
		bits[i / 64] &= ~(1 << (i % 64));
		//		bits[i >> 6] &= (1 << (i & 0x3f));
	}

	bool test(uint32_t i) {
		return (bits[i / 64] & (1 << (i % 64))) != 0;
	}
};
