#include "triehash.hh"

void read_and_write_dict(const char filename[],
												 const char compressedfilename[]) {
	/*
		should read in the words in ASCII and create a compact stored form
		and write it out to disk
	 */
	triehash<'a', 26> th = triehash::read_ascii(filename);
	th.save(compressedfilename);
}

int main() {
	read_and_write_dict("dict213k.txt", "compdict213k.cdic");
	read_and_write_dict("dict466k.txt", "compdict466k.cdic");
	triehash<'A', 26> th("compdict213k.cdic");
}
