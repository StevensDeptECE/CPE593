#pragma once
/*
	aa aah aal aali 
  aa = 12 entries start with this
  ab = too many 100+
    aba = 
    abb = 
    abc = 

  qu
 


  format to save
  4 bytes = num_words
  4 bytes num_prefixes = 17k?
  list of all prefixes 
  count1
  count2
  count3
   ...

  aa END1 aba END1 abb END1
  
	END1 h END1 l END1 li END1

  encoded using 64-bit numbers arithmetic encoding

   (( a << 5)| a) << 5 ...

  ((a * 28 + a)* 28 + END1) *28

nodes[0] [ 1   2    3    ... 26]
nodes[1] [ 27 28 29...   52]
nodes[2] [53 ...         78]

nodes[27] [ hashmap


 */
template<uint32_t start_letter, uint32_t num_letters>
class triehash {
private:
	class trienode {
	public:
    uint32_t next[26];		
	};

	class hashnode {
	public:
		uint32_t table_offset;
		uint32_t table_size;
		
	};

	class hashtable {
	public:
		uint32_t word;
	}
	// root = nodes[0]
	trienode* nodes;
	hashnode* hashnodes;
	hashtable* table;
	/*
		int hashnodeoffset = nodes[nodes[0].next['a']];
		uint32_t start = hashnodes[hashnodeoffset].table_offset;
		uint32_t size = hashnodes[hashnodeoffset].table_size;
		int pos = hash(key)
		table[start ... start+size]
    table[start+(pos & size)] // linear probing, check for collisions

	 */
	
	uint32_t num_words; // total number of words in the dictionary
	uint32_t node_size;
	uint32_t node_capacity;
	uint32_t max_hash_size; // maximum number of words allowed in each hash
  	
public:
	static triehash read_ascii(const char filename[]);
	triehash(const char compressedfilename[]);

	

};
