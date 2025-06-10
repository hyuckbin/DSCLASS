#include <stdio.h>
#include <ctype.h>  
//포인터로도 한 번 바꿔보자

void swapCase(char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (islower(line[i])) {
            line[i] = toupper(line[i]);
        } else if (isupper(line[i])) {
            line[i] = tolower(line[i]);
        }
    }
}

int main() {
    char line[1000];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    swapCase(line); 

    printf("=> %s", line);

    return 0;
}
