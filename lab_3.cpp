#include "lab_3.h"
#include "inputCheck.h"
#include "generate.h"
#include <algorithm>

using namespace mylib;
using namespace generate;

// ============ LibraryWorker Implementation ============

LibraryWorker::LibraryWorker() : id(0), firstname(""), lastname(""), age(0), isActive(true) {
}

LibraryWorker::LibraryWorker(int id, string firstname, string lastname, int age)
    : id(id), firstname(firstname), lastname(lastname), age(age), isActive(true) {
}

// Геттеры
int LibraryWorker::getId() const { return id; }
string LibraryWorker::getFirstName() const { return firstname; }
string LibraryWorker::getLastName() const { return lastname; }
int LibraryWorker::getAge() const { return age; }
bool LibraryWorker::getIsActive() const { return isActive; }

// Сеттеры
void LibraryWorker::setId(int id) { this->id = id; }
void LibraryWorker::setFirstName(string firstname) { this->firstname = firstname; }
void LibraryWorker::setLastName(string lastname) { this->lastname = lastname; }
void LibraryWorker::setAge(int age) { this->age = age; }
void LibraryWorker::setIsActive(bool active) { this->isActive = active; }

void LibraryWorker::printInfo() const {
    if (!isActive) return;

    cout << "ID: " << id << " | Имя: " << firstname << " " << lastname
         << " | Возраст: " << age << " лет" << endl << endl;
}

// ============ LibraryManager Implementation ============

LibraryManager::LibraryManager() : nextId(1), arrayCount(0) {
    initializeArray();
}

void LibraryManager::initializeArray() {
    for (auto& worker : workersArray) {
        worker.setIsActive(false);
    }
}

int LibraryManager::getNextId() {
    return nextId++;
}

// === VECTOR OPERATIONS ===

void LibraryManager::addToVector() {
    cout << "Имя: ";
    string firstname = checkTryToInputString(true);
    cout << "Фамилия: ";
    string lastname = checkTryToInputString(true);
    cout << "Возраст: ";
    int age = checkTryToInputInt();

    LibraryWorker worker(getNextId(), firstname, lastname, age);
    workersVector.push_back(worker);
    cout << "Работник добавлен в vector! ID: " << worker.getId() << endl;
}

void LibraryManager::removeFromVector() {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }

    cout << "ID для удаления: ";
    int id = checkTryToInputInt();

    auto it = remove_if(workersVector.begin(), workersVector.end(),
        [id](const LibraryWorker& w) { return w.getId() == id; });

    if (it != workersVector.end()) {
        workersVector.erase(it, workersVector.end());
        cout << "Работник с ID " << id << " удален из vector!" << endl;
    } else {
        cout << "Работник с ID " << id << " не найден в vector!" << endl;
    }
}

void LibraryManager::editInVector() {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }

    cout << "ID для редактирования: ";
    int id = checkTryToInputInt();

    for (auto& worker : workersVector) {
        if (worker.getId() == id) {
            cout << "Новое имя: ";
            string firstname = checkTryToInputString(true);
            cout << "Новая фамилия: ";
            string lastname = checkTryToInputString(true);
            cout << "Новый возраст: ";
            int age = checkTryToInputInt();

            worker.setFirstName(firstname);
            worker.setLastName(lastname);
            worker.setAge(age);
            cout << "Работник с ID " << id << " отредактирован в vector!" << endl;
            return;
        }
    }
    cout << "Работник с ID " << id << " не найден в vector!" << endl;
}

void LibraryManager::printVector() const {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }
    cout << "=== СОДЕРЖИМОЕ VECTOR ===" << endl;
    for (const auto& worker : workersVector) {
        worker.printInfo();
    }
}

void LibraryManager::searchInVectorByName() {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }

    cout << "Имя для поиска: ";
    string name = checkTryToInputString(true);

    bool found = false;
    for (const auto& worker : workersVector) {
        if (worker.getFirstName().find(name) != string::npos ||
            worker.getLastName().find(name) != string::npos) {
            worker.printInfo();
            found = true;
        }
    }
    if (!found) cout << "Работники с именем '" << name << "' не найдены!" << endl;
}

