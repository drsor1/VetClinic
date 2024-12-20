#ifndef VETERINARIAN_H
#define VETERINARIAN_H

#include <string> // Подключение библиотеки для работы со строками

// Определение класса Veterinarian (ветеринар)
class Veterinarian {
public:
    // Конструктор, инициализирующий объект ветеринара с заданными параметрами
    Veterinarian(const std::string& name, const std::string& specialization, int experience);

    // Метод для получения имени ветеринара
    std::string getName() const;

    // Метод для получения специализации ветеринара
    std::string getSpecialization() const;

    // Метод для получения опыта ветеринара (в годах)
    int getExperience() const;

private:
    std::string name; // Имя ветеринара
    std::string specialization; // Специализация ветеринара (например, терапевт, хирург)
    int experience; // Опыт ветеринара (в годах)
};

#endif // VETERINARIAN_H
