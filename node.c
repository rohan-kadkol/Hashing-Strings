#include<stdlib.h>
#include<stdlib.h>

struct _Node {
    char* word;
    int frequency;
    struct _Node* node;
};
typedef struct _Node Node;

Node* create_node(char* word, int maxWordLength) {
    char* w = malloc(maxWordLength);
    memcpy(w, word, maxWordLength);

    Node* node = malloc(sizeof(Node));
    node->frequency=1;
    node->word=w;
    node->node=NULL;
    return node;
}