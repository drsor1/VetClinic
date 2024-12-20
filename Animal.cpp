#include "Animal.h" // Подключение заголовочного файла с описанием класса Animal

// Конструктор класса Animal, инициализирует все члены класса значениями, переданными в аргументах
Animal::Animal(const std::string& name, const std::string& species, const std::string& breed, int age, const Owner& owner)
 : name(name), species(species), breed(breed), age(age), owner(owner) {}

// Метод для получения имени животного
std::string Animal::getName() const {
    return name; // Возвращаем имя животного
}

// Метод для получения вида животного (например, кошка, собака)
std::string Animal::getSpecies() const {
    return species; // Возвращаем вид животного
}

// Метод для получения породы животного
std::string Animal::getBreed() const {
    return breed; // Возвращаем породу животного
}

// Метод для получения возраста животного
int Animal::getAge() const {
    return age; // Возвращаем возраст животного
}

// Метод для получения информации о владельце животного
const Owner& Animal::getOwner() const {
    return owner; // Возвращаем ссылку на объект владельца
}