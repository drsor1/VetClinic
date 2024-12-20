#ifndef CLINIC_H
#define CLINIC_H

#include <string> // Подключение библиотеки для работы со строками
#include <vector> // Подключение библиотеки для работы с векторами
#include "Veterinarian.h" // Подключение заголовочного файла с описанием класса Veterinarian
#include "Appointment.h" // Подключение заголовочного файла с описанием класса Appointment

// Определение класса Clinic (клиника)
class Clinic {
public:
    // Конструктор, инициализирующий имя клиники и ее адрес
    Clinic(const std::string& name, const std::string& address);

    // Метод для добавления ветеринара в клинику
    void addVeterinarian(const Veterinarian& veterinarian);

    // Метод для записи на прием в клинику
    void scheduleAppointment(const Appointment& appointment);

    // Метод для отображения списка всех приемов в клинике
    void listAppointments() const;

    // Метод для получения списка всех ветеринаров клиники
    std::vector<Veterinarian> getVeterinarians() const;
    
    // Метод для удаления информации о приеме (через пользовательский ввод)
    void removeAppointmentFromUserInput();

    // Метод для добавления ветеринара через пользовательский ввод
    void addVeterinarianFromUserInput();

    // Метод для записи приема через пользовательский ввод
    void scheduleAppointmentFromUserInput();

private:
    std::string name; // Имя клиники
    std::string address; // Адрес клиники
    std::vector<Veterinarian> veterinarians; // Список ветеринаров клиники
    std::vector<Appointment> appointments; // Список всех приемов в клинике
};

#endif // CLINIC_H