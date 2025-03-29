#include <iostream>
#include <fstream>

const int MAX_LINE = 255; // Максимальная длина строки

// Функция для формирования файла
void createFile(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при создании файла " << filename << std::endl;
        return;
    }
    file << "Hello world\n";
    file << "SingleWord\n";
    file << "Another line with multiple words\n";
    file << "OneWord\n";
    file << "Two words here\n";
    file << "JustOne\n";
    file << "Multiple words again\n";
    file << "Single\n";
    file << "Last line with one word\n";
    file << "End\n";
    file.close();
    std::cout << "Файл " << filename << " успешно создан.\n";
}

// Функция для печати файла
void printFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла " << filename << std::endl;
        return;
    }
    char line[MAX_LINE];
    std::cout << "Содержимое файла " << filename << ":\n";
    while (file.getline(line, MAX_LINE)) {
        std::cout << line << std::endl;
    }
    file.close();
}

// Функция для копирования строк с одним словом
void copySingleWordLines(const char* source, const char* destination) {
    std::ifstream srcFile(source);
    std::ofstream destFile(destination);
    if (!srcFile.is_open() || !destFile.is_open()) {
        std::cerr << "Ошибка при работе с файлами\n";
        if (srcFile.is_open()) srcFile.close();
        if (destFile.is_open()) destFile.close();
        return;
    }
    char line[MAX_LINE];
    while (srcFile.getline(line, MAX_LINE)) {
        char temp[MAX_LINE];
        strcpy_s(temp, MAX_LINE, line); // Используем strcpy_s вместо strcpy
        char* context = nullptr;
        char* token = strtok_s(temp, " \t", &context); // Используем strtok_s вместо strtok
        int wordCount = 0;
        while (token != nullptr) {
            wordCount++;
            token = strtok_s(nullptr, " \t", &context);
        }
        if (wordCount == 1) {
            destFile << line << std::endl;
        }
    }
    srcFile.close();
    destFile.close();
    std::cout << "Строки с одним словом скопированы из " << source << " в " << destination << "\n";
}

// Функция для нахождения самого длинного слова
void findLongestWord(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла " << filename << std::endl;
        return;
    }
    char longestWord[MAX_LINE] = "";
    size_t maxLength = 0;
    char line[MAX_LINE];
    while (file.getline(line, MAX_LINE)) {
        size_t length = std::strlen(line);
        if (length > maxLength) {
            maxLength = length;
            strcpy_s(longestWord, MAX_LINE, line); // Используем strcpy_s вместо strcpy
        }
    }
    file.close();
    if (maxLength > 0) {
        std::cout << "Самое длинное слово в файле " << filename << ": " << longestWord
            << " (длина: " << maxLength << ")\n";
    }
    else {
        std::cout << "Файл " << filename << " пуст.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    const char* f1 = "F1.txt";
    const char* f2 = "F2.txt";

    createFile(f1);              // Формирование файла F1.txt
    printFile(f1);               // Печать файла F1.txt
    copySingleWordLines(f1, f2); // Копирование строк с одним словом в F2.txt
    printFile(f2);               // Печать файла F2.txt
    findLongestWord(f2);         // Поиск самого длинного слова в F2.txt

    return 0;
}