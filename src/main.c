#include <stdio.h>
#include <string.h>

void print_usage_guide() {
      printf("usage:\t[file] [options] or\n\t[command] [options]\n\t");
}

int main(int argc, char *argv[]) {
  char version[] = "0.0.1-dev";
  FILE *p_file = fopen(argv[1], "r");
  char buffer[1024] = {0};

  if(p_file == NULL) {
    if (argc == 1) {
      printf("Lae\tversion %s\nRun 'lae help' to see the usage guide\n", version);
      return 0;
    }
    else if (strncmp(argv[1], "help", 4) == 0) {
      print_usage_guide();
      return 0;
    }

    printf("Could not open file\n");
    return 1;
  }

    while (fgets(buffer, sizeof(buffer), p_file) != NULL) {
	printf("%s", buffer);
    }
    fclose(p_file);
    return 0;
}
