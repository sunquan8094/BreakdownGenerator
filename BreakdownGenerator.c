#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "card.h"

struct card* deck[38];

char name[38][5] = {
    "AS", "2S", "3S", "4S", "5S", "6S", "JS", "QS", "KS",
    "AH", "2H", "3H", "4H", "5H", "6H", "JH", "QH", "KH",
    "AC", "2C", "3C", "4C", "5C", "6C", "JC", "QC", "KC",
    "AD", "2D", "3D", "4D", "5D", "6D", "JD", "QD", "KD",
    "JkrR", "JkrB"
};

char meaning[38][32] = {
    "(chug * 1)", "(chug * 2)", "(chug * 3)", "(chug * 4)", "(chug * 5)", "(chug * 6)", "(Break)", "(dissonant chord)", "(pinch)",
    "(chug * 1)", "(chug * 2)", "(chug * 3)", "(chug * 4)", "(chug * 5)", "(chug * 6)", "(Break)", "(dissonant chord)", "(pinch)",
    "(chug * 1)", "(chug * 2)", "(chug * 3)", "(chug * 4)", "(chug * 5)", "(chug * 6)", "(Break)", "(dissonant chord)", "(pinch)",
    "(chug * 1)", "(chug * 2)", "(chug * 3)", "(chug * 4)", "(chug * 5)", "(chug * 6)", "(Break)", "(dissonant chord)", "(pinch)",
    "(bendy note)", "(bendy note)"
};

int hand[38];

int count = 0;

void init() {
    for (int h = 0; h < 38; h++) {
        deck[h] = (struct card *) malloc (sizeof(struct card));
        strcpy(deck[h]->name, name[h]);
        strcpy(deck[h]->meaning, meaning[h]);
    }
}

void deal(int n) {
    for (int l = 0; l < n; l++) {
        int merr = -1;
        while (isInHand(merr) == 1 || merr == -1) {
            merr = rand() % 38;
        }
        hand[l] = merr;
        count++;
    }
}

int isInHand(int n) {
    int retval = 0;
    for (int o = 0; o < count; o++) {
        if (hand[o] == n) {
            retval = 1;
        }
    }
    return retval;
}

void close() {
    for (int h = 0; h < 38; h++) {
        free(deck[h]);
    }
}

int main() {
    srand(time(NULL));
    init();
    int num = 0;
    int merr;
    char ch;
    printf("Input a number.\n");
    while (num <= 0 || num > 38) {
        merr = scanf("%d", &num);
        if (merr != 0 || num <= 0 || num > 38) {
            printf("Invalid input.\n");
        }
        while ((ch = getchar()) != '\n');
    }
    deal(num);
    for (int m = 0; m < count; m++) {
        printf("%s ", deck[hand[m]]->name);
    }
    printf("\n");
    for (int k = 0; k < count; k++) {
        printf("%s ", deck[hand[k]]->meaning);
    }
    printf("\n");
    close();
    return 0;
}