#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINE_MAX_LENGTH 1024
#define LIMIT_RED 12
#define LIMIT_GREEN 13
#define LIMIT_BLUE 14

void processFile(const char *filename);
void analyzeLine(char *line, int *red, int *green, int *blue);
int extractColorValue(char *line, int index);

int main() {
    processFile("text2.txt");
    return 0;
}

void processFile(const char *filename) {
    FILE *fp;
    char line[LINE_MAX_LENGTH];
    int suma = 0;
    int mocsuma = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int lineId = 0;
    int red, green, blue;
    while (fgets(line, sizeof(line), fp) != NULL) {
        lineId++;
        red = green = blue = 0;
        analyzeLine(line, &red, &green, &blue);

        if (red <= LIMIT_RED && green <= LIMIT_GREEN && blue <= LIMIT_BLUE) {
            suma += lineId;
        }

        int moc = red * green * blue;
        mocsuma += moc;
    }

    fclose(fp);

    printf("\nsuma: %d\n", suma);
    printf("\nmoc: %d\n", mocsuma);
}

void analyzeLine(char *line, int *red, int *green, int *blue) {
    char *colors[] = {"red", "green", "blue"};
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        char *found = line;
        while ((found = strstr(found, colors[i])) != NULL) {
            int index = found - line;
            int value = extractColorValue(line, index);
            switch (i) {
                case 0:
                    if (value > *red) *red = value;
                    break;
                case 1:
                    if (value > *green) *green = value;
                    break;
                case 2:
                    if (value > *blue) *blue = value;
                    break;
            }
            found++;
        }
    }
}

int extractColorValue(char *line, int index) {
    int value;
    if (isdigit(line[index - 3])) {
        char numberStr[4] = {line[index - 3], line[index - 2], '\0'};
        value = atoi(numberStr);
    } else {
        char numberStr[3] = {line[index - 2], '\0'};
        value = atoi(numberStr);
    }
    return value;
}