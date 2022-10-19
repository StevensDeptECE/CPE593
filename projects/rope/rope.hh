#pragma once
#include <cstdint>

class rope {
private:
	struct node {
		char val;
		uint32_t offset;
	};
	node root;
	/*
		internal function to reorder the text into a single, sequential stream

		Once the text is sequential, it can be written out in a single write
		the question is, is this worth the cost?
	*/
public:
	struct mark {
        //TODO: implement
	};

	struct range {
        //TODO: implement
	};
	rope(const char filename[]);
	~rope();
	rope(const rope& orig) = delete;
	rope& operator =(const rope& orig) = delete;
	rope(chain&& orig);
	void append(const char s[], uint32_t len);

	//void insert(const char s[], uint32_t len);
	void remove(uint32_t pos);
	void remove(uint32_t start, uint32_t end);
	rope cut(uint32_t minline, uint32_t mincol,
						uint32_t maxline, uint32_t maxcol);
	void paste(uint32_t minline, uint32_t mincol, const rope& r);
	mark search(const char s[], uint32_t len) const;
	void load(const char filename[]);
	void save(const char filename[]);
};
