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
        // Перевірка, чи після коми йде тире
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
    // Відкриття файлу для читання
    ifstream inputFile("t.txt.txt");

    // Перевірка, чи файл вдалося відкрити
    if (!inputFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1; // Помилка відкриття файлу
    }

    char str[101];
    int totalCount = 0; // Загальна кількість знайдених комбінацій

    // Читання всіх рядків з файлу
    while (inputFile.getline(str, 100))
    {
        totalCount += CountCommaDash(str);
    }

    // Вивід кількості знайдених комбінацій
    cout << "File contains " << totalCount << " occurrences of ', -'" << endl;

    // Закриття файлу
    inputFile.close();

    return 0;
}
