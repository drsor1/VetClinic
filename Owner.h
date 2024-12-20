#ifndef OWNER_H
#define OWNER_H

#include <string> // Подключение библиотеки для работы со строками

// Определение класса Owner (владелец)
class Owner {
public:
    // Конструктор, инициализирующий объект владельца с заданными параметрами
    Owner(const std::string& name, const std::string& contactInfo);

    // Метод для получения имени владельца
    std::string getName() const;

    // Метод для получения контактной информации владельца
    std::string getContactInfo() const;

private:
    std::string name; // Имя владельца
    std::string contactInfo; // Контактная информация владельца
};

#endif // OWNER_H