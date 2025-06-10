#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char filename[100];
    char line[1000];
    double sum = 0.0;

    printf("Input filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    
    while (fgets(line, sizeof(line), file) != NULL) {
        char *ptr = line;
        while (*ptr) {

            if (isdigit(*ptr) || *ptr == '.') {
                char numStr[100];
                int i = 0;

                
                while (isdigit(*ptr) || *ptr == '.') {
                    numStr[i++] = *ptr;
                    ptr++;
                }
                numStr[i] = '\0';

                
                sum += atof(numStr);
            } else {
                ptr++;
            }
        }
    }

    fclose(file);

    printf("The sum is %.2f\n", sum);
    return 0;
}
