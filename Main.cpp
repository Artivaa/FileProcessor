#include "FileProcessor.h"

// Точка входа в программу
int main()
{
    // Установка русской локали для корректного вывода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создание объекта обработчика файлов
    FileProcessor processor("F1.txt", "F2.txt");
    char longestWord[256];  // Буфер для хранения самого длинного слова

    processor.createInputFile();         // Создание файла F1
    processor.processLongestWord(longestWord);  // Обработка и поиск

    // Вывод результата
    std::cout << "Самое длинное слово из F2: " << longestWord << "\n";

    return 0;
}