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
  double getBatteryLevel();
  std::string getModel();
  void setModel(std::string newModel);
  bool getIsHaveButton();
  void setIsHaveButton(bool newIsHaveButton);
  bool getIsUsed();
  void setIsUsed(bool newIsUsed);
  double getPrice();
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
};

class Catalog {
  private:
  Basket* basket;
  ListOfSmartphones* listOfSmartphones;

public:
  Catalog();
  Catalog(const Catalog &other);
  ~Catalog();
  void loadSmartphonesFromFile();

  void printListOfSmartphones();
  void removeSmartphoneFromList(int index);
  void addSmartphoneToList(Smartphone smartphone);
  void changeSmartphoneFromList(int index);
  void searchSmartphonePerParameterInList();
  void sortCopyOfListOfSmartphones();

  void getBasketOfSmartphones();
  void removeSmartphoneFromBasket(int index);
  void addSmartphoneToBasket(Smartphone smartphone);
  void searchSmartphonePerParameterInBasket();
  void sortCopyOfBasketOfSmartphones();
};




#endif //FULL_OOPIP_PROJECT_SEM_3_LAB_1_H