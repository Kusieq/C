#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int findFirstAndLastWord(const char *line, char *first, char *last) {
    int firstWord = 999;
    int lastWord = -1;

    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
        const char *found = strstr(line, num[i]);
        if (found != NULL) {
            int index = found - line;
            if (index < firstWord) {
                firstWord = index;
                *first = '0' + i;
            }
            if (index > lastWord) {
                lastWord = index;
                *last = '0' + i;
            }
        }
    }

    return firstWord;
}

void findFirstAndLastDigit(const char *line, int firstWord, char *first, char *last) {
    for (int i = 0; i < strlen(line); i++) {
        if (isdigit(line[i])) {
            if (*first == '\0' || i < firstWord) {
                *first = line[i];
                firstWord = i;
            }
            if (*last == '\0' || i > firstWord) {
                *last = line[i];
            }
        }
    }
}

int main() {
    FILE *fp;
    char line[1024];
    fp = fopen("text1.txt", "r");
    int sum = 0;

    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    } else {
        while (fgets(line, sizeof(line), fp) != NULL) {
            char first = '\0';
            char last = '\0';

            int firstWord = findFirstAndLastWord(line, &first, &last);
            findFirstAndLastDigit(line, firstWord, &first, &last);

            if (first != '\0' && last != '\0') {
                char numberStr[3] = {first, last, '\0'};
                int number = atoi(numberStr);
                sum += number;
            }
        }

        fclose(fp);
    }

    printf("Sum: %d\n", sum);
    return 0;
}