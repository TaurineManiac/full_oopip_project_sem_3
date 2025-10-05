#include <iostream>
#include <windows.h>
#include <generate.h>
#include <inputCheck.h>
#include "lab_1.h"

using namespace std;
using namespace generate;
using namespace mylib;



int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while (true) {
        cout << "Выберите номер лабы(1-7), Выход(8):" << endl;
        bool isSteelRunning = true;
        int numOfLabChoice = checkYourSolution(8);

        switch (numOfLabChoice) {
            case 1 || 2: {
                cout << "В каждом индивидуальном задании необходимо реализовать функции просмотра, добавления, удаления, редактирования, сортировки, поиска данных по необходимым параметрам."
                        " Использовать минимум 5 флагов форматирования. Сформировать табличный вывод всех данных."
                        " Использовать функции setf() и unsetf() для установки и сбрасывания флагов. Использовать функции eof(), fail(), good(), bad(), clear() для проверки состояния потока. " << endl;
                cout << "29.Разработать набор классов (минимум 5 классов, связи между классами: агрегация, композиция, наследование) по предметной области «Каталог мобильных устройств»."
                        " Функционал программы должен позволить собрать данные заказе.  " << endl;
                FinalCatalog* catalog= new FinalCatalog();
                catalog->getCatalog()->loadSmartphonesFromFile();
                catalog->getCatalog()->rewriteSmartphonesInFile();
                catalog->start();
                break;
            }
            case 2:
                cout << "На основе разработанной иерархии классов, реализованной в лабораторной работе "
                        "«Использование потоков ввода/вывода данных»,"
                        " реализовать программу работы с данными, используя потоки файлового ввода-вывода. "
                        "Реализовать функций добавления данных в файл, удаления данных из файла,"
                        " редактирования данных в файле, просмотра данных из файла, поиска данных по необходимым параметрам в файле. "
                        "Использовать функции open(), is_open(), bad(), good(), close(), eof(), fail(), перегрузить операторы !" << endl;
                cout << "ЛАБА ВЫПОЛНЕНА В ЛАБЕ 1" << endl;
                break;
            case 3:
                cout << "Лаба ещё не готова!" << endl;
                break;
            case 4:
                cout << "Лаба ещё не готова!" << endl;
                break;
            case 5:
                cout << "Лаба ещё не готова!" << endl;
                break;
            case 6:
                cout << "Лаба ещё не готова!" << endl;
                break;
            case 7:
                cout << "Лаба ещё не готова!" << endl;
                break;
            case 8:
                cout << "Произошёл выход." << endl;
                isSteelRunning = false;
                break;
            default:
                break;
        }

        if (!isSteelRunning) {
            break;
        }
    }
    return 0;
}