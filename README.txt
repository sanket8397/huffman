Data compression of text file using Huffman Data compression technique


Name : Sanket Surendra Kapse
MIS No. : 111408027


Steps Involved
1. First source file is read and frequency of each char is counted and stored in a linked list.
2. Link list is sorted in ascending order. For this link list is breaked into nodes and finally merged into a sorted linklist.
3. Huffman tree is constructed using Huffman algorithm function htree() is used.
4. Now each character is a leaf node.
5. In order to get what binary string is used by each leaf node we have to traverse tree.
6. print paths() and printPathsRecur() function is used to find the binary string that leads to leaf node. This binary string ie t->01 e ->001 h-> 110 is stored in linked list.
7. Now our linked list contains variable size for each character as opposed to fixed 8 bits.
8. Now second time we read the  Source file for converstion into binary form. Here the first character in file is taken and search into linklist so as to convert into binary form. eg "the" word which is three bytes is replaced into binary form like 01110001 now this requiers only 1 byte hence compressed.
9.If we stored binary string 01110001 in file it will used Eight bytes, so could not store into string form. So we converted binary string 0110001 into ascii value ie 113 and character stored for ascii value in  zip file is 'K'. Function used is b_to_decod().
10. Now further if you want to unzip file then you have to read zip file character by character and convert into binary form which is also a variable length encoding.
11. finally you are now with binary string with variable encoding. Now you call function conv_bin_char() which converts binary string into characters by searching binary string in linklist and replace substring using char.

Problem Encountered and Solved.
1.
Memory Problem: First it was able to solve only few characters like abcddd. Then we improved code so that it can deal with larger code. for that we used dynamic memory allocation. We allocated first 1024 bytes and if it is less we used function realloc to increase it by 2 times 1024.
2.
Characters like NULL which is 00000000 if in binary string creates problems as it was checked for EOF and the program used to stop.
Characters like 00001010 which is newline character could allowed to used line by line encoding so we could not used line by line encoding.
Also Ascii value of 255  which is 11111111 also could not be used because it was having problem while decoding.
so we solved problem by inerting 1 after every five '0' so that NULL will not be encountered and for every 11111111 after every five '1' we inserted a '0', we removed it at the time of decoding.
3.
Lot of time was wasted in traversing a tree without recursively so that patteren of t->01 e ->001 h-> 110 could be made but could be solved easily using recursive.
4.
For decoding binary string it should be in multiple of eight bits, however if it is less than eight bit then the last substring was not stored in file so was a problem.
Solution Suggestion of length to be stored in file hinted me with option to used first three bits as control bits. The control bits gives value of 0 to 7 means how many bits are padded to make a last byte complete of eight bits.


 
