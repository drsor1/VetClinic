#include "Appointment.h" // Подключение заголовочного файла с описанием класса Appointment

// Конструктор класса Appointment, инициализирует объект приема с заданными параметрами
Appointment::Appointment(const Animal& animal, const Veterinarian& veterinarian, const std::string& date,
const std::vector<Service>& services, const std::string& notes)
 : animal(animal), veterinarian(veterinarian), date(date), services(services), notes(notes) {}

// Метод для получения краткой информации о приеме (например, имя животного, имя ветеринара, дата приема)
std::string Appointment::getDetails() const {
    return "Запись для " + animal.getName() + " с " + veterinarian.getName() + " на " + date;
}

// Геттер для получения объекта животного
const Animal& Appointment::getAnimal() const {
    return animal; // Возвращаем объект животного
}

// Геттер для получения владельца животного через объект Animal
const Owner& Appointment::getOwner() const {
    return animal.getOwner(); // Возвращаем владельца через объект animal
}

// Метод для получения полной информации о приеме
std::string Appointment::getFullDetails() const {
    std::string fullDetails = "Подробности приема:\n"; // Заголовок полной информации о приеме
    fullDetails += "Имя животного: " + animal.getName() + "\n"; // Имя животного
    fullDetails += "Животное: " + animal.getSpecies() + "\n"; // Вид животного
    fullDetails += "Порода: " + animal.getBreed() + "\n"; // Порода животного
    fullDetails += "Возраст: " + std::to_string(animal.getAge()) + "\n"; // Возраст животного
    fullDetails += "Владелец: " + animal.getOwner().getName() + "\n"; // Имя владельца
    fullDetails += "Контактная Информация: " + animal.getOwner().getContactInfo() + "\n"; // Контактная информация владельца
    fullDetails += "Ветеринар: " + veterinarian.getName() + "\n"; // Имя ветеринара
    fullDetails += "Специализация: " + veterinarian.getSpecialization() + "\n"; // Специализация ветеринара
    fullDetails += "Опыт работы: " + std::to_string(veterinarian.getExperience()) + " лет\n"; // Опыт работы ветеринара
    fullDetails += "Дата и время: " + date + "\n"; // Дата и время приема
    fullDetails += "Услуги: \n"; // Заголовок для списка услуг
    for (const auto& service : services) { // Перебор списка услуг, предоставленных на приеме
        fullDetails += " - " + service.getName() + ": " + service.getDescription() +
        " ($" + std::to_string(service.getPrice()) + ")\n"; // Информация об услуге
    }
    if (!notes.empty()) { // Если есть заметки, добавляем их к полным данным
        fullDetails += "Записки: " + notes + "\n"; // Добавляем заметки
    }
    return fullDetails; // Возвращаем строку с полной информацией о приеме
}