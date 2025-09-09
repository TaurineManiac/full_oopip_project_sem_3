#include "lab_1.h"
#include <generate.h>
#include <inputCheck.h>
#include <iomanip>

#include <iostream>
#include <ostream>
#include <string>



using namespace std;

Phone::Phone() {
    isHaveButton=false;
    isUsed=false;
    BatteryLevel=0;
    price=0;
    model = "";
}

Phone::Phone(const Phone &anotherPhone) {
    isHaveButton=anotherPhone.isHaveButton;
    isUsed=anotherPhone.isUsed;
    BatteryLevel=anotherPhone.BatteryLevel;
    price=anotherPhone.price;
    model=anotherPhone.model;

}

double Phone::getBatteryLevel() {
    return BatteryLevel;
}

void Phone::setBatteryLevel(double newBatteryLevel) {
    BatteryLevel=newBatteryLevel;
}

bool Phone::getIsHaveButton() {
    return isHaveButton;
}

void Phone::setIsHaveButton(bool newIsHaveButton) {
    isHaveButton=newIsHaveButton;
}

double Phone::getPrice() {
    return price;
}

void Phone::setPrice(double newPrice) {
    price=newPrice;
}

bool Phone::getIsUsed() {
    return isUsed;
}

void Phone::setIsUsed(bool newIsUsed) {
    isUsed=newIsUsed;
}

std::string Phone::getModel() {
    return model;
}

void Phone::setModel(std::string newModel) {
    model=newModel;
}

//==============================================================================================================================================

double Smartphone::getHertz() {
    return Hertz;
}

void Smartphone::setHertz(double newHertz) {
    Hertz=newHertz;
}

bool Smartphone::getIsHaveESim() {
    return isHaveESim;
}

void Smartphone::setIsHaveESim(bool newIsHaveESim) {
    isHaveESim=newIsHaveESim;
}

bool Smartphone::getIsInBasket() {
    return isInBasket;
}

void Smartphone::setIsInBasket(bool newIsInBasket) {
    isInBasket=newIsInBasket;
}

Smartphone::Smartphone() {
    isHaveESim=false;
    isInBasket=false;
    Hertz=0;
}

Smartphone::Smartphone(const Smartphone &other) {
    isHaveESim=other.isHaveESim;
    isInBasket=other.isInBasket;
    Hertz=other.Hertz;
}

ListOfSmartphones::ListOfSmartphones() {

}

ListOfSmartphones::ListOfSmartphones(const ListOfSmartphones &other) {
    smartphones=other.smartphones;
}

ListOfSmartphones::~ListOfSmartphones() {
    for (int i=0; i<smartphones.size(); i++) {
        smartphones[i].~Smartphone();
    }
}

void ListOfSmartphones::addSmartphoneToList(Smartphone smartphone) {
    smartphones.push_back(smartphone);
}

