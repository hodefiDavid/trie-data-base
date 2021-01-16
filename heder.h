//
// Created by david on 1/16/21.
//

#ifndef TRIE_DATA_STRUCTURE_HEDER_H
#define TRIE_DATA_STRUCTURE_HEDER_H
#define ARRAY_SIZE 26 //as the number of the english letters
#define FROM_A_TO_NUM 97 // char 'a' == 97 in ascii therefore I reduce the value of the chars in 97
#define FROM_A_TO_a 32 // char 'A' == 65 in ascii therefore I added 32 to it in order to reach 'a'
typedef struct _node {
    //char letter will hold the letter that connected to this node
    char letter;
    //int end_of_word will hold integer that represent if the word is ended,
    //0 - word not ended
    //1 - word ended once 2 twice and so on
    int end_of_word;

    char *word;
    //connected_nodes - arrays of pointers that represent the connected nodes
    struct _node *connected_nodes[ARRAY_SIZE];
} node, *p_node;

void print_r(p_node ptr);

void print_nor(p_node ptr);

void cleanUp(p_node ptr);















#endif //TRIE_DATA_STRUCTURE_HEDER_H