void LibraryManager::searchInVectorByAge() {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }

    cout << "Возраст для поиска: ";
    int age = checkTryToInputInt();

    bool found = false;
    for (const auto& worker : workersVector) {
        if (worker.getAge() == age) {
            worker.printInfo();
            found = true;
        }
    }
    if (!found) cout << "Работники с возрастом " << age << " не найдены!" << endl;
}

void LibraryManager::sortVectorByName() {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }

    sort(workersVector.begin(), workersVector.end(),
        [](const LibraryWorker& a, const LibraryWorker& b) {
            return a.getLastName() < b.getLastName();
        });
    cout << "Vector отсортирован по фамилии!" << endl;
}

void LibraryManager::sortVectorByAge() {
    if (workersVector.empty()) {
        cout << "Vector пуст!" << endl;
        return;
    }

    sort(workersVector.begin(), workersVector.end(),
        [](const LibraryWorker& a, const LibraryWorker& b) {
            return a.getAge() < b.getAge();
        });
    cout << "Vector отсортирован по возрасту!" << endl;
}

// === LIST OPERATIONS ===

void LibraryManager::addToList() {
    cout << "Имя: ";
    string firstname = checkTryToInputString(true);
    cout << "Фамилия: ";
    string lastname = checkTryToInputString(true);
    cout << "Возраст: ";
    int age = checkTryToInputInt();

    LibraryWorker worker(getNextId(), firstname, lastname, age);
    workersList.push_back(worker);
    cout << "Работник добавлен в list! ID: " << worker.getId() << endl;
}

void LibraryManager::removeFromList() {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }

    cout << "ID для удаления: ";
    int id = checkTryToInputInt();

    size_t initialSize = workersList.size();
    workersList.remove_if([id](const LibraryWorker& w) {
        return w.getId() == id;
    });

    if (workersList.size() < initialSize) {
        cout << "Работник с ID " << id << " удален из list!" << endl;
    } else {
        cout << "Работник с ID " << id << " не найден в list!" << endl;
    }
}

void LibraryManager::editInList() {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }

    cout << "ID для редактирования: ";
    int id = checkTryToInputInt();

    for (auto& worker : workersList) {
        if (worker.getId() == id) {
            cout << "Новое имя: ";
            string firstname = checkTryToInputString(true);
            cout << "Новая фамилия: ";
            string lastname = checkTryToInputString(true);
            cout << "Новый возраст: ";
            int age = checkTryToInputInt();

            worker.setFirstName(firstname);
            worker.setLastName(lastname);
            worker.setAge(age);
            cout << "Работник с ID " << id << " отредактирован в list!" << endl;
            return;
        }
    }
    cout << "Работник с ID " << id << " не найден в list!" << endl;
}

void LibraryManager::printList() const {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }
    cout << "=== СОДЕРЖИМОЕ LIST ===" << endl;
    for (const auto& worker : workersList) {
        worker.printInfo();
    }
}

void LibraryManager::searchInListByName() {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }

    cout << "Имя для поиска: ";
    string name = checkTryToInputString(true);

    bool found = false;
    for (const auto& worker : workersList) {
        if (worker.getFirstName().find(name) != string::npos ||
            worker.getLastName().find(name) != string::npos) {
            worker.printInfo();
            found = true;
        }
    }
    if (!found) cout << "Работники с именем '" << name << "' не найдены!" << endl;
}

void LibraryManager::searchInListByAge() {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }

    cout << "Возраст для поиска: ";
    int age = checkTryToInputInt();

    bool found = false;
    for (const auto& worker : workersList) {
        if (worker.getAge() == age) {
            worker.printInfo();
            found = true;
        }
    }
    if (!found) cout << "Работники с возрастом " << age << " не найдены!" << endl;
}

void LibraryManager::sortListByName() {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }

    workersList.sort([](const LibraryWorker& a, const LibraryWorker& b) {
        return a.getLastName() < b.getLastName();
    });
    cout << "List отсортирован по фамилии!" << endl;
}