void ListOfSmartphones::printListOfSmartphones(vector<Smartphone>& list) {
    if (list.empty()) {
        cout << "╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║                                        СПИСОК СМАРТФОНОВ ПУСТ                                              ║" << endl;
        cout << "╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
        return;
    }

    // Шапка таблицы
    cout << "╔═════╦════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║  ID ║                                ХАРАКТЕРИСТИКИ СМАРТФОНА                                                    ║" << endl;
    cout << "╠═════╬════════════════════════════════════════════════════════════════════════════════════════════════════════════╣" << endl;

    for (int i = 0; i < list.size(); i++) {
        cout << "║ " << setw(3) << i << " ║ ";
        printSmartphoneDetails((list[i]));
        cout << " ║" << endl;

        if (i != list.size() - 1) {
            cout << "╠═════╬════════════════════════════════════════════════════════════════════════════════════════════════════════════╣" << endl;
        }
    }

    cout << "╚═════╩════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}


// Вспомогательный метод для вывода деталей одного смартфона
void ListOfSmartphones::printSmartphoneDetails(Smartphone& phone) {
    cout << "Модель: " << setw(15) << left << phone.getModel()
         << " | Цена: " << setw(8) << phone.getPrice() << "$"
         << " | Батарея: " << setw(5) << phone.getBatteryLevel() << "%"
         << " | Герцовка: " << setw(4) << phone.getHertz() << "Hz"
         << " | eSIM: " << setw(3) << (phone.getIsHaveESim() ? "Да" : "Нет")
         << " | Кнопки: " << setw(3) << (phone.getIsHaveButton() ? "Да" : "Нет")
         << " | Б/У: " << setw(3) << (phone.getIsUsed() ? "Да" : "Нет")
         << " | В корзине: " << setw(3) << (phone.getIsInBasket() ? "Да" : "Нет");
}

void ListOfSmartphones::changeSmartphoneFromList(int index) {
    int choice;
    cout << "Изменить модель смартфона?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        string str=mylib::checkTryToInputString(false);
        smartphones[index].setModel(str);
    }
    cout << "Изменить наличие eSim?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        smartphones[index].setIsHaveESim(!smartphones[index].getIsHaveESim());
    }
    cout << "Изменить герцовку?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        smartphones[index].setHertz(mylib::checkTryToInputDouble());
    }
    cout << "Изменить наличие кнопок?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        smartphones[index].setIsHaveButton(!smartphones[index].getIsHaveButton());
    }
    cout << "Изменить был ли Б/У?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        smartphones[index].setIsUsed(!smartphones[index].getIsUsed());
    }
    cout << "Изменить ёмкость батареи?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        smartphones[index].setBatteryLevel(mylib::checkTryToInputDouble());
    }
    cout << "Изменить цену?(1-да|2-нет)" << endl;
    choice=mylib::checkYourSolution(2);
    if (choice == 1) {
        smartphones[index].setPrice(mylib::checkTryToInputDouble());
    }
    cout << "Изменение завершено." << endl;
}

void ListOfSmartphones::removeSmartphoneFromList(int index) {
    smartphones.erase(smartphones.begin()+index);
    cout << "Элемент удалён." << endl;
}

void ListOfSmartphones::searchSmartphonePerParameterInList() {
    cout << "Выберите параметр по какому хотите искать (1-7, 8-Выход):" << endl;
    cout << "1. Цена\n"
            "2. Б/У\n"
            "3. Герцовка\n"
            "4. Имеет eSim\n"
            "5. Мощность батареи\n"
            "6. Модель\n"
            "7. Имеет физические кнопки\n"
            "8. Выход" << endl;

    int choice = mylib::checkYourSolution(8);
    bool found = false; // флаг совпадений

    switch (choice) {
        case 1: {
            cout << "Введите цену:" << endl;
            double newPrice = mylib::checkTryToInputDouble();
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getPrice() == newPrice) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 2: {
            cout << "Выберите Б/У (1-Да, 2-Нет):" << endl;
            bool newUsed = (mylib::checkYourSolution(2) == 1);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getIsUsed() == newUsed) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 3: {
            cout << "Введите герцовку экрана (HHz):" << endl;
            double newHertz = mylib::checkTryToInputDouble();
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getHertz() == newHertz) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 4: {
            cout << "Смартфон имеет eSim? (1-Да, 2-Нет):" << endl;
            bool newESim = (mylib::checkYourSolution(2) == 1);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getIsHaveESim() == newESim) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 5: {
            cout << "Введите ёмкость батареи:" << endl;
            double newBattery = mylib::checkTryToInputDouble();
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getBatteryLevel() == newBattery) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 6: {
            cout << "Введите название модели:" << endl;
            string newModel = mylib::checkTryToInputString(false);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getModel() == newModel) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 7: {
            cout << "Смартфон имеет физические кнопки? (1-Да, 2-Нет):" << endl;
            bool newButton = (mylib::checkYourSolution(2) == 1);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getIsHaveButton() == newButton) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 8: {
            cout << "Выход из поиска." << endl;
            return;
        }
        default:
            return;
    }

    if (!found) {
        cout << "Совпадений не найдено." << endl;
    }
}


