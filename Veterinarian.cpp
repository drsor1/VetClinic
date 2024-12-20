#include "Veterinarian.h" // Подключение заголовочного файла с описанием класса Veterinarian

// Конструктор класса Veterinarian, инициализирует имя, специализацию и опыт ветеринара
Veterinarian::Veterinarian(const std::string& name, const std::string& specialization, int experience)
 : name(name), specialization(specialization), experience(experience) {}

// Метод для получения имени ветеринара
std::string Veterinarian::getName() const {
    return name; // Возвращаем имя ветеринара
}

// Метод для получения опыта ветеринара (в годах)
int Veterinarian::getExperience() const {
    return experience; // Возвращаем опыт ветеринара
}

// Метод для получения специализации ветеринара
std::string Veterinarian::getSpecialization() const {
    return specialization; // Возвращаем специализацию ветеринара
}
