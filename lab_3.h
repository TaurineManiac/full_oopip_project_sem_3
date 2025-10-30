#ifndef FULL_OOPIP_PROJECT_SEM_3_LAB_3_H
#define FULL_OOPIP_PROJECT_SEM_3_LAB_3_H

#include <array>
#include <list>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class LibraryWorker {
private:
    int id;
    string firstname;
    string lastname;
    int age;
    bool isActive;

public:
    LibraryWorker();
    LibraryWorker(int id, string firstname, string lastname, int age);

    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
    bool getIsActive() const;

    void setId(int id);
    void setFirstName(string firstname);
    void setLastName(string lastname);
    void setAge(int age);
    void setIsActive(bool active);

    void printInfo() const;
};

class LibraryManager {
private:
    vector<LibraryWorker> workersVector;
    list<LibraryWorker> workersList;
    array<LibraryWorker, 100> workersArray;
    int nextId;
    int arrayCount;

public:
    LibraryManager();

    // === VECTOR OPERATIONS ===
    void addToVector();
    void removeFromVector();
    void editInVector();
    void printVector() const;
    void searchInVectorByName();
    void searchInVectorByAge();
    void sortVectorByName();
    void sortVectorByAge();

    // === LIST OPERATIONS ===
    void addToList();
    void removeFromList();
    void editInList();
    void printList() const;
    void searchInListByName();
    void searchInListByAge();
    void sortListByName();
    void sortListByAge();

    // === ARRAY OPERATIONS ===
    bool addToArray();
    void removeFromArray();
    void editInArray();
    void printArray() const;
    void searchInArrayByName();
    void searchInArrayByAge();
    void sortArrayByName();
    void sortArrayByAge();

    // === MENU SYSTEM ===
    void showMainMenu();
    void showVectorMenu();
    void showListMenu();
    void showArrayMenu();

private:
    int getNextId();
    void initializeArray();
};

#endif