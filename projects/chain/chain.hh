#pragma once
#include <cstdint>

template<uint32_t outdegree>
class chain {
private:
	struct node {
		uint8_t type;
		uint32_t line_count; // total number of lines in this node and below
		uint32_t offset[outdegree];
	};
	char* text;
	node root;
	/*
		internal function to reorder the text into a single, sequential stream

		Once the text is sequential, it can be written out in a single write
		the question is, is this worth the cost?
	*/
	void defragment();
public:
	struct mark {
		uint32_t line;
		uint32_t col;
	};

	struct range {
		mark start, end;
	};
	chain(uint32_t lines, uint32_t text_size);
	~chain();
	chain(const chain& orig) = delete;
	chain& operator =(const chain& orig) = delete;
	chain(chain&& orig);
	chain(const char filename[]);
	void append(const char s[], uint32_t len);
	void insert(uint32_t line, uint32_t col, const char s[], uint32_t len);
	void remove(int32_t line);
	void remove(uint32_t minline, uint32_t maxline);
	chain cut(uint32_t minline, uint32_t mincol,
						uint32_t maxline, uint32_t maxcol);
	void paste(uint32_t minline, uint32_t mincol, const chain& c);
	mark search(const char s[], uint32_t len) const;
	void load(const char filename[]);
	void save(const char filename[]);
};
