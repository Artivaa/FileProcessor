#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <windows.h>

// ����� ��� ��������� ������ � ������ ������ �������� �����
class FileProcessor
{
private:
    char inputFileName[256];    // ��� �������� ����� (F1)
    char outputFileName[256];   // ��� ��������� ����� (F2)

    // ���������, �������� �� ������ ������ ���� �����
    bool hasSingleWord(const char* line);

    // ������� ����� ������� ����� � �������� �����
    void findLongestWord(char* result);

public:
    // �����������, ����������� ����� �������� � ��������� ������
    FileProcessor(const char* input, const char* output);

    // ������� ������� ���� � 10 �������� ������
    void createInputFile();

    // �������� ������ � ����� ������ �� F1 � F2
    void copySingleWordLines();

    // ��������� ������ ��������� � ���������� ����� ������� �����
    void processLongestWord(char* result);
};

#endif
