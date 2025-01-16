#include <stdio.h>

void draw_flag(int size) {
    if (size < 5) {
        printf("The size must be greater than or equal to 5.\n");
        return;
    }

    // Top border
    for (int i = 0; i < size + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Flag content
    for (int i = 0; i < size; i++) {
        printf("#"); // Left border
        for (int j = 0; j < size; j++) {
            if (i == j || i + j == size - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n"); // Right border
    }

    // Bottom border
    for (int i = 0; i < size + 2; i++) {
        printf("#");
    }
    printf("\n");
}

void draw_spiral(int size) {
    int spiral[size][size];

    // Initialize the grid with spaces
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            spiral[i][j] = ' ';
        }
    }

    // Create the spiral
    int value = '*';
    int top = 0, bottom = size - 1, left = 0, right = size - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            spiral[top][i] = value;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            spiral[i][right] = value;
        }
        right--;

        for (int i = right; i >= left; i--) {
            spiral[bottom][i] = value;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            spiral[i][left] = value;
        }
        left++;
    }

    // Print the spiral
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", spiral[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;

    while (1) { // Бесконечный цикл, пока не введено корректное значение
        printf("Enter the size of the flag (an odd number >= 5): ");
        scanf("%d", &size);

        if (size % 2 == 0) {
            printf("Please enter an odd number for the flag to display correctly.\n");
        }
        else if (size < 5) {
            printf("The size must be greater than or equal to 5.\n");
        }
        else {
            break; // Выход из цикла при корректном значении
        }
    }

    printf("\nFlag:\n");
    draw_flag(size);

    printf("\nSpiral:\n");
    draw_spiral(size);

    return 0;
}
