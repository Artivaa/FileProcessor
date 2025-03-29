#include <iostream>
#include <fstream>

const int MAX_LINE = 255;

// ����� ������� �������� �������� �����
template<typename TStream>
bool checkFileOpen(TStream& stream, const char* filename, const char* mode) {
    if (!stream.is_open()) {
        std::cerr << "������ ��� " << mode << " ����� " << filename << std::endl;
        return false;
    }
    return true;
}

// ������� ��� ������������ �����
void createFile(const char* filename) {
    std::ofstream file(filename);
    if (!checkFileOpen(file, filename, "��������")) return;

    file << "Hello world\n"
        << "SingleWord\n"
        << "Another line with multiple words\n"
        << "OneWord\n"
        << "Two words here\n"
        << "JustOne\n"
        << "Multiple words again\n"
        << "Single\n"
        << "Last line with one word\n"
        << "End\n";

    file.close();
    std::cout << "���� " << filename << " ������� ������.\n";
}

// ����� ������� ��������� �����
template<typename LineHandler>
void processEachLine(const char* filename, LineHandler handler) {
    std::ifstream file(filename);
    if (!checkFileOpen(file, filename, "��������")) return;

    char line[MAX_LINE];
    while (file.getline(line, MAX_LINE)) {
        handler(line);
    }
    file.close();
}

// ������� ��� ������ �����
void printFile(const char* filename) {
    std::cout << "���������� ����� " << filename << ":\n";
    processEachLine(filename, [](const char* line) {
        std::cout << line << std::endl;
        });
}

// ������� ��� �������� ���� � ������
int countWords(const char* line) {
    char temp[MAX_LINE];
    strcpy_s(temp, line);
    int count = 0;
    char* context = nullptr;
    char* token = strtok_s(temp, " \t", &context);

    while (token) {
        count++;
        token = strtok_s(nullptr, " \t", &context);
    }
    return count;
}

// ������� ��� ����������� ����� � ����� ������
void copySingleWordLines(const char* source, const char* destination) {
    std::ofstream destFile(destination);
    if (!checkFileOpen(destFile, destination, "��������")) return;

    processEachLine(source, [&](const char* line) {
        if (countWords(line) == 1) {
            destFile << line << "\n";
        }
        });

    destFile.close();
    std::cout << "������ � ����� ������ ����������� � " << destination << "\n";
}

// ����� ������� ��������� ����
template<typename WordHandler>
void processEachWord(const char* filename, WordHandler handler) {
    processEachLine(filename, [&](const char* line) {
        char temp[MAX_LINE];
        strcpy_s(temp, line);
        char* context = nullptr;
        char* token = strtok_s(temp, " \t", &context);

        while (token) {
            handler(token);
            token = strtok_s(nullptr, " \t", &context);
        }
        });
}

// ������� ��� ���������� ������ �������� �����
void findLongestWord(const char* filename) {
    char longestWord[MAX_LINE] = "";
    size_t maxLength = 0;

    processEachWord(filename, [&](const char* word) {
        const size_t length = strlen(word);
        if (length > maxLength) {
            maxLength = length;
            strcpy_s(longestWord, word);
        }
        });

    if (maxLength > 0) {
        std::cout << "����� ������� ����� � ����� " << filename << ": " << longestWord
            << " (�����: " << maxLength << ")\n";
    }
    else {
        std::cout << "���� " << filename << " ����.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    const char* f1 = "F1.txt";
    const char* f2 = "F2.txt";

    createFile(f1);
    printFile(f1);
    copySingleWordLines(f1, f2);
    printFile(f2);
    findLongestWord(f2);

    return 0;
}