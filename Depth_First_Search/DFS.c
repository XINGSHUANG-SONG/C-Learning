#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
};

void print_maze(void)
{
        int i, j;
        for (i = 0; i < MAX_ROW; i++) {
                for (j = 0; j < MAX_COL; j++)
                        printf("%d ", maze[i][j]);
                putchar('\n');
        }
        printf("*********\n");
}

int search_path(int row, int col){
    maze[row][col] = 2;
    if (row == MAX_ROW - 1  /* goal */
        && col == MAX_COL - 1) {
            printf("(%d, %d)\n", row, col);
            return 1;
    }
    if (row-1 >= 0          /* up */
        && maze[row-1][col] == 0) {
            if (search_path(row-1, col)) {
                printf("(%d, %d)\n", row, col);
                return 1;
            }
        }
    if (col-1 >= 0          /* left */
        && maze[row][col-1] == 0) {
            if (search_path(row, col-1)) {
                printf("(%d, %d)\n", row, col);
                return 1;
            }
        }
    if (row+1 < MAX_ROW     /* down */
        && maze[row+1][col] == 0) {
            if (search_path(row+1, col)) {
                printf("(%d, %d)\n", row, col);
                return 1;
            }
        }
    if (col+1 < MAX_COL     /* right */
        && maze[row][col+1] == 0) {
            if (search_path(row, col+1)) {
                printf("(%d, %d)\n", row, col);
                return 1;
            }
        }
    return 0;
}

int main(void)
{
        int row = 0, col = 0;
        if (!search_path(row, col))
            printf("No path.\n");
        return 0;
}