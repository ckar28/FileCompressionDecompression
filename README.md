<h1 align='center'> FileZipper_Huffman</h1>

## Features
It can compress the file size by Half or more.(50%-60%)

Used **Huffman's algorithm** to construct **a tree** that is used for data compression. 
Assumed that each character has an associated weight equal to the number of times the character occurs in a file.
When compressing a file we'll need to calculate these weights.

## Huffman Coding Algorithm Description

Huffman's algorithm assumes that we're building a single tree from a group (or forest) of trees. 
Initially, all the trees have a single node with a character and the character's weight. 
Trees are combined by picking two trees, and making a new tree from the two trees. 
This decreases the number of trees by one at each step since two trees are combined into one tree.

### Algorithm Steps:

1. Begin with a forest of trees. All trees are one node, with the weight of the tree equal to the weight of the character in the node. 
Characters that occur most frequently have the highest weights. Characters that occur least frequently have the smallest weights.
Repeat this step until there is only one tree.

2. Choose two trees with the smallest weights, call these trees T1 and T2. Create a new tree whose root has a weight equal to the sum of the weights T1 + T2 and whose left subtree is T1 and whose right subtree is T2.

3. The single tree left after the previous step is an optimal encoding tree.


## Implemetation of Algorithm

There are two parts to an implementation: a compression program and an un-compression/decompression program. 
You need both to have a useful compression utility. We'll assume these are separate programs, but they share many classes, functions, modules, code. 

- We'll call the program that reads a regular file and produces a compressed file the **compression or huffing program**.  
- The program that does the reverse, producing a regular file from a compressed file, will be called the **uncompression or un-huffing program**.


### Data Structures Used
- Two **unordered maps**, one for the character and coding pairs and another for the character and the frequency or number of times repeated.
- One **priority queue** to apply the minimum heap minimum extraction property in the tree construction algorithm.



### Challenges Encountered

The operating system often buffers output for efficiency when writing, which means the data is saved to disk only when the internal buffer is full and not each time the program writes to a stream. Files must usually be in a size that is a multiple of specific units, like a byte or word, determined by the architecture or operating system. This results in files not being able to have a size of 122 bits on some systems. Although all the bits will eventually be written, the exact timing during program execution is uncertain.

Buffering can also result in extra bits being written, known as "padding bits," to make the total number of bits a multiple of eight. Our decompression program must account for these padding bits as they do not contain compressed information. To do this, we check if the size of the bit string is a multiple of 8 and calculate the necessary padding bits using the modulo of 8.

Additionally, we added a pseudo EOF character within the human-readable ASCII range, allowing the user to use any ASCII characters without restrictions.