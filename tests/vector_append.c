#include <stdio.h>
#include <string.h>
#define concat(dest, src) strncat(dest, src, sizeof(src))

int main() {
  char vector[2][6] = {
    {"hello "},
    {"world\n"}
  };
  /* // Gotta hardcode that
  char typing1;
  char typing2;
  do {
    scanf("%c", &typing1);
    concat(vector[0], &typing1);
  } while (typing1 != '\n');
  do {
    scanf("%c", &typing2);
    concat(vector[1], &typing2);
  } while (typing2 != '\n');
  */
  for (int i = 0; i < sizeof(vector) / 6; i++) {
    for (int j = 0; j < sizeof(vector[i]); j++) {
      printf("%c", vector[i][j]);
    }
  }
  return 0;
}
