# Hashing

[#Introduction]
Hashing is a technique for searching where the thing you are looking for (the key) is turned into the location to find it using a ___hash function___.

Hashing is used to implement a ___set___, or a ___map___ where each key has a corresponding value.

Hashing allows searching in O(1) time because it does not matter how many elements are in the hash map. To put something in the hash map, compute the hash, go to that location and put it in. To find something, hash the key, go to the location and check. If the location is empty, then the item is not in the hash map.

Hashing isn't quite that simple, because there are problems. The biggest problem is that multiple values can end up with the same position. This is called a collision. All of this session is focused on how to keep hashing O(1) and avoid as many collisions as possible.

[#Why Use Hashing?]
Let's start by taking a set of numbers and putting them into a hash table. A number is either in the set, or not, so if we put the same number in twice, it will just be stored once.

Suppose we use a list to implement the set. Put the following numbers into the list: 1, 3, 9, 2, 9, 1, 4.

The first 4 numbers can go in like this:

|1|3|9|2|

How long does this take? Well, each time we have to check that the number we are adding in is not already in the list. The first time takes 1. There is nothing in the list just put it in:

|1|

The second time takes 2. First check that the number 3 is not in the one element (it isn't) then add it to the list.

|1|3|

The third time takes 3: check whether it is in the list of 2 elements (it isn't) and then add it $2 + 1 = 3$.

|1|3|9

So the complexity is

$1 + 2 + 3 + ... + n = n(n+1) / 2 = O(n^2)$

[#Hash Functions]
Hashing is all about the function. Pick a poor function, and the number of collisions can be gigantic.


[#Linear Probing]

[#Linear Chaining]


[#Perfect Hashing]

[#Other Uses of Hashing]

[#Cryptographic Hashing]

[#Readings]

[#Homework]

