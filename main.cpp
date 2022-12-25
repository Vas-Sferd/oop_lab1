#include <bits/stdc++.h>

using namespace std;

class Entry {
public:
    int grade; // Оценка
    string student; // Имя студента
    string subject; // Название предмета
};

class Attestation {
    set<string> students; // Вектор имен студентов
    set<string> subjects; // Вектор названий предметов
    vector<Entry> entries; // Вектор записей в журнале
public:
    void add_student(string student) {
        students.insert(student);
    }
    void add_subject(string subject) {
        subjects.insert(subject);
    }
    void add_mark_grade(int grade, string student, string subject) {
        entries.push_back({grade, student, subject});
    }
    void average_grade_for_student(string student) {
        vector<int> grades;
        for (auto& e : entries) {
            if (e.student == student) {
                grades.push_back(e.grade);
            }
        }
        if (grades.size() != 0) {
            cout << "Средний балл студента " << student << " = " << 1.0 * reduce(grades.begin(), grades.end()) / grades.size() << endl;
        }
    }
    void average_grade_for_student_of_subject(string student, string subject) {
        vector<int> grades;
        for (auto& e : entries) {
            if (e.student == student && e.subject == subject) {
                grades.push_back(e.grade);
            }
        }
        if (grades.size() != 0) {
            cout << "Средний балл студента " << student << " по предмету " << subject << " = " << reduce(grades.begin(), grades.end()) / grades.size() << endl;
        }
    }
    int get_students_count() {
        return students.size();
    }
    int get_grade_for_subject_count(string subject) {
        int counter = 0;
        for (auto& e : entries) {
            if (e.subject == subject) {
                ++counter;
            }
        }
        return counter;
    }
};

int main()
{
    Attestation attestation;
    attestation.add_student("Артем");
    attestation.add_student("Юля");
    attestation.add_subject("География");
    attestation.add_subject("Математика");

    attestation.add_mark_grade(4, "Артем", "География");
    attestation.add_mark_grade(5, "Юля", "География");
    attestation.add_mark_grade(3, "Юля", "Математика");

    attestation.average_grade_for_student("Юля");
    attestation.average_grade_for_student_of_subject("Юля", "География");

    return 0;
}
