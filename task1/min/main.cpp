#include <iostream>
#include <string>
#include <vector>

/*Вариант 11
Тема проекта: приложение «Журнал учителя».
В приложении должно быть реализовано 2 класса: Журнал и Урок.
Класс Журнал содержит название предмета, имя учителя. Класс Урок содержит дату, тему, номер класса.*/


using namespace std;

class Lesson {
private:
    string date;
    string topic;
    int classNumber;

public:
    Lesson(string d, string t, int cn)
        : date(d), topic(t), classNumber(cn) {}

    Lesson(string d, string t)
        : date(d), topic(t), classNumber(1) {}

    string getDate() const { return date; }
    string getTopic() const { return topic; }
    int getClassNumber() const { return classNumber; }
};

class Journal {
private:
    string subjectName;
    string teacherName;
    vector<Lesson> lessons;

public:
    void setSubject(string subject) {
        subjectName = subject;
    }

    void setTeacher(string teacher) {
        teacherName = teacher;
    }

    void addLesson(const Lesson& lesson) {
        lessons.push_back(lesson);
    }

    // Новые геттеры
    string getSubjectName() const { return subjectName; }
    string getTeacherName() const { return teacherName; }
    const vector<Lesson>& getLessons() const { return lessons; }
};

int main() {
    Journal mathJournal;
    mathJournal.setSubject("Математика");
    mathJournal.setTeacher("Иванова А.С.");

    Lesson lesson1("01.09.2023", "Введение в алгебру", 9);
    Lesson lesson2("05.09.2023", "История математики");
    Lesson lesson3("10.09.2023", "Геометрические фигуры", 7);

    mathJournal.addLesson(lesson1);
    mathJournal.addLesson(lesson2);
    mathJournal.addLesson(lesson3);

    // Вывод через геттеры в main
    cout << "Журнал по предмету: " << mathJournal.getSubjectName() << endl;
    cout << "Преподаватель: " << mathJournal.getTeacherName() << endl << endl;

    cout << "Список уроков:\n";
    for (const Lesson& lesson : mathJournal.getLessons()) {
        cout << "Дата: " << lesson.getDate() << "\n"
            << "Тема: " << lesson.getTopic() << "\n"
            << "Класс: " << lesson.getClassNumber() << "\n"
            << "-----------------\n";
    }

    return 0;
}
