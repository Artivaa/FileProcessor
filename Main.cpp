#include <iostream>
#include <fstream>
#include <windows.h>

// Функция для безопасного копирования строк
void safeStrCopy(char* dest, const char* src, size_t size)
{
    strcpy_s(dest, size, src);
}

// Создание входного файла F1 с заранее заданным содержимым
void createInputFile(const char* inputFileName)
{
    std::ofstream outFile(inputFileName);
    if (outFile.is_open())
    {
        outFile << "Привет\n";
        outFile << "Мир программирования\n";
        outFile << "Солнце\n";
        outFile << "Звезды светят ярко\n";
        outFile << "Луна\n";
        outFile << "Облака плывут медленно\n";
        outFile << "Дерево\n";
        outFile << "Птицы поют утром\n";
        outFile << "Река\n";
        outFile << "Горы стоят величественно\n";
        outFile.close();
    }
    else
    {
        std::cout << "Не удалось создать входной файл\n";
    }
}

// Проверка строки на наличие единственного слова
bool hasSingleWord(const char* line)
{
    int spaceCount = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ' ')
        {
            spaceCount++;
        }
    }
    return spaceCount == 0;
}

// Копирование строк с одним словом из F1 в F2
void copySingleWordLines(const char* inputFileName, const char* outputFileName)
{
    std::ifstream inFile(inputFileName);
    std::ofstream outFile(outputFileName);

    if (inFile.is_open() && outFile.is_open())
    {
        char line[256];
        while (inFile.getline(line, 256))
        {
            if (hasSingleWord(line))
            {
                outFile << line << "\n";
            }
        }
        inFile.close();
        outFile.close();
    }
    else
    {
        std::cout << "Ошибка при открытии файлов\n";
    }
}

// Поиск самого длинного слова в файле F2
void findLongestWord(const char* outputFileName, char* result)
{
    std::ifstream inFile(outputFileName);
    char currentWord[256] = "";
    result[0] = '\0';

    if (inFile.is_open())
    {
        while (inFile.getline(currentWord, 256))
        {
            if (strlen(currentWord) > strlen(result))
            {
                strcpy_s(result, 256, currentWord);
            }
        }
        inFile.close();
    }
}

// Основная функция обработки: копирование и поиск
void processLongestWord(const char* inputFileName, const char* outputFileName, char* result)
{
    copySingleWordLines(inputFileName, outputFileName);
    findLongestWord(outputFileName, result);
}

// Точка входа в программу
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char inputFileName[256];
    char outputFileName[256];
    char longestWord[256];

    safeStrCopy(inputFileName, "F1.txt", 256);
    safeStrCopy(outputFileName, "F2.txt", 256);

    createInputFile(inputFileName);
    processLongestWord(inputFileName, outputFileName, longestWord);

    std::cout << "Самое длинное слово из F2: " << longestWord << "\n";

    return 0;
}