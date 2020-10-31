#include <stdio.h>
#include <string.h>

#include "node.c"

#define Z 2
#define TABLE_SIZE 149
#define MAX_WORD_LENGTH 100

Node* hashTable[TABLE_SIZE];

int hashFunction(char*);
void readFile(char*);
void addToHashTable(char* word);
Node* searchChain(Node** hashTable, int address, char* word);
void printHashTable(Node* hashTable[]);

int main() {
    memset(hashTable, '\0', TABLE_SIZE * sizeof(Node*));
    readFile("textFile.txt");
    printHashTable(hashTable);
}

void readFile(char* fileName) {
    char c[1000];
    FILE* file;

    if ((file = fopen(fileName, "r")) == NULL) {
        printf("Filed to open the file: %s", fileName);
    }

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;

    char ch;
    while ((ch = (char)fgetc(file)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            word[wordLength++] = (char)ch;
        } else {
            if (wordLength) {
                word[wordLength] = '\0';
                printf("!@#!@#!@#!@#\n");
                addToHashTable(word);
                wordLength = 0;
            }
        }
    }
    if (wordLength) {
        word[wordLength] = '\0';
        printf("##############\n");
        addToHashTable(word);
        wordLength = 0;
    }

    fclose(file);
}

void addToHashTable(char* word) {
    printf("START\n");
    printf("%s\n", word);
    if (hashTable[132]) {
        printf("hashTable[132] = %s\n", hashTable[132]->word);
    }
    if (hashTable[59]) {
        printf("hashTable[59] = %s\n", hashTable[59]->word);
    }
    if (hashTable[85]) {
        printf("hashTable[85] = %s\n", hashTable[85]->word);
    }
    printf("END\n");

    int address = hashFunction(word);
    // printf("%s hashes to %d\n", word, address);
    Node* node = searchChain(hashTable, address, word);
    // printf("%u", node);

    if (node == NULL) {
        // printf("HERE %s\n", word);
        Node* node = create_node(word, MAX_WORD_LENGTH);
        Node* oldNode = hashTable[address];
        node->node = oldNode;
        hashTable[address] = node;
        // printf("HERE %s\n", node->word);
        // printf("HERE %s\n", hashTable[address]->word);
    } else {
        node->frequency++;
    }
}

Node* searchChain(Node* hashTable[], int address, char* word) {
    if (hashTable[address] != NULL) {
        Node* node = hashTable[address];
        while (node != NULL) {
            if (strcmp(node->word, word) == 0) {
                return node;
            }
            node = node->node;
        }
        return NULL;
    }
    printf("*****************\n");
    return NULL;
}

int hashFunction(char* string) {
    int length = strlen(string);
    int pz = string[length - 1];
    for (int i = length - 2; i >= 0; i--) {
        pz = string[i] + Z * pz;
    }

    return pz % TABLE_SIZE;
}

void printHashTable(Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("i = %d ", i);
            printf("Word: %s, Frequency: %d\n", hashTable[i]->word,
                   hashTable[i]->frequency);
            fflush(stdout);
        }
    }
    // printf("HHHUH: %s\n", hashTable[132]->word);
}