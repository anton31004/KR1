#include <iostream>
#include <string>
//*task1*//
// Функция для заполнения массива случайными числами от 1 до 50
void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50 + 1;
    }
}
// Функция для вывода массива на экран
void printarray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
// Функция для поиска и вывода пар элементов сумма которых равна заданному числу
void findpairs(int* arr, int size, int Sum) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == Sum) {
                std::cout << "Пара найдена: " << arr[i] << " + " << arr[j] << " = " << Sum << std::endl;
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    int size;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> size;

    int* array = new int[size]; // Выделение памяти под динамический массив

    fillArray(array, size); // Заполнение массива случайными числами
    std::cout << "Массив: ";
    printarray(array, size); // Вывод массива на экран

    int Sum;
    std::cout << "Введите сумму, которую вы хотете найти: ";
    std::cin >> Sum;

    findpairs(array, size, Sum); // Поиск и вывод пар элементов сумма которых равна заданному числу

    delete[] array; // Освобождение памяти, выделенной под массив

    return 0;
}

//*task2*//
// Структура для хранения информации о контакте
struct Contact {
    std::string name;
    std::string phoneNumber;
};

// Объявление типа указателя на функцию
typedef void (*ContactFunction)(Contact contacts[], int& contactCount);

// Функция для добавления нового контакта
void add(Contact contacts[], int& contactCount) {
    if (contactCount < 100) {
        std::cout << "Введите имя нового контакта: ";
        std::cin >> contacts[contactCount].name;
        std::cout << "Введите номер телефона нового контакта: ";
        std::cin >> contacts[contactCount].phoneNumber;
      

        contactCount++;
        std::cout << "Контакт успешно добавлен." << std::endl;
    }
    else {
        std::cout << "Превышено максимальное количество контактов." << std::endl;
    }
}

// Функция для удаления существующего контакта
void deletecontact(Contact contacts[], int& contactCount) {
    std::string contactName;
    std::cout << "Введите имя контакта для удаления: ";
    std::cin >> contactName;

    int Index = -1;
    for (int i = 0; i < contactCount; ++i) {
        if (contacts[i].name == contactName) {
            Index = i;
            break;
        }
    }

    if (Index != -1) {
        for (int i = Index; i < contactCount - 1; ++i) {
            contacts[i] = contacts[i + 1];
        }
        contactCount--;
        std::cout << "Контакт успешно удален." << std::endl;
    }
    else {
        std::cout << "Контакт с таким именем не найден." << std::endl;
    }
}

// Функция для обновления информации о контакте
void update(Contact contacts[], int& contactCount) {
    std::string contactName;
    std::cout << "Введите имя контакта для обновления: ";
    std::cin >> contactName;

    int Index = -1;
    for (int i = 0; i < contactCount; ++i) {
        if (contacts[i].name == contactName) {
            Index = i;
            break;
        }
    }

    if (Index != -1) {
        std::cout << "Введите новый номер телефона: ";
        std::cin >> contacts[Index].phoneNumber;
        std::cout << "Информация о контакте успешно обновлена." << std::endl;
    }
    else {
        std::cout << "Контакт с таким именем не найден." << std::endl;
    }
}

// Функция для вывода информации обо всех контактах
void print(Contact contacts[], int& contactCount) {
    std::cout << "Телефонный справочник:" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "Имя: " << contacts[i].name << ", Номер телефона: " << contacts[i].phoneNumber << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Contact contacts[100]; //Массив
    int contactCount = 0;
    ContactFunction contactFunctions[] = { add, deletecontact, update, print };
    int choice;
    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить новый контакт" << std::endl;
        std::cout << "2. Удалить существующий контакт" << std::endl;
        std::cout << "3. Обновить информацию о контакте" << std::endl;
        std::cout << "4. Вывести информацию обо всех контактах" << std::endl;
        std::cout << "0. Выйти из программы" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            contactFunctions[choice - 1](contacts, contactCount);
        }
        else if (choice != 0) {
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);

    return 0;
}