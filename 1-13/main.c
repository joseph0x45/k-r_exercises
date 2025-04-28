#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_LEN 10

void histogram_horizontal(int histogram[MAX_LEN]) {
  for (int i = 0; i < MAX_LEN; i++) {
    printf("%d: ", i + 1);
    for (int j = 0; j < histogram[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}
void histogram_vertical(int histogram[MAX_LEN], int frequency) {
  for (int i = frequency; i > 0; i--) {
    for (int j = 0; j < MAX_LEN; j++) {
      if (histogram[j] >= i) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  for (int i = 0; i < MAX_LEN; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");
}

int main() {
  int state, c, current_length, frequency;
  state = OUT;
  frequency = current_length = c = 0;
  int histogram[MAX_LEN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        if (current_length + 1 >= MAX_LEN) {
          current_length = MAX_LEN - 1;
        }
        histogram[current_length - 1]++;
        if (current_length > frequency) {
          frequency = current_length;
        }
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
  /* histogram_horizontal(histogram); */
  histogram_vertical(histogram, frequency);
  return 0;
}
