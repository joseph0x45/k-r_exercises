#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_LEN 10

int main() {
  int state, c, current_length;
  state = OUT;
  current_length = c = 0;
  int histogram[MAX_LEN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        if (current_length + 1 >= MAX_LEN) {
          current_length = MAX_LEN - 1;
        }
        histogram[current_length - 1]++;
      }
      state = OUT;
      current_length = 0;
    } else {
      state = IN;
      current_length++;
    }
  }
  if (state == IN) {
    if (current_length + 1 >= MAX_LEN) {
      current_length = MAX_LEN - 1;
    }
    histogram[current_length - 1]++;
  }
  for (int i = 0; i < MAX_LEN; i++) {
    printf("%d: ", i + 1);
    for (int j = 0; j < histogram[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
