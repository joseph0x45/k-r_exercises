#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int c, current_length, state;
  c = current_length = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      for (int i = 0; i < current_length; i++) {
        printf("*");
      }
      printf("\n");
      current_length = 0;
    } else if (state == OUT) {
      ++current_length;
    }
  }
  return 0;
}
