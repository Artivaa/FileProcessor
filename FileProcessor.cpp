#include "FileProcessor.h"

// �����������: �������������� ����� ������
FileProcessor::FileProcessor(const char* input, const char* output)
{
    // ���������� ����������� ����� � ������ ������� ������
    strcpy_s(inputFileName, input);
    strcpy_s(outputFileName, output);
}

// �������� �������� ����� F1 � ������� �������� ����������
void FileProcessor::createInputFile()
{
    std::ofstream outFile(inputFileName);
    if (outFile.is_open())
    {
        // ������ 10 ����� ������, ��������� �� ������� �������� ���� �����
        outFile << "������\n";
        outFile << "��� ����������������\n";
        outFile << "������\n";
        outFile << "������ ������ ����\n";
        outFile << "����\n";
        outFile << "������ ������ ��������\n";
        outFile << "������\n";
        outFile << "����� ���� �����\n";
        outFile << "����\n";
        outFile << "���� ����� �������������\n";
        outFile.close();
    }
    else
    {
        std::cout << "�� ������� ������� ������� ����\n";
    }
}

// �������� ������ �� ������� ������������� �����
bool FileProcessor::hasSingleWord(const char* line)
{
    int spaceCount = 0;
    // ������� �������� � ������
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ' ')
        {
            spaceCount++;
        }
    }
    // ���� �������� ���, ������ ����� ����
    return spaceCount == 0;
}

// ����������� ����� � ����� ������ �� F1 � F2
void FileProcessor::copySingleWordLines()
{
    std::ifstream inFile(inputFileName);    // �������� �������� �����
    std::ofstream outFile(outputFileName);  // �������� ��������� �����

    if (inFile.is_open() && outFile.is_open())
    {
        char line[256]; // ����� ��� ������ �����
        // ���������� ������ ����� F1
        while (inFile.getline(line, 256))
        {
            if (hasSingleWord(line))
            {
                // ������ ������ � F2, ���� ��� �������� ���� �����
                outFile << line << "\n";
            }
        }
        inFile.close();
        outFile.close();
    }
    else
    {
        std::cout << "������ ��� �������� ������\n";
    }
}

// ����� ������ �������� ����� � ����� F2
void FileProcessor::findLongestWord(char* result)
{
    std::ifstream inFile(outputFileName);   // �������� ����� F2
    char currentWord[256] = "";             // ������� �����
    result[0] = '\0';                       // ������������� ���������� ������ �������

    if (inFile.is_open())
    {
        // ������ ���� ����� �� F2
        while (inFile.getline(currentWord, 256))
        {
            // ��������� ����� �������� ����� � ��� ���������
            if (strlen(currentWord) > strlen(result))
            {
                // ���������� ����������, ���� ������� ����� �������
                strcpy_s(result, 256, currentWord);
            }
        }
        inFile.close();
    }
}

// �������� ������� ���������: ����������� � �����
void FileProcessor::processLongestWord(char* result)
{
    copySingleWordLines();  // ������� �������� ������
    findLongestWord(result); // ����� ���� ����� ������� �����
}