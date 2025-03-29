#include <iostream>
#include <fstream>

const int MAX_LINE = 255; // ������������ ����� ������

// ������� ��� ������������ �����
void createFile(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "������ ��� �������� ����� " << filename << std::endl;
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
    std::cout << "���� " << filename << " ������� ������.\n";
}

// ������� ��� ������ �����
void printFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "������ ��� �������� ����� " << filename << std::endl;
        return;
    }
    char line[MAX_LINE];
    std::cout << "���������� ����� " << filename << ":\n";
    while (file.getline(line, MAX_LINE)) {
        std::cout << line << std::endl;
    }
    file.close();
}

// ������� ��� ����������� ����� � ����� ������
void copySingleWordLines(const char* source, const char* destination) {
    std::ifstream srcFile(source);
    std::ofstream destFile(destination);
    if (!srcFile.is_open() || !destFile.is_open()) {
        std::cerr << "������ ��� ������ � �������\n";
        if (srcFile.is_open()) srcFile.close();
        if (destFile.is_open()) destFile.close();
        return;
    }
    char line[MAX_LINE];
    while (srcFile.getline(line, MAX_LINE)) {
        char temp[MAX_LINE];
        strcpy_s(temp, MAX_LINE, line); // ���������� strcpy_s ������ strcpy
        char* context = nullptr;
        char* token = strtok_s(temp, " \t", &context); // ���������� strtok_s ������ strtok
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
    std::cout << "������ � ����� ������ ����������� �� " << source << " � " << destination << "\n";
}

// ������� ��� ���������� ������ �������� �����
void findLongestWord(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "������ ��� �������� ����� " << filename << std::endl;
        return;
    }
    char longestWord[MAX_LINE] = "";
    size_t maxLength = 0;
    char line[MAX_LINE];
    while (file.getline(line, MAX_LINE)) {
        size_t length = std::strlen(line);
        if (length > maxLength) {
            maxLength = length;
            strcpy_s(longestWord, MAX_LINE, line); // ���������� strcpy_s ������ strcpy
        }
    }
    file.close();
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

    createFile(f1);              // ������������ ����� F1.txt
    printFile(f1);               // ������ ����� F1.txt
    copySingleWordLines(f1, f2); // ����������� ����� � ����� ������ � F2.txt
    printFile(f2);               // ������ ����� F2.txt
    findLongestWord(f2);         // ����� ������ �������� ����� � F2.txt

    return 0;
}