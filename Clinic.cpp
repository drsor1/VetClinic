// Подключение необходимых заголовочных файлов
#include "Clinic.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Список доступных специализаций ветеринаров
const std::vector<std::string> specializations = {"Общая практика", "Хирургия", "Стоматология", "Дерматология", "Кардиология"};
// Список возможных видов животных
const std::vector<std::string> speciesList = {"Собака", "Кошка", "Птица", "Кролик", "Хомяк", "Рыба", "Черепаха", "Ящерица",
"Змея", "Морская свинка"};

// Конструктор класса Clinic, инициализирует имя и адрес клиники
Clinic::Clinic(const std::string& name, const std::string& address)
    : name(name), address(address) {}

// Удаление записи на прием через пользовательский ввод
void Clinic::removeAppointmentFromUserInput() {
    // Проверка наличия записей
    if (appointments.empty()) {
        std::cout << "Никаких записей, которые можно было бы отменить.\n";
        return;
    }

    // Сбор уникальных имен владельцев из списка приемов
    std::vector<std::string> ownerNames;
    for (const auto& app : appointments) {
        std::string ownerName = app.getAnimal().getOwner().getName();
        // Если имя владельца еще не добавлено в список, добавляем его
        if (std::find(ownerNames.begin(), ownerNames.end(), ownerName) == ownerNames.end()) {
            ownerNames.push_back(ownerName);
        }
    }

    // Вывод списка владельцев
    std::cout << "Владельцы животных (на прием):\n";
    for (const auto& ownerName : ownerNames) {
        std::cout << "- " << ownerName << "\n";
    }

    // Пользователь выбирает владельца
    std::string selectedOwner;
    std::cout << "Введите имя нужного владельца животного: ";
    std::getline(std::cin, selectedOwner);

    // Проверка существования выбранного владельца
    auto ownerIt = std::find(ownerNames.begin(), ownerNames.end(), selectedOwner);
    if (ownerIt == ownerNames.end()) {
        std::cout << "Такого владельца нет.\n";
        return;
    }

    // Сбор имен животных, принадлежащих выбранному владельцу
    std::vector<std::string> animalNames;
    for (const auto& app : appointments) {
        if (app.getAnimal().getOwner().getName() == selectedOwner) {
            animalNames.push_back(app.getAnimal().getName());
        }
    }

    // Вывод списка животных
    std::cout << "Животные данного владельца записанные на прием: " << selectedOwner << ":\n";
    for (const auto& animalName : animalNames) {
        std::cout << "- " << animalName << "\n";
    }

    // Пользователь выбирает животное
    std::string selectedAnimal;
    std::cout << "Введите имя животного: ";
    std::getline(std::cin, selectedAnimal);

    // Проверка существования выбранного животного
    auto animalIt = std::find(animalNames.begin(), animalNames.end(), selectedAnimal);
    if (animalIt == animalNames.end()) {
        std::cout << "Такого животного нет.\n";
        return;
    }

    // Поиск приема по имени владельца и животного
    auto it = std::find_if(appointments.begin(), appointments.end(), [&](const Appointment& app) {
        return app.getAnimal().getOwner().getName() == selectedOwner && app.getAnimal().getName() == selectedAnimal;
    });

    // Удаление приема, если он найден
    if (it != appointments.end()) {
        appointments.erase(it);
        std::cout << "Запись успешно удалена.\n";
    } else {
        std::cout << "Запись под такого владельца и животное не найдена.\n";
    }
}

// Добавление ветеринара в клинику
void Clinic::addVeterinarian(const Veterinarian& veterinarian) {
    veterinarians.push_back(veterinarian);
}

// Добавление записи на прием
void Clinic::scheduleAppointment(const Appointment& appointment) {
    appointments.push_back(appointment);
}

// Вывод списка всех записей
void Clinic::listAppointments() const {
    for (const auto& appointment : appointments) {
        std::cout << appointment.getFullDetails() << std::endl;
    }
}

// Получение списка всех ветеринаров
std::vector<Veterinarian> Clinic::getVeterinarians() const {
    return veterinarians;
}
// Добавление ветеринара через пользовательский ввод
void Clinic::addVeterinarianFromUserInput() {
    std::string name, specialization;
    int experience = -1;

    // Ввод имени ветеринара
    std::cout << "Введите имя ветеринара: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Имя ветеринара не может быть пустым. Пожалуйста, введите имя: ";
        std::getline(std::cin, name);
    }
    // Ввод специализации
    std::cout << "Выберите специализацию:\n";
    for (size_t i = 0; i < specializations.size(); ++i) {
        std::cout << i + 1 << ". " << specializations[i] << "\n";
    }
    int specChoice;
    std::cin >> specChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    specialization = (specChoice >= 1 && specChoice <= specializations.size()) ? specializations[specChoice - 1] : "Общая практика";

    // Ввод опыта работы
    while (experience < 0 || experience > 100) {
        std::cout << "Введите опыт работы (0-100): ";
        std::cin >> experience;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            experience = -1;
        }
    }

    // Создание и добавление ветеринара
    Veterinarian vet(name, specialization, experience);
    addVeterinarian(vet);
    std::cout << "Ветеринар добавлен успешно.\n";
}

