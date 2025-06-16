// PS04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct list
{
    int field;
    list* prev, * next;
};

void add_to_start(list*&, int); // Добавление элемента в начало списка
void add_to_middle(list*&, int, int); // Добавление элемента в середину списка
void add_to_end(list*&, int); // Добавление элемента в конец списка
void remove_from_start(list*&); // Удаление элемента из начала списка
void remove_from_middle(list*&, int); // Удаление элемента из середины списка
void remove_from_end(list*&); // Удаление элемента из конца списка
void print_from_start(list*); // Печать списка от начала к концу
void print_from_end(list*); // Печать списка с конца к началу


int main()
{
    setlocale(LC_ALL, "Ru");

    // Инициализайия списка
    list* head = nullptr;
    int choice, value, position;

    // Меню
    do {
        cout << "\nМеню: \n";
        cout << "1. Добавить в начало списка\n";
        cout << "2. Добавить в середину списка\n";
        cout << "3. Добавить в конец списка\n";
        cout << "4. Удалить из начало списка\n";
        cout << "5. Удалить из середину списка\n";
        cout << "6. Удалить из конец списка\n";
        cout << "7. Печать от начало в конец\n";
        cout << "8. Печать с конца к началу\n";
        cout << "9. Выйти\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            add_to_start(head, value); // Добавление элемента в начало
            break;
        case 2:
            cout << "Введите значение и позицию: ";
            cin >> value >> position;
            add_to_middle(head, value, position); // Добавление элемента в середину
            break;
        case 3:
            cout << "Введите значение: ";
            cin >> value;
            add_to_end(head, value); // Добавление элемента в конец
            break;
        case 4:
            remove_from_start(head); // Удаление элемента из начала
            break;
        case 5:
            cout << "Введите позицию: ";
            cin >> position;
            remove_from_middle(head, position); // Удаление элемента из середины
            break;
        case 6:
            remove_from_end(head); // Удаление элемента из конца
            break;
        case 7:
            print_from_start(head); // Печать списка от начала к концу
            break;
        case 8:
            print_from_end(head); // Печать списка с конца к началу
            break;
        case 9:
            cout << "Выход из программы.\n";
        default:
            cout << "Неверный выбор.\n"; // Обработка неверного выбора
        }
    } while (choice != 9);
 
}

// Добавление элемента в начало списка
void add_to_start(list*& head, int value) {
    list* curr = new list();
    curr->field = value; // Установка значения нового узла
    curr->prev = nullptr;
    curr->next = head; // Указатель на текущую голову списка
    if (head) head->prev = curr; // Если список не пуст, обновляем указатель на предыдущий узел
    head = curr; // Устанавливаем новый узел как голову списка
}

// Добавление элемента в середину списка
void add_to_middle(list*& head, int value, int position) {
    if (!head || position <= 0) { // Если список пуст или позиция некорректна
        add_to_start(head, value); // Добавляем элемент в начало
        return;
    }

    list* curr = head; // Используем curr для навигации
    for (int i = 0; curr->next && i < position - 1; i++) { // Поиск нужной позиции
        curr = curr->next;
    }

    // Создание нового узла с помощью curr
    curr = new list(); // Переприсваиваем curr как новый узел
    curr->field = value;

    // Связываем новый узел с предыдущими и следующими элементами
    curr->next = head->next;
    curr->prev = head;
    if (head->next) head->next->prev = curr;
    head->next = curr; // Вставляем новый узел в список
}
//void add_to_middle(list*& head, int value, int position) {
//    if (!head || position <= 0) { // Если список пуст или позиция некорректна
//        add_to_start(head, value); // Добавляем элемент в начало
//        return;
//    }
//    list* curr = head;
//    for (int i = 0; curr->next && i < position - 1; i++) { // Поиск нужной позиции
//        curr = curr->next;
//    }
//    list* last = new list();
//    last->field = value;
//    last->next = curr->next; // Связь нового узла со следующим узлом
//    last->prev = curr; // Связь нового узла с предыдущим узлом
//    if (curr->next) curr->next->prev = last;
//    curr->next = last; // Вставка нового узла в список
//}


