#include "hashdict.hh"

void read_and_write_dict(const char filename[],
												 const char compressedfilename[]) {
	/*
		should read in the words in ASCII and create a compact stored form
		and write it out to disk
	 */
	hashdict<'a', 26> hd = hashdict<'a', 26>::read_ascii(filename);
	hd.save(compressedfilename);
}

void testload(const char filename[]) {
	hashdict<'a', 26> th(filename);
}

int main() {
	read_and_write_dict("dict213k.txt", "compdict213k.cdic");
	read_and_write_dict("dict466k.txt", "compdict466k.cdic");
	testload("compdict213k.cdic");
}