// Добавление записи через пользовательский ввод
void Clinic::scheduleAppointmentFromUserInput() {
    std::string ownerName, contactInfo, animalName, species, breed, vetName, date;
    int age = -1;
    std::string serviceName, serviceDescription;

    // Ввод информации о владельце
    std::cout << "Введите имя владельца животного: ";
    std::getline(std::cin, ownerName);

// Проверка на пустое имя
    while (ownerName.empty()) {
        std::cout << "Имя владельца не может быть пустым. Пожалуйста, введите имя: ";
        std::getline(std::cin, ownerName);
    }

    std::cout << "Введите контактную информацию (почта/телефон): ";
    std::getline(std::cin, contactInfo);

    // Проверка на пустую контактную информацию (можно добавить более строгую проверку формата)
    while (contactInfo.empty()) {
        std::cout << "Контактная информация не может быть пустой. Пожалуйста, введите контактную информацию: ";
        std::getline(std::cin, contactInfo);
    }

    // Ввод информации о животном
    std::cout << "Введите имя животного: ";
    std::getline(std::cin, animalName);

    std::cout << "Выберите животное:\n";
    for (size_t i = 0; i < speciesList.size(); ++i) {
        std::cout << i + 1 << ". " << speciesList[i] << "\n";
    }
    int speciesChoice;
    std::cin >> speciesChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    species = (speciesChoice >= 1 && speciesChoice <= speciesList.size()) ? speciesList[speciesChoice - 1] : "Собака";

    std::cout << "Введите породу: ";
    std::getline(std::cin, breed);

    
    std::string ageInput; // Для хранения ввода как строки

    while (age < 0) {
        std::cout << "Введите возраст животного (целое число): ";
        std::getline(std::cin, ageInput); // Чтение всей строки

        if (ageInput.empty()) {
            std::cout << "Возраст не может быть пустым. Пожалуйста, введите возраст " << std::endl;
            continue; // Возврат к началу цикла
        }

        try {
            age = std::stoi(ageInput); // Преобразование в целое число
            if (age < 0) {
                std::cout << "Возраст не может быть отрицательным. Пожалуйста, введите возраст " << std::endl;
            }
        } catch (const std::invalid_argument& e) {
        std::cout << "Некорректный ввод. Пожалуйста, введите целое число " << std::endl;
        } catch (const std::out_of_range& e) {
        std::cout << "Введенное число слишком большое. Пожалуйста, введите целое число " << std::endl;
        }
    }

    Owner owner(ownerName, contactInfo);
    Animal animal(animalName, species, breed, age, owner);

    // Ввод информации о ветеринаре
    std::cout << "Доступные ветеринары:\n";
    for (const auto& vet : veterinarians) {
        std::cout << "- " << vet.getName() << "\n";
    }
    std::cout << "Введите имя нужного ветеринара: ";
    std::getline(std::cin, vetName);
    auto it = std::find_if(veterinarians.begin(), veterinarians.end(),
    [&](const Veterinarian& v) { return v.getName() == vetName; });
    if (it == veterinarians.end()) {
        std::cout << "Данный ветеринар отсутствует в списке.\n";
        return;
    }
    Veterinarian veterinarian = *it;

    // Ввод информации о записи
    std::cout << "Введите дату и время записи: ";
    std::getline(std::cin, date);
    std::string priceInput; // Для хранения ввода как строки
    std::cout << "Введите название услуги(процедуры): ";
    std::getline(std::cin, serviceName);
    std::cout << "Введите описание услуги(процедуры): ";
    std::getline(std::cin, serviceDescription);
    double servicePrice = -1;
    while (servicePrice < 0) {
        std::cout << "Введите стоимость (число): ";
        std::getline(std::cin, priceInput); // Чтение всей строки

        if (priceInput.empty()) {
            std::cout << "Стоимость не может быть пустой. Пожалуйста, введите стоимость " << std::endl;
            continue; // Возврат к началу цикла
        }

        try {
            servicePrice = std::stoi(priceInput); // Преобразование в целое число
            if (servicePrice < 0) {
                std::cout << "Стоимость не может быть отрицательной. Пожалуйста, введите стоимость " << std::endl;
            }
        } catch (const std::invalid_argument& e) {
        std::cout << "Некорректный ввод. Пожалуйста, введите число " << std::endl;
        } catch (const std::out_of_range& e) {
        std::cout << "Введенное число слишком большое. Пожалуйста, введите число меньше " << std::endl;
        }
    }

    Service service(serviceName, serviceDescription, servicePrice);
    Appointment appointment(animal, veterinarian, date, {service});
    scheduleAppointment(appointment);
    std::cout << "Запись оформлена успешно.\n";
}