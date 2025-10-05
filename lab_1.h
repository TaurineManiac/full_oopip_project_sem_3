//
// Created by Lenovo on 08.09.2025.
//

#ifndef FULL_OOPIP_PROJECT_SEM_3_LAB_1_H
#define FULL_OOPIP_PROJECT_SEM_3_LAB_1_H
#include <vector>
#include <string>

class Phone {
  private:
  bool isHaveButton;
  bool isUsed;
  double BatteryLevel;
  std::string model;
  double price;

public:
  Phone();
  Phone(const Phone &other);
  ~Phone()=default;
  void setBatteryLevel(double newBatteryLevel);
  double getBatteryLevel() const;
  std::string getModel();
  void setModel(std::string newModel);
  bool getIsHaveButton() const;
  void setIsHaveButton(bool newIsHaveButton);
  bool getIsUsed() const;
  void setIsUsed(bool newIsUsed);
  double getPrice() const;
  void setPrice(double newPrice);
};

class Smartphone : public Phone {
  private:
  bool isHaveESim;
  bool isInBasket=false;
  double Hertz;

  public:
  Smartphone();
  Smartphone(const Smartphone &other);
  ~Smartphone()=default;
  void setIsHaveESim(bool newIsHaveESim);
  bool getIsHaveESim();
  void setIsInBasket(bool newIsInBasket);
  bool getIsInBasket();
  void setHertz(double newHertz);
  double getHertz();



};

class ListOfSmartphones {
  private:
  std::vector<Smartphone> smartphones;
  public:
  ListOfSmartphones();
  ListOfSmartphones(const ListOfSmartphones &other);
  ~ListOfSmartphones();
  void printListOfSmartphones(std::vector<Smartphone>& list);
  void removeSmartphoneFromList(int index);
  void addSmartphoneToList(Smartphone smartphone);
  void changeSmartphoneFromList(int index);
  void searchSmartphonePerParameterInList();
  void sortCopyOfListOfSmartphones();
  void printSmartphoneDetails(Smartphone& phone);

  std::vector<Smartphone> getSmartphones();
};

class Basket {
  private:
  std::vector<Smartphone> smartphones;
  public:
  Basket();
  Basket(const Basket &other);
  ~Basket();
  void printListOfSmartphones(std::vector<Smartphone>& newList);
  void removeSmartphoneFromList(int index);
  void addSmartphoneToList(Smartphone smartphone);
  void searchSmartphonePerParameter();
  void sortCopyOfListOfSmartphones();
  void printSmartphoneDetails(Smartphone& phone);

  std::vector<Smartphone> getSmartphones();
};

class Catalog {
  private:
  Basket* basket;
  ListOfSmartphones* listOfSmartphones;

public:
  Catalog();
  Catalog(Catalog &other);
  ~Catalog();
  void loadSmartphonesFromFile();
  void inputSmartphoneIntoFile(Smartphone smartphone);
  int chooseSmartphoneInFile();
  void deleteSmartphoneFromFile();
  void rewriteSmartphonesInFile();

  void printListOfSmartphones();
  void removeSmartphoneFromList(int index);
  void addSmartphoneToList();
  void changeSmartphoneFromList(int index);
  void searchSmartphonePerParameterInList();
  void sortCopyOfListOfSmartphones();

  void printBasketOfSmartphones();
  void removeSmartphoneFromBasket(int index);
  void addSmartphoneToBasket();
  void searchSmartphonePerParameterInBasket();
  void sortCopyOfBasketOfSmartphones();

  Basket* getBasket();
  ListOfSmartphones* getListOfSmartphones();
};


class FinalCatalog {
  private:
  Catalog* catalog;
  public:
  FinalCatalog();
  FinalCatalog(Catalog &other);
  ~FinalCatalog();
  void start();
  void workWithBasket();
  void workWithListOfSmartphones();
  Catalog* getCatalog();
};

#endif //FULL_OOPIP_PROJECT_SEM_3_LAB_1_H