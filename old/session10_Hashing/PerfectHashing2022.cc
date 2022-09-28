//pseudocode for perfect hashing

hash(key) {
  return key % size
}

//given hashmap of size n
insert(map, key, val)
  h = hash(key)
  list t = map.preparedtable[h]
	t.add(pair(key,val))
end


	preparePerfectHashMap(map, listofkey_val_pairs)
	  for each pair
   	  insert(map, key, val)
    end

		for each bin in preparedtable
			t=map.preparedtable[bin]
	    numberofelements = t.size()
	    for childbins = numberofelements to ...
       	child <-- new hashmap(childbins)
	      for each e <-- each element in t
	         ...	        
	
