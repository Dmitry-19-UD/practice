#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для проверки пробелов после знаков препинания
void checkPunctuationSpaces(const string& str) {
    const string punctuation = ".,!?;:"; // Знаки препинания для проверки
    for (size_t i = 0; i < str.length() - 1; ++i) {
        if (punctuation.find(str[i]) != string::npos && str[i+1] != ' ') {
            cout << "Ошибка: после '" << str[i] << "' нет пробела!" << endl;
        }
    }
}

// Функция для создания словаря из текста
vector<string> createDictionary(const string& text) {
    vector<string> words;
    vector<string> dictionary;
    string currentWord;

    // Разбиваем текст на слова
    for (char ch : text) {
        if (ch == ' ' || ch == '.') {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        } else {
            currentWord += ch;
        }
    }
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }

    // Удаляем дубликаты
    for (const string& word : words) {
        if (find(dictionary.begin(), dictionary.end(), word) == dictionary.end()) {
            dictionary.push_back(word);
        }
    }

    return dictionary;
}

int main() {
    // Чтение из файла F1
    ifstream fin("F1.txt");
    if (!fin) {
        cerr << "Не удалось открыть файл F1.txt" << endl;
        return 1;
    }

    string line;
    string fullText;
    while (getline(fin, line)) {
        fullText += line + " ";
        checkPunctuationSpaces(line);
    }
    fin.close();

    // Создание словаря
    vector<string> dictionary = createDictionary(fullText);

    // Запись в файл F2
    ofstream fout("F2.txt");
    if (!fout) {
        cerr << "Не удалось открыть файл F2.txt" << endl;
        return 1;
    }

    for (const string& word : dictionary) {
        fout << word << endl;
    }
    fout.close();

    cout << "Словарь успешно создан в файле F2.txt" << endl;

    return 0;
}