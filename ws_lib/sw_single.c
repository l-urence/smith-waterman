//
//  sw_single.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "sw_single.h"

int match(char ai, char bj) {
    if (ai == bj) {
        return MATCH;
    } else {
        return MISS_MATCH;
    }
}

void sw(char *s1, char *s2, int **matrix) {
    int m = ((int) strlen(s1));
    int n = ((int) strlen(s2));
    position** memory = (position**)malloc(n * sizeof(position**));
    
    for (int i=1; i<=n; i++) {
        char b = s2[i-1];
        position pos;
        memory[i] = (position *) malloc(m * sizeof(position));
        
        for (int j=1; j<=m; j++) {
            char a = s1[j-1];
            int max = 0;
            
            int mm = matrix[i-1][j-1] + match(a, b);
            if (mm > max) {
                max = mm;
                pos = (position) {i - 1, j - 1};
            }
            
            int md = matrix[i-1][j] + GAP;
            if (md > max) {
                max = md;
                pos = (position) {i - 1, j};
            }
            
            int mi = matrix[i][j-1] + GAP;
            if (mi > max) {
                max = mi;
                pos = (position) {i, j - 1};
            }
            
            if (max == 0) {
                pos = (position) {i, j};
            }
            
            memory[i][j] = pos;
            matrix[i][j] = max;
        }
    }
    
    // Traceback
    char stringA[m + n +2], stringB[m + n +2];
    
    position *currentPos = maximumValue(matrix, m, n);
    position nextPos = memory[currentPos->i][currentPos->j];
    int index = 0;
    
    while ((currentPos->i != nextPos.i || currentPos->j != nextPos.j) && nextPos.i >= 0 && nextPos.j >= 0) {
        if (nextPos.i == currentPos->i) {
            stringA[index] = '-';
        } else {
            stringA[index] = s2[currentPos->i - 1];
        }
        
        if (nextPos.j == currentPos->j) {
            stringB[index] = '-';
        } else {
            stringB[index] = s1[currentPos->j  - 1];
        }
        
        *currentPos = nextPos;
        
        if (currentPos->i > 0 && currentPos > 0)
            nextPos = memory[currentPos->i][currentPos->j];
        
        index++;
    }
    
    printf("\n");
    
    for (int i=index-1; i>=0; i--) {
        printf("%c", stringB[i]);
    }
    
    printf("\n");
    
    for (int i=index-1; i>=0; i--) {
        printf("%c", stringA[i]);
    }
    
    printf("\n");
    
    free(currentPos);
    freeMemory(memory, n);
}