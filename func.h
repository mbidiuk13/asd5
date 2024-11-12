#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>

// Структура черги
struct Queu {
    int data;
    struct Queu* pnext;
};

// Структури для черги
struct Queu* head;      // покажчик на початок черги
struct Queu* new_element;      // покажчик на новий елемент черги
struct Queu* current;          // покажчик на поточний елемент черги
struct Queu* del_element;     // покажчик на елемент, що видаляється

// Функція додавання елементів у чергу
void enqueue(int* mas, int N) {
    for (int i = 0; i < N; i++) {
        new_element = (struct Queu*)malloc(sizeof(struct Queu));  // Виділення пам'яті під новий елемент
        new_element->data = mas[i];                                 // Запис даних у новий елемент
        new_element->pnext = NULL;                                   // Наступний елемент поки відсутній

        if (head == NULL) {                                          // Якщо черга порожня
            head = new_element;                                       // Встановлюємо новий елемент як головний
        } else {
            current = head;                                           // Інакше переходимо в кінець черги
            while (current->pnext != NULL) {
                current = current->pnext;
            }
            current->pnext = new_element;                            // Додаємо новий елемент в кінець
        }
    }
}

// Функція для видалення всіх парних елементів з черги
void dequeueEven() {
    while (head != NULL && head->data % 2 == 0) {  // Видаляємо парні елементи з початку черги
        del_element = head;
        head = head->pnext;
        free(del_element);
    }

    current = head;

    while (current != NULL && current->pnext != NULL) {
        if (current->pnext->data % 2 == 0) {  // Якщо наступний елемент парний
            del_element = current->pnext;
            current->pnext = del_element->pnext;  // Пропускаємо поточний парний елемент
            free(del_element);
        } else {
            current = current->pnext;  // Переходимо до наступного елемента
        }
    }
}


// Функція виведення елементів черги
void printQueue() {
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->pnext;
    }
    printf("\n");
}

// Функція для обчислення середнього арифметичного значення елементів черги
float calculateAverage() {
    if (head == NULL) {
        return 0.0;  // Якщо черга порожня, повертаємо 0
    }
    int sum = 0;
    int count = 0;
    current = head;
    while (current != NULL) {
        sum += current->data;   // Додаємо значення елемента до суми
        count++;                 // Збільшуємо лічильник елементів
        current = current->pnext;
    }

    return (float)sum / (float)count;  // Повертаємо середнє арифметичне
}

#endif
