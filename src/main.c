#include <stdio.h>

int main() {
  char msg[] = "Lae\tversion 0.0.1-dev\n";
  printf("%s", msg);
    FILE *p_file = fopen("/home/calebe/Dev/Lae/examples/variables.lae", "r");
  char buffer[1024] = {0};

  if(p_file == NULL) {
    printf("Could not open file\n");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), p_file) != NULL) {
    printf("%s", buffer); 
  }
  fclose(p_file);
  return 0;
}