void LibraryManager::sortListByAge() {
    if (workersList.empty()) {
        cout << "List пуст!" << endl;
        return;
    }

    workersList.sort([](const LibraryWorker& a, const LibraryWorker& b) {
        return a.getAge() < b.getAge();
    });
    cout << "List отсортирован по возрасту!" << endl;
}

// === ARRAY OPERATIONS ===

bool LibraryManager::addToArray() {
    if (arrayCount >= workersArray.size()) {
        cout << "Array полон! Нельзя добавить больше работников." << endl;
        return false;
    }

    cout << "Имя: ";
    string firstname = checkTryToInputString(true);
    cout << "Фамилия: ";
    string lastname = checkTryToInputString(true);
    cout << "Возраст: ";
    int age = checkTryToInputInt();

    for (auto& worker : workersArray) {
        if (!worker.getIsActive()) {
            worker = LibraryWorker(getNextId(), firstname, lastname, age);
            worker.setIsActive(true);
            arrayCount++;
            cout << "Работник добавлен в array! ID: " << worker.getId() << endl;
            return true;
        }
    }

    return false;
}

void LibraryManager::removeFromArray() {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }

    cout << "ID для удаления: ";
    int id = checkTryToInputInt();

    for (auto& worker : workersArray) {
        if (worker.getIsActive() && worker.getId() == id) {
            worker.setIsActive(false);
            arrayCount--;
            cout << "Работник с ID " << id << " удален из array!" << endl;
            return;
        }
    }
    cout << "Работник с ID " << id << " не найден в array!" << endl;
}

void LibraryManager::editInArray() {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }
    printArray();
    cout << "ID для редактирования: ";
    int id = checkTryToInputInt();

    for (auto& worker : workersArray) {
        if (worker.getIsActive() && worker.getId() == id) {
            cout << "Новое имя: ";
            string firstname = checkTryToInputString(true);
            cout << "Новая фамилия: ";
            string lastname = checkTryToInputString(true);
            cout << "Новый возраст: ";
            int age = checkTryToInputInt();

            worker.setFirstName(firstname);
            worker.setLastName(lastname);
            worker.setAge(age);
            cout << "Работник с ID " << id << " отредактирован в array!" << endl;
            return;
        }
    }
    cout << "Работник с ID " << id << " не найден в array!" << endl;
}

void LibraryManager::printArray() const {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }
    cout << "=== СОДЕРЖИМОЕ ARRAY ===" << endl;
    for (const auto& worker : workersArray) {
        if (worker.getIsActive()) {
            worker.printInfo();
        }
    }
}

void LibraryManager::searchInArrayByName() {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }

    cout << "Имя для поиска: ";
    string name = checkTryToInputString(true);

    bool found = false;
    for (const auto& worker : workersArray) {
        if (worker.getIsActive() &&
            (worker.getFirstName().find(name) != string::npos ||
             worker.getLastName().find(name) != string::npos)) {
            worker.printInfo();
            found = true;
        }
    }
    if (!found) cout << "Работники с именем '" << name << "' не найдены!" << endl;
}

void LibraryManager::searchInArrayByAge() {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }

    cout << "Возраст для поиска: ";
    int age = checkTryToInputInt();

    bool found = false;
    for (const auto& worker : workersArray) {
        if (worker.getIsActive() && worker.getAge() == age) {
            worker.printInfo();
            found = true;
        }
    }
    if (!found) cout << "Работники с возрастом " << age << " не найдены!" << endl;
}

void LibraryManager::sortArrayByName() {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }

    vector<LibraryWorker> temp;
    for (const auto& worker : workersArray) {
        if (worker.getIsActive()) {
            temp.push_back(worker);
        }
    }

    sort(temp.begin(), temp.end(),
        [](const LibraryWorker& a, const LibraryWorker& b) {
            return a.getLastName() < b.getLastName();
        });

    initializeArray();
    arrayCount = 0;
    for (const auto& worker : temp) {
        workersArray[arrayCount] = worker;
        arrayCount++;
    }

    cout << "Array отсортирован по фамилии!" << endl;
}