// Добавление элемента в конец списка
void add_to_end(list*& head, int value) {
    if (!head) {
        add_to_start(head, value); // Если список пуст, добавляем в начало
        return;
    }

    list* curr = head; // Используем curr для навигации
    while (curr->next) { // Находим последний узел
        curr = curr->next;
    }

    // Создаём новый узел с помощью curr
    curr = new list(); // Переприсваиваем curr как новый узел
    curr->field = value;

    // Связываем новый узел с предыдущим
    curr->next = nullptr;
    curr->prev = head;
    head->next = curr; // Указываем на новый последний элемент списка
}
//void add_to_end(list*& head, int value) {
//    if (!head) {
//        add_to_start(head, value); // Если список пуст, добавляем в начало
//        return;
//    }
//    list* curr = head;
//    while (curr->next) { // Поиск последнего элемента списка
//        curr = curr->next;
//    }
//    list* last = new list();
//    last->field = value;
//    last->prev = curr; // Связь нового узла с предыдущим узлом
//    last->next = nullptr;
//    curr->next = last; // Указатель на новый последний узел списка
//}

// Удаление элемента из начала списка
void remove_from_start(list*& head) {
    if (!head) return; // Если список пуст, ничего не делаем
    list* curr = head; // Сохраняем указатель на текущую голову
    head = head->next; // Обновляем голову списка
    if (head) head->prev = nullptr; // Если список не пуст, обнуляем указатель на предыдущий узел
    delete curr; // Удаляем старую голову
}

// Удаление элемента из середины списка
void remove_from_middle(list*& head, int position) {
    if (!head || position <= 0) { // Если список пуст или позиция некорректна
        remove_from_start(head); // Удаляем элемент из начала
        return;
    }
    list* curr = head;
    for (int i = 0; curr && i < position; i++) { // Поиск нужной позиции
        curr = curr->next;
    }
    if (!curr) return; // Если узел не найден, ничего не делаем
    if (curr->prev) curr->prev->next = curr->next; // Обновляем связь предыдущего узла
    if (curr->next) curr->next->prev = curr->prev; // Обновляем связь следующего узла
    delete curr; // Удаляем текущий узел
}

// Удаление элемента из конца списка
void remove_from_end(list*& head) {
    if (!head) return; // Если список пуст, ничего не делаем
    list* curr = head;
    while (curr->next) { // Поиск последнего узла
        curr = curr->next;
    }
    if (curr->prev) curr->prev->next = nullptr; // Обновляем связь предыдущего узла
    else head = nullptr; // Если список состоит из одного узла, делаем его пустым
    delete curr; // Удаляем последний узел
}
// Печать списка от начала к концу
void print_from_start(list* head) {
    list* curr = head;
    while (curr) { // Проходим по списку
        cout << curr->field << " "; // Печатаем значение узла
        curr = curr->next;
    }
    cout << endl;
}

// Печать списка с конца к началу
void print_from_end(list* head) {
    if (!head) return; // Если список пуст, ничего не делаем
    list* curr = head;
    while (curr->next) { // Проходим к последнему узлу
        curr = curr->next;
    }
    while (curr) { // Проходим обратно по списку
        cout << curr->field << " "; // Печатаем значение узла
        curr = curr->prev;
    }
    cout << endl;
}























//// создание спика
    //list* head = nullptr;
    //list* curr = new list();
    //curr->field = 1;
    //curr->prev = nullptr;
    //curr->next = nullptr;
    //head = curr;

    //// добавление в начало
    //curr = new list();
    //curr->field = 2;
    //
    //curr->prev = nullptr;
    //curr->next = head;
    //head->prev = curr;
    //head = curr;
    //
    //// Печать от начало в конец
    //curr = head;
    //while (curr != nullptr) {
    //    cout << curr->field << " ";
    //    curr = curr->next;
    //}
    //cout << endl;
    ////Печать с конца к началу
    //curr = head;
    //while (curr->next != nullptr) {
    //    curr = curr->next;
    //}
    //while (curr != nullptr) {
    //    cout << curr->field << " ";
    //    curr = curr->prev;
    //}
    // curr
    // head
    // last

