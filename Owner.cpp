#include "Owner.h" // Подключение заголовочного файла с описанием класса Owner

// Конструктор класса Owner, инициализирует имя и контактную информацию владельца
Owner::Owner(const std::string& name, const std::string& contactInfo)
 : name(name), contactInfo(contactInfo) {}

// Метод для получения контактной информации владельца
std::string Owner::getContactInfo() const {
    return contactInfo; // Возвращаем контактную информацию владельца
}

// Метод для получения имени владельца
std::string Owner::getName() const {
    return name; // Возвращаем имя владельца
}