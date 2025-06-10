#include <stdio.h>
#include <stdlib.h>

void find_min_in_file(const char* filename){
    FILE *file;
    int number;
    int min;
    int first = 1;

    printf("Input filename: %s\n", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n\n");
        return;
    }

    while (fscanf(file, "%d", &number) == 1) {
        if (first) {
            min = number;
            first = 0;
        } else if (number < min) {
            min = number;
        }
    }

    if (!first) {
        printf("The smallest number is %d\n\n", min);
    } else {
        printf("No numbers found in the file.\n\n");
    }

    fclose(file);


}

int main() {
    const char* filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    int i;

    for (i = 0; i < 3; i++) {
        find_min_in_file(filenames[i]);
    }

    return 0;
}
