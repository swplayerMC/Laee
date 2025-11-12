#include <stdio.h>
//#include <string.h>

int main(int argc, char *argv[]) {
  char version[] = "0.0.1-dev";
  FILE *pFile = fopen(argv[1], "r");
  char buffer[1024] = {0};

  if(pFile == NULL) {
    if (argc == 1) {
      printf("Lae\tversion %s\nRun 'lae help' to see the usage guide\n", version);
      return 0;
    }
    printf("Could not open file\n");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
    printf("%s", buffer);
  }
  fclose(pFile);
  return 0;
}
