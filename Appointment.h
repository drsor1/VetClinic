#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string> // Подключение библиотеки для работы со строками
#include <vector> // Подключение библиотеки для работы с векторами
#include "Animal.h" // Подключение заголовочного файла с описанием класса Animal
#include "Veterinarian.h" // Подключение заголовочного файла с описанием класса Veterinarian
#include "Service.h" // Подключение заголовочного файла с описанием класса Service

// Определение класса Appointment (прием)
class Appointment {
public:
    // Конструктор, инициализирующий объект приема с заданными параметрами
    Appointment(const Animal& animal, const Veterinarian& veterinarian, const std::string& date, const std::vector<Service>& services, const std::string& notes = "");

    // Метод для получения краткой информации о приеме
    std::string getDetails() const;

    // Метод для получения полной информации о приеме
    std::string getFullDetails() const;

    // Геттер для получения информации о животном
    const Animal& getAnimal() const;

    // Геттер для получения владельца животного через объект Animal
    const Owner& getOwner() const;

private:
    Animal animal; // Объект животного, связанный с приемом
    Veterinarian veterinarian; // Объект ветеринара, проводящего прием
    std::string date; // Дата приема
    std::vector<Service> services; // Список услуг, предоставленных на приеме
    std::string notes; // Примечания к приему (например, диагноз или рекомендации)
};

#endif // APPOINTMENT_H
