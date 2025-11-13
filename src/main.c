#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
// #include <regex.h>

void print_usage_guide() {
    printf("Usage:\t[file] [options] or\n\t[command] [options]\n");
    printf("Commands:\n");
    printf("\thelp\tshows this guide\n");
}

int main(int argc, char *argv[]) {
    char version[] = "0.0.1-dev";
    FILE *p_lae = fopen(argv[1], "r");
    char buffer[1024] = {0};

    if(p_lae == NULL) {
	if (argc == 1) {
	    printf("Lae\tversion %s\nRun 'lae help' to see the usage guide\n", version);
	    return 0;
	} else if (strncmp(argv[1], "help", 4) == 0) {
	    print_usage_guide();
	    return 0;
	}
	// else:
	printf("Could not open file\n");
	return 1;
    }

    while (fgets(buffer, sizeof(buffer), p_lae) != NULL) {
	printf("%s", buffer);
    }
    fclose(p_lae);
    return 0;
}
