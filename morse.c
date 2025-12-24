#include <stdio.h>
#include <string.h>

struct Morse {
    char letter;
    char code[8];
};

struct Morse table[26] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}
};

/* English → Morse */
void engToMorse(char str[]) {

    strupr(str);   // make whole string uppercase

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == ' ') {   // space → word break
            printf("/ ");
            continue;
        }

        for (int j = 0; j < 26; j++) {
            if (table[j].letter == str[i]) {
                printf("%s ", table[j].code);
                break;
            }
        }
    }

    printf("\n");
}

/* Morse → English */
void morseToEng(char str[]) {

    char temp[10];
    int ti = 0;

    strcat(str, " ");   // add space so last Morse token works

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] != ' ') {
            temp[ti++] = str[i];
        }
        else {
            temp[ti] = '\0';

            if (strcmp(temp, "/") == 0) {
                printf(" ");   // new word
            } else {
                for (int j = 0; j < 26; j++) {
                    if (strcmp(temp, table[j].code) == 0) {
                        printf("%c", table[j].letter);
                        break;
                    }
                }
            }

            ti = 0;
        }
    }

    printf("\n");
}

int main() {

    int choice;
    char str[200];

    printf("Enter 1 for Morse to English, 2 for English to Morse:\n");
    scanf("%d", &choice);

    getchar(); // clear newline

    if (choice == 2) {
        printf("Enter English text:\n");
        gets(str);
        engToMorse(str);
    }
    else if (choice == 1) {
        printf("Enter Morse code:\n");
        gets(str);
        morseToEng(str);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
