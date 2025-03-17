#include "FileProcessor.h"

// ����� ����� � ���������
int main()
{
    // ��������� ������� ������ ��� ����������� ������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // �������� ������� ����������� ������
    FileProcessor processor("F1.txt", "F2.txt");
    char longestWord[256];  // ����� ��� �������� ������ �������� �����

    processor.createInputFile();         // �������� ����� F1
    processor.processLongestWord(longestWord);  // ��������� � �����

    // ����� ����������
    std::cout << "����� ������� ����� �� F2: " << longestWord << "\n";

    return 0;
}