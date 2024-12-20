#ifndef ANIMAL_H
#define ANIMAL_H

#include <string> // Подключение библиотеки для работы со строками
#include "Owner.h" // Подключение заголовочного файла с описанием класса Owner

// Определение класса Animal (животное)
class Animal {
public:
    // Конструктор, инициализирующий объект животного с заданными параметрами
    Animal(const std::string& name, const std::string& species, const std::string& breed, int age, const Owner& owner);
    
    // Метод для получения имени животного
    std::string getName() const;

    // Метод для получения вида животного (например, кошка, собака)
    std::string getSpecies() const;

    // Метод для получения породы животного
    std::string getBreed() const;

    // Метод для получения возраста животного
    int getAge() const;

    // Метод для получения информации о владельце животного
    const Owner& getOwner() const;

private:
    std::string name; // Имя животного
    std::string species; // Вид животного
    std::string breed; // Порода животного
    int age; // Возраст животного
    Owner owner; // Информация о владельце животного
};

#endif // ANIMAL_H