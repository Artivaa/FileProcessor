#include "FileProcessor.h"

// Конструктор: инициализирует имена файлов
FileProcessor::FileProcessor(const char* input, const char* output)
{
    // Безопасное копирование строк с учетом размера буфера
    strcpy_s(inputFileName, input);
    strcpy_s(outputFileName, output);
}

// Создание входного файла F1 с заранее заданным содержимым
void FileProcessor::createInputFile()
{
    std::ofstream outFile(inputFileName);
    if (outFile.is_open())
    {
        // Запись 10 строк текста, некоторые из которых содержат одно слово
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
bool FileProcessor::hasSingleWord(const char* line)
{
    int spaceCount = 0;
    // Подсчет пробелов в строке
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ' ')
        {
            spaceCount++;
        }
    }
    // Если пробелов нет, значит слово одно
    return spaceCount == 0;
}

// Копирование строк с одним словом из F1 в F2
void FileProcessor::copySingleWordLines()
{
    std::ifstream inFile(inputFileName);    // Открытие входного файла
    std::ofstream outFile(outputFileName);  // Открытие выходного файла

    if (inFile.is_open() && outFile.is_open())
    {
        char line[256]; // Буфер для чтения строк
        // Построчное чтение файла F1
        while (inFile.getline(line, 256))
        {
            if (hasSingleWord(line))
            {
                // Запись строки в F2, если она содержит одно слово
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
void FileProcessor::findLongestWord(char* result)
{
    std::ifstream inFile(outputFileName);   // Открытие файла F2
    char currentWord[256] = "";             // Текущее слово
    result[0] = '\0';                       // Инициализация результата пустой строкой

    if (inFile.is_open())
    {
        // Чтение всех строк из F2
        while (inFile.getline(currentWord, 256))
        {
            // Сравнение длины текущего слова с уже найденным
            if (strlen(currentWord) > strlen(result))
            {
                // Обновление результата, если текущее слово длиннее
                strcpy_s(result, 256, currentWord);
            }
        }
        inFile.close();
    }
}

// Основная функция обработки: копирование и поиск
void FileProcessor::processLongestWord(char* result)
{
    copySingleWordLines();  // Сначала копируем строки
    findLongestWord(result); // Затем ищем самое длинное слово
}