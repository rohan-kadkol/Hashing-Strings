#include <stdio.h>
#include <string.h>

#define Z 2
#define TABLE_SIZE 149

int hashFunction(char *);

int main() {
  char *string = "abcd";
  printf("String length: %d\n", hashFunction(string));
}

int hashFunction(char *string) {
  int length = strlen(string);
  int pz = string[length - 1];
  for (int i = length - 2; i >= 0; i--) {
    pz = string[i] + Z * pz;
  }

  return pz % TABLE_SIZE;
}