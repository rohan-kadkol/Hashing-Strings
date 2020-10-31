#include <stdio.h>
#include <string.h>

#define Z 2
#define TABLE_SIZE 149

int hashFunction(char *);
void readFile(char *);
void addToHashTable();

int main() {
    readFile("textFile.txt");
}

void readFile(char *fileName) {
    char c[1000];
    FILE *file;

    if ((file = fopen(fileName, "r")) == NULL) {
        printf("Filed to open the file: %s", fileName);
    }

    char word[100];
    int wordLength = 0;

    char ch;
    while ((ch = (char)fgetc(file)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            word[wordLength++] = (char)ch;
        } else {
            if (wordLength) {
                printf("Wordlength: %d", wordLength);
                addToHashTable(word, wordLength);
                wordLength = 0;
            }
        }
    }
    if (wordLength) {
        addToHashTable(word, wordLength);
        wordLength = 0;
    }
}

void addToHashTable(char *word, int wordLength) {
    word[wordLength] = '\0';
    printf("Added: %s\n", word);
}

int hashFunction(char *string) {
    int length = strlen(string);
    int pz = string[length - 1];
    for (int i = length - 2; i >= 0; i--) {
        pz = string[i] + Z * pz;
    }

    return pz % TABLE_SIZE;
}