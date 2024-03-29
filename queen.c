#include <stdio.h>
#define N 8
int board[N][N];
int is_valid(int row, int col) {
int i, j;

for (i = 0; i < N; i++) {
if (board[row][i] || board[i][col]) {
return 0;
}    }
for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
if (board[i][j]) {
return 0;
}    }
for (i = row, j = col; i >= 0 && j < N; i--, j++) {
if (board[i][j]) {
return 0;
}
}    return 1;}
int solve(int row) {
int col;

if (row == N) {
return 1;
}
for (col = 0; col < N; col++) {
if (is_valid(row, col)) {
board[row][col] = 1;

if (solve(row + 1)) {
return 1;
}
board[row][col] = 0;
}    }
return 0;}
void print_board() {
int i, j;

for (i = 0; i < N; i++) {
for (j = 0; j < N; j++) {
printf("%c ", board[i][j] ? 'Q' : '.');
}
printf("\n");
}
}
int main() {
if (solve(0)) {
print_board();
} else {
printf("No solution found.\n");
}
return 0;
}
 
