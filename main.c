#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heder.h"

int main(int argc, char **argv) {

    int what_to_print = 0;
    if (argc > 1) {
        if ((char) *argv[1] == 'r') {
            what_to_print = 1;
        }
    }

    p_node head = NULL;
    head = realloc(head, sizeof(node));
    if (head == NULL) {
        printf("error with realloc, sorry");
        free(head);
        return -1;
    }

    head->end_of_word= 0;
    head->letter = '\0';
    char *word = NULL;
    char temp_ch = ' ';
    int tempLenght = 0;
    while (temp_ch != EOF) {
        temp_ch = (char) getc(stdin);
        //65 in ascii == 'A' , 90 in ascii == 'Z'
        if (temp_ch >= 65 && temp_ch <= 90) {
            temp_ch = temp_ch + FROM_A_TO_a;
        }
        //97 in ascii == 'a' , 122 in ascii == 'z'
        if (temp_ch >= 97 && temp_ch <= 122) {
            tempLenght++;
            char *tmp_allo = realloc(word, tempLenght);
            if (tmp_allo == NULL) {
                printf("error with realloc, sorry");
                cleanUp(head);
                free(word);
                free(tmp_allo);
                return -1;
            }
            word = tmp_allo;
            word[tempLenght - 1] = temp_ch;

        } else {
            if (temp_ch == '\t' || temp_ch == '\n' || temp_ch == ' ') {
                p_node ptr = head;

                for (int i = 0; i < tempLenght; ++i) {
                    if (ptr->connected_nodes[word[i] - FROM_A_TO_NUM] == NULL) {
                        p_node node_tmp = NULL;
                        node_tmp = realloc(node_tmp, sizeof(node));
                        if (node_tmp == NULL) {
                            printf("error with realloc, sorry");
                            cleanUp(head);
                            free(word);
                            return -1;
                        }

                        ptr->connected_nodes[word[i] - FROM_A_TO_NUM] = node_tmp;
                    }
                    ptr = ptr->connected_nodes[word[i] - FROM_A_TO_NUM];
                    ptr->letter = word[i];
                    if (i == tempLenght - 1) {
                        ptr->end_of_word++;
                        ptr->word = realloc(ptr->word, tempLenght);
                        if (ptr->word == NULL) {
                            printf("error with realloc, sorry");
                            cleanUp(head);
                            free(word);
                            return -1;
                        }
                        strcpy(ptr->word, word);
                        ptr->word[tempLenght] = '\0';
                    }
                }
                ptr = head;
                tempLenght = 0;
            }
        }
    }

// if what_to_print == 0
// we need  Print out the list of words seen in the input
// along with the number of occurrences for each word
// sorted in ascending lexicographic order.
    if (!what_to_print) {
        print_nor(head);
    }
// if what_to_print == 0
// if what_to_print == 1 the user write r
// we need  Print out the list of words seen in the input
// along with the number of occurrences for each word
// sorted in descending lexicographic order.
    else {
        print_r(head);
    }

    free(word);
    cleanUp(head);
    return 0;
}

void cleanUp(p_node ptr) {

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (ptr->connected_nodes[i] != NULL) {
            cleanUp(ptr->connected_nodes[i]);
        }
    }
    free(ptr->word);
    free(ptr);
}


void print_nor(p_node ptr) {

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (ptr->end_of_word > 0) {
            printf("%s %d \n", ptr->word, ptr->end_of_word);
            ptr->end_of_word = 0;}

        if (ptr->connected_nodes[i] != NULL) {
            print_nor(ptr->connected_nodes[i]);}

    }
}

void print_r(p_node ptr) {

    for (int i = ARRAY_SIZE-1; i >= 0; i--) {
        if (ptr->end_of_word > 0) {
            printf("%s %d \n", ptr->word, ptr->end_of_word);
            ptr->end_of_word = 0;}

        if (ptr->connected_nodes[i] != NULL) {
            print_r(ptr->connected_nodes[i]);}

    }
}
