// in2bin, input to binary, translate input text to binary code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_usage(void) {
    puts("    -n --noloop: After first input, don't loop");
    puts("    -h --help: Show this help");
}

void translate(const char *input) {
    while (*input) {
	char c = *input;
	for (int i = 7; i >= 0; i--) {
	    int bit = (c >> i) & 1;
	    printf("%d", bit);
	}
	printf(" ");
	input++;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
	while (1) {
	    char *str = malloc(500 * sizeof(char));
	    if (str == NULL) {
	        perror("fatal"); // the allocation failed
	    }

	    if (fgets(str, 500, stdin) != NULL) {
	        translate(str);
	    }

	    // clean up
	    if (str[strlen(str) - 1] != '\n') {
		int j;
		while ((j = getchar()) != '\n' && j != EOF);
	    }

	    free(str); // clean up
        }
    }

    if (strcmp(argv[1], "--noloop") == 0 || strcmp(argv[1], "-n") == 0) {
	char *str = malloc(500 * sizeof(char));
        if (str == NULL) {
            perror("fatal"); // the allocation failed
        }

        if (fgets(str, 500, stdin) != NULL) {
            translate(str);
        }

        // clean up
        if (str[strlen(str) - 1] != '\n') {
            int j;
            while ((j = getchar()) != '\n' && j != EOF);
        }

        free(str); // clean up
    } else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
	printf("usage: %s: [options]\n", argv[0]);
	show_usage();
	return 0;
    } else {
	printf("usage: %s: [options]\n", argv[0]);
        show_usage();
        return 1;
    }

    return 0;
}
