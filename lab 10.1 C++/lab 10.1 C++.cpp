#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int CountCommaDash(const char* s)
{
    int k = 0;
    int pos = 0;
    const char* t;

    while ((t = strstr(s + pos, ",")) != nullptr)
    {
        // ��������, �� ���� ���� ��� ����
        if (*(t + 1) == '-')
        {
            k++;
        }
        pos = t - s + 1;
    }

    return k;
}

int main()
{
    // ³������� ����� ��� �������
    ifstream inputFile("t.txt.txt");

    // ��������, �� ���� ������� �������
    if (!inputFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1; // ������� �������� �����
    }

    char str[101];
    int totalCount = 0; // �������� ������� ��������� ���������

    // ������� ��� ����� � �����
    while (inputFile.getline(str, 100))
    {
        totalCount += CountCommaDash(str);
    }

    // ���� ������� ��������� ���������
    cout << "File contains " << totalCount << " occurrences of ', -'" << endl;

    // �������� �����
    inputFile.close();

    return 0;
}
