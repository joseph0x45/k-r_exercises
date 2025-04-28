#include <stdio.h>
#define ARRAY_SIZE 26
#define A_ASCII_CODE 65
#define a_ASCII_CODE 97

int main() {
  int A_to_Z[ARRAY_SIZE] = {0};
  int a_to_z[ARRAY_SIZE] = {0};
  int c;
  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z') {
      A_to_Z[c - A_ASCII_CODE]++;
    } else if (c >= 'a' && c <= 'z') {
      a_to_z[c - a_ASCII_CODE]++;
    }
  }
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%c: ", i + A_ASCII_CODE);
    for (int j = 0; j < A_to_Z[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%c: ", i + a_ASCII_CODE);
    for (int j = 0; j < a_to_z[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}
