# trie-data-base
In computer science, a trie, also called digital tree or prefix tree, is a kind of search tree—an ordered tree data structure used to store a dynamic set or associative array where the keys are usually strings. Unlike a binary search tree, no node in the tree stores the key associated with that node; instead, its position in the tree defines the key with which it is associated; i.e., the value of the key is distributed across the structure. All the descendants of a node have a common prefix of the string associated with that node, and the root is associated with the empty string. Keys tend to be associated with leaves, though some inner nodes may correspond to keys of interest. Hence, keys are not necessarily associated with every node. For the space-optimized presentation of prefix tree, see compact prefix tree.

In the example shown, keys are listed in the nodes and values below them. Each complete English word has an arbitrary integer value associated with it. A trie can be seen as a tree-shaped deterministic finite automaton. Each finite language is generated by a trie automaton, and each trie can be compressed into a deterministic acyclic finite state automaton.

Though tries can be keyed by character strings, they need not be. The same algorithms can be adapted to serve similar functions on ordered lists of any construct; e.g., permutations on a list of digits or shapes. In particular, a bitwise trie is keyed on the individual bits making up any fixed-length binary datum, such as an integer or memory address.(from wiki trie)

![Screenshot 2021-01-17 105351](https://user-images.githubusercontent.com/73063199/104835890-59dcd600-58b2-11eb-831d-5801f990fb54.png)


for more info:
https://www.youtube.com/watch?v=-urNrIAQnNo&ab_channel=LukasVyhnalek
https://www.geeksforgeeks.org/trie-insert-and-search/
https://en.wikipedia.org/wiki/Trie
