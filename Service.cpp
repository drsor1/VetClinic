#include "Service.h" // Подключение заголовочного файла с описанием класса Service

// Конструктор класса Service, инициализирует объект услуги с заданными параметрами
Service::Service(const std::string& name, const std::string& description, double price)
 : name(name), description(description), price(price) {}

// Метод для получения названия услуги
std::string Service::getName() const {
    return name; // Возвращаем название услуги
}

// Метод для получения описания услуги
std::string Service::getDescription() const {
    return description; // Возвращаем описание услуги
}

// Метод для получения цены услуги
double Service::getPrice() const {
    return price; // Возвращаем цену услуги
}