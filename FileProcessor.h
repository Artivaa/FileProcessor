#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <windows.h>

// Класс для обработки файлов и поиска самого длинного слова
class FileProcessor
{
private:
    char inputFileName[256];    // Имя входного файла (F1)
    char outputFileName[256];   // Имя выходного файла (F2)

    // Проверяет, содержит ли строка только одно слово
    bool hasSingleWord(const char* line);

    // Находит самое длинное слово в выходном файле
    void findLongestWord(char* result);

public:
    // Конструктор, принимающий имена входного и выходного файлов
    FileProcessor(const char* input, const char* output);

    // Создает входной файл с 10 строками текста
    void createInputFile();

    // Копирует строки с одним словом из F1 в F2
    void copySingleWordLines();

    // Выполняет полную обработку и возвращает самое длинное слово
    void processLongestWord(char* result);
};

#endif
