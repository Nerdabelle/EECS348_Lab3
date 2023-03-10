/*
 * Program2.c
 *
 *  Created on: Feb 12, 2023
 *      Author: a473s013
 */
#include <stdio.h>

// Returns the number of combinations of scoring plays that can result in a given score.
int possible_plays(int score) {
    int count = 0;
    for (int td = 0; td * 6 <= score; td++) {
        for (int fg = 0; fg * 3 <= score - td * 6; fg++) {
            for (int sf = 0; sf * 2 <= score - td * 6 - fg * 3; sf++) {
                for (int tdc = 0; tdc * 8 <= score - td * 6 - fg * 3 - sf * 2; tdc++) {
                    for (int tdfg = 0; tdfg * 7 <= score - td * 6 - fg * 3 - sf * 2 - tdc * 8; tdfg++) {
                        if (td * 6 + fg * 3 + sf * 2 + tdc * 8 + tdfg * 7 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", tdc, tdfg, td, fg, sf);
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP: ");
        int val;
        scanf("%d", &val);
        if (val == 0){
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) break;
        printf("possible combinations of scoring plays:\n");
        int count = possible_plays(score);
        printf("Total combinations: %d\n", count);
        }
        else if (val == 1){
        printf("exiting...");
        return 0;

        }
        else {
        printf("invalid input\n");
    }

    }


    return 0;
}


