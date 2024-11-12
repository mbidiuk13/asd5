#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// Прототипи функцій
void enqueue(int* mas, int N);
void dequeueEven();  // Функція для видалення всіх парних елементів
void printQueue();
float calculateAverage();  // Прототип функції для обчислення середнього арифметичного

// Основна функція
int main() {
    int N;

    // Ініціалізація елементів черги
    printf("Enter the number of elements in the queue (N): ");
    scanf("%d", &N);
    int* mas = malloc(N * sizeof(int));
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &mas[i]);
    }

    // Додавання елементів у чергу
    enqueue(mas, N);

    // Виведення черги після додавання елементів
    printf("Queue after adding elements (Q1): ");
    printQueue();

    // Обчислення середнього арифметичного
    float A1 = calculateAverage();
    printf("Average of all elements in the queue (A1): %.2f\n", A1);

    // Видалення всіх парних елементів
    dequeueEven();

    // Виведення черги після видалення парних елементів
    printf("Queue after deleting even elements (Q2): ");
    printQueue();

    // Обчислення нового середнього арифметичного
    float A2 = calculateAverage();
    printf("Average of all elements in the queue after deletion (A2): %.2f\n", A2);

    // Звільнення пам'яті
    free(mas);

    return 0;
}