void LibraryManager::sortArrayByAge() {
    if (arrayCount == 0) {
        cout << "Array пуст!" << endl;
        return;
    }

    vector<LibraryWorker> temp;
    for (const auto& worker : workersArray) {
        if (worker.getIsActive()) {
            temp.push_back(worker);
        }
    }

    sort(temp.begin(), temp.end(),
        [](const LibraryWorker& a, const LibraryWorker& b) {
            return a.getAge() < b.getAge();
        });

    initializeArray();
    arrayCount = 0;
    for (const auto& worker : temp) {
        workersArray[arrayCount] = worker;
        arrayCount++;
    }

    cout << "Array отсортирован по возрасту!" << endl;
}

// === MENU SYSTEM ===

void LibraryManager::showMainMenu() {
    int choice;
    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ БИБЛИОТЕКИ РАБОТНИКОВ ===" << endl;
        generateChooseMenu(1, true,
            "Работа с VECTOR",
            "Работа с LIST",
            "Работа с ARRAY",
            "Выход");

        cout << "Выберите опцию (1-4): ";
        choice = checkTryToInputInt();

        switch (choice) {
            case 1: showVectorMenu(); break;
            case 2: showListMenu(); break;
            case 3: showArrayMenu(); break;
            case 4: cout << "Выход..." << endl; break;
            default: cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 4);
}

void LibraryManager::showVectorMenu() {
    int choice;
    do {
        cout << "\n=== VECTOR OPERATIONS ===" << endl;
        generateChooseMenu(1, true,
            "Добавить работника",
            "Удалить работника",
            "Редактировать работника",
            "Показать всех",
            "Поиск по имени",
            "Поиск по возрасту",
            "Сортировка по имени",
            "Сортировка по возрасту",
            "Назад");

        cout << "Выберите опцию (1-9): ";
        choice = checkTryToInputInt();

        switch (choice) {
            case 1: addToVector(); break;
            case 2: removeFromVector(); break;
            case 3: editInVector(); break;
            case 4: printVector(); break;
            case 5: searchInVectorByName(); break;
            case 6: searchInVectorByAge(); break;
            case 7: sortVectorByName(); break;
            case 8: sortVectorByAge(); break;
            case 9: break;
            default: cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 9);
}

void LibraryManager::showListMenu() {
    int choice;
    do {
        cout << "\n=== LIST OPERATIONS ===" << endl;
        generateChooseMenu(1, true,
            "Добавить работника",
            "Удалить работника",
            "Редактировать работника",
            "Показать всех",
            "Поиск по имени",
            "Поиск по возрасту",
            "Сортировка по имени",
            "Сортировка по возрасту",
            "Назад");

        cout << "Выберите опцию (1-9): ";
        choice = checkTryToInputInt();

        switch (choice) {
            case 1: addToList(); break;
            case 2: removeFromList(); break;
            case 3: editInList(); break;
            case 4: printList(); break;
            case 5: searchInListByName(); break;
            case 6: searchInListByAge(); break;
            case 7: sortListByName(); break;
            case 8: sortListByAge(); break;
            case 9: break;
            default: cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 9);
}

void LibraryManager::showArrayMenu() {
    int choice;
    do {
        cout << "\n=== ARRAY OPERATIONS ===" << endl;
        generateChooseMenu(1, true,
            "Добавить работника",
            "Удалить работника",
            "Редактировать работника",
            "Показать всех",
            "Поиск по имени",
            "Поиск по возрасту",
            "Сортировка по имени",
            "Сортировка по возрасту",
            "Назад");

        cout << "Выберите опцию (1-9): ";
        choice = checkTryToInputInt();

        switch (choice) {
            case 1: addToArray(); break;
            case 2: removeFromArray(); break;
            case 3: editInArray(); break;
            case 4: printArray(); break;
            case 5: searchInArrayByName(); break;
            case 6: searchInArrayByAge(); break;
            case 7: sortArrayByName(); break;
            case 8: sortArrayByAge(); break;
            case 9: break;
            default: cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 9);
}