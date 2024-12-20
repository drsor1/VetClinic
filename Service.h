#ifndef SERVICE_H
#define SERVICE_H

#include <string> // Подключение библиотеки для работы со строками

// Определение класса Service (услуга)
class Service {
public:
    // Конструктор, инициализирующий объект услуги с заданными параметрами
    Service(const std::string& name, const std::string& description, double price);

    // Метод для получения названия услуги
    std::string getName() const;

    // Метод для получения описания услуги
    std::string getDescription() const;

    // Метод для получения цены услуги
    double getPrice() const;

private:
    std::string name; // Название услуги
    std::string description; // Описание услуги
    double price; // Цена услуги
};

#endif // SERVICE_H