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

int main() {
    int size;

    while (1) { // Бесконечный цикл, пока не введено корректное значение
        printf("Enter the size of the flag (an odd number >= 5): ");
        scanf_s("%d", &size);

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

    draw_flag(size);
    return 0;
}