void ListOfSmartphones::sortCopyOfListOfSmartphones() {

    if (smartphones.empty()) {
        cout << "Список пуст, сортировать нечего." << endl;
        return;
    }

    vector<Smartphone> smartphonesCopy = smartphones;

    cout << "Выберите критерий для сортировки:" << endl;
    cout << "1. Цена\n"
            "2. Б/У\n"
            "3. Герцовка\n"
            "4. Имеет eSim\n"
            "5. Мощность батареи\n"
            "6. Модель\n"
            "7. Имеет физические кнопки\n"
            "8. Выход" << endl;

    int choice = mylib::checkYourSolution(8);

    if (choice == 8) {
        cout << "Выход без сортировки." << endl;
        return;
    }

    for (int i = 0; i < smartphonesCopy.size() - 1; i++) {
        for (int j = 0; j < smartphonesCopy.size() - i - 1; j++) {
            bool needSwap = false;

            switch (choice) {
                case 1:
                    if (smartphonesCopy[j].getPrice() > smartphonesCopy[j + 1].getPrice())
                        needSwap = true;
                    break;
                case 2:
                    if (smartphonesCopy[j].getIsUsed() > smartphonesCopy[j + 1].getIsUsed())
                        needSwap = true;
                    break;
                case 3:
                    if (smartphonesCopy[j].getHertz() > smartphonesCopy[j + 1].getHertz())
                        needSwap = true;
                    break;
                case 4:
                    if (smartphonesCopy[j].getIsHaveESim() > smartphonesCopy[j + 1].getIsHaveESim())
                        needSwap = true;
                    break;
                case 5:
                    if (smartphonesCopy[j].getBatteryLevel() > smartphonesCopy[j + 1].getBatteryLevel())
                        needSwap = true;
                    break;
                case 6:
                    if (smartphonesCopy[j].getModel() > smartphonesCopy[j + 1].getModel())
                        needSwap = true;
                    break;
                case 7:
                    if (smartphonesCopy[j].getIsHaveButton() > smartphonesCopy[j + 1].getIsHaveButton())
                        needSwap = true;
                    break;
            }

            if (needSwap) {
                Smartphone temp = smartphonesCopy[j];
                smartphonesCopy[j] = smartphonesCopy[j + 1];
                smartphonesCopy[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированный список:" << endl;
    printListOfSmartphones(smartphonesCopy);
}

void Basket::addSmartphoneToList(Smartphone smartphone) {
    smartphones.push_back(smartphone);
}

void Basket::printListOfSmartphones(std::vector<Smartphone> &newList) {
    if (newList.empty()) {
        cout << "╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║                                        СПИСОК СМАРТФОНОВ ПУСТ                                              ║" << endl;
        cout << "╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
        return;
    }

    // Шапка таблицы
    cout << "╔═════╦════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║  ID ║                                ХАРАКТЕРИСТИКИ СМАРТФОНА                                                    ║" << endl;
    cout << "╠═════╬════════════════════════════════════════════════════════════════════════════════════════════════════════════╣" << endl;

    for (int i = 0; i < newList.size(); i++) {
        cout << "║ " << setw(3) << i << " ║ ";
        printSmartphoneDetails((newList[i]));
        cout << " ║" << endl;

        if (i != newList.size() - 1) {
            cout << "╠═════╬════════════════════════════════════════════════════════════════════════════════════════════════════════════╣" << endl;
        }
    }

    cout << "╚═════╩════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}

void Basket::printSmartphoneDetails(Smartphone &phone) {
    cout << "Модель: " << setw(15) << left << phone.getModel()
     << " | Цена: " << setw(8) << phone.getPrice() << "$"
     << " | Батарея: " << setw(5) << phone.getBatteryLevel() << "%"
     << " | Герцовка: " << setw(4) << phone.getHertz() << "Hz"
     << " | eSIM: " << setw(3) << (phone.getIsHaveESim() ? "Да" : "Нет")
     << " | Кнопки: " << setw(3) << (phone.getIsHaveButton() ? "Да" : "Нет")
     << " | Б/У: " << setw(3) << (phone.getIsUsed() ? "Да" : "Нет")
     << " | В корзине: " << setw(3) << (phone.getIsInBasket() ? "Да" : "Нет");
}

void Basket::sortCopyOfListOfSmartphones() {

    if (smartphones.empty()) {
        cout << "Список пуст, сортировать нечего." << endl;
        return;
    }

    vector<Smartphone> smartphonesCopy = smartphones;

    cout << "Выберите критерий для сортировки:" << endl;
    cout << "1. Цена\n"
            "2. Б/У\n"
            "3. Герцовка\n"
            "4. Имеет eSim\n"
            "5. Мощность батареи\n"
            "6. Модель\n"
            "7. Имеет физические кнопки\n"
            "8. Выход" << endl;

    int choice = mylib::checkYourSolution(8);

    if (choice == 8) {
        cout << "Выход без сортировки." << endl;
        return;
    }

    for (int i = 0; i < smartphonesCopy.size() - 1; i++) {
        for (int j = 0; j < smartphonesCopy.size() - i - 1; j++) {
            bool needSwap = false;

            switch (choice) {
                case 1:
                    if (smartphonesCopy[j].getPrice() > smartphonesCopy[j + 1].getPrice())
                        needSwap = true;
                    break;
                case 2:
                    if (smartphonesCopy[j].getIsUsed() > smartphonesCopy[j + 1].getIsUsed())
                        needSwap = true;
                    break;
                case 3:
                    if (smartphonesCopy[j].getHertz() > smartphonesCopy[j + 1].getHertz())
                        needSwap = true;
                    break;
                case 4:
                    if (smartphonesCopy[j].getIsHaveESim() > smartphonesCopy[j + 1].getIsHaveESim())
                        needSwap = true;
                    break;
                case 5:
                    if (smartphonesCopy[j].getBatteryLevel() > smartphonesCopy[j + 1].getBatteryLevel())
                        needSwap = true;
                    break;
                case 6:
                    if (smartphonesCopy[j].getModel() > smartphonesCopy[j + 1].getModel())
                        needSwap = true;
                    break;
                case 7:
                    if (smartphonesCopy[j].getIsHaveButton() > smartphonesCopy[j + 1].getIsHaveButton())
                        needSwap = true;
                    break;
            }

            if (needSwap) {
                Smartphone temp = smartphonesCopy[j];
                smartphonesCopy[j] = smartphonesCopy[j + 1];
                smartphonesCopy[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированный список:" << endl;
    printListOfSmartphones(smartphonesCopy);
}

Basket::Basket() {

}

Basket::Basket(const Basket &other) {
    smartphones = other.smartphones;
}

Basket::~Basket() {

}

void Basket::removeSmartphoneFromList(int index) {
    smartphones.erase(smartphones.begin() + index);
    cout << "Элемент удалён." << endl;
}

void Basket::searchSmartphonePerParameter() {
        cout << "Выберите параметр по какому хотите искать (1-7, 8-Выход):" << endl;
    cout << "1. Цена\n"
            "2. Б/У\n"
            "3. Герцовка\n"
            "4. Имеет eSim\n"
            "5. Мощность батареи\n"
            "6. Модель\n"
            "7. Имеет физические кнопки\n"
            "8. Выход" << endl;

    int choice = mylib::checkYourSolution(8);
    bool found = false; // флаг совпадений

    switch (choice) {
        case 1: {
            cout << "Введите цену:" << endl;
            double newPrice = mylib::checkTryToInputDouble();
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getPrice() == newPrice) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 2: {
            cout << "Выберите Б/У (1-Да, 2-Нет):" << endl;
            bool newUsed = (mylib::checkYourSolution(2) == 1);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getIsUsed() == newUsed) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 3: {
            cout << "Введите герцовку экрана (HHz):" << endl;
            double newHertz = mylib::checkTryToInputDouble();
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getHertz() == newHertz) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 4: {
            cout << "Смартфон имеет eSim? (1-Да, 2-Нет):" << endl;
            bool newESim = (mylib::checkYourSolution(2) == 1);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getIsHaveESim() == newESim) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 5: {
            cout << "Введите ёмкость батареи:" << endl;
            double newBattery = mylib::checkTryToInputDouble();
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getBatteryLevel() == newBattery) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 6: {
            cout << "Введите название модели:" << endl;
            string newModel = mylib::checkTryToInputString(false);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getModel() == newModel) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 7: {
            cout << "Смартфон имеет физические кнопки? (1-Да, 2-Нет):" << endl;
            bool newButton = (mylib::checkYourSolution(2) == 1);
            for (int i = 0; i < smartphones.size(); i++) {
                if (smartphones[i].getIsHaveButton() == newButton) {
                    printSmartphoneDetails(smartphones[i]);
                    cout << endl;
                    found = true;
                }
            }
            break;
        }
        case 8: {
            cout << "Выход из поиска." << endl;
            return;
        }
        default:
            return;
    }

    if (!found) {
        cout << "Совпадений не найдено." << endl;
    }
}























