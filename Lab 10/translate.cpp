#define _CRT_SECURE_NO_WARNINGS

#include "translate.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

/*
По символьным файлам с текстом (содержащим сокращения) и с сокращениями создать новый файл,
где все сокращения заменены на соответствующие слова.
ДОП:
- составление списка замен в отдельный файл(строка, позиция, сокращение, которое было заменено)
- возможность подключить несколько словарей
*/


typedef struct {
    char* word;
    char* reduced;
} Token;

char** expandWords(char** words, size_t size, size_t* newSize) {
    *newSize = size * 2;
    char** temp = new char* [*newSize];
    for (size_t i = 0; i < size; i++) {
        temp[i] = words[i];
    }
    delete[] words;
    return temp;
}

Token** expandTokens(Token** tokens, size_t size, size_t* newSize) {
    *newSize = size * 2;
    Token** temp = new Token * [*newSize];
    for (size_t i = 0; i < size; i++) {
        temp[i] = tokens[i];
    }
    delete[] tokens;
    return temp;
}

void clearTokens(Token** tokens, size_t size) {
    for (size_t i = 0; i < size; i++) {
        delete tokens[i];
    }
    delete[] tokens;
}

char* newStr(const char* str) {
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    return temp;
}

Token* readToken(ifstream& in) {
    char buff[500];
    in.getline(buff, 500, '\n');
    Token* token = new Token;
    token->reduced = newStr(strtok(buff, " "));
    token->word = newStr(buff + strlen(token->reduced) + 1);
    return token;
}

Token** readAllTokens(const char** patchs, int size, size_t* newSize) {
    size_t tIdx = 0, tSize = 10;
    Token** tokens = new Token * [tSize];

    for (int i = 0; i < size; i++) {//----------------
        ifstream in;//----------------
        in.open(patchs[i]);//----------------

        if (in.is_open())
        {
            while (!in.eof()) {
                Token* token = readToken(in);
                if (tIdx >= tSize) {
                    tokens = expandTokens(tokens, tSize, &tSize);
                }
                tokens[tIdx++] = token;
            }
        }
        else {
            cout << "File not opened!!!" << endl;
        }

        in.close();
    }

    *newSize = tIdx; // обновляем кол-во возможных сокращений 
    return tokens;
}

void clearBuff(char* buff, size_t size) {
    for (size_t i = 0; i < size; i++) {
        buff[i] = '\0';
    }
}

char* changeIfReduced(char* word, Token** tokens, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(word, tokens[i]->reduced) == 0) {
            return tokens[i]->word;
        }
    }
    return word;
}

char** replaceWords(int row, ofstream& log, char* line, size_t* newSize, Token** tokens, size_t size) {

    size_t wSize = 10, wIdx = 0;
    char** words = new char* [wSize];
    char* pch = strtok(line, " \t");

    int pos = 0;

    while (pch != nullptr) {
        if (wIdx >= wSize) {
            words = expandWords(words, wSize, &wSize);
        }
        words[wIdx++] = changeIfReduced(pch, tokens, size);
        // слово поменялось
        if (pch != words[wIdx - 1]) {
            log << "строка: " << row + 1 << " позиция: " << pos << " замена: " << pch << '-' << words[wIdx - 1] << endl;
        }
        pch = strtok(nullptr, " \t");
        pos++;
    }
    *newSize = wIdx;
    return words;
}

void start() {
    
    size_t tSize = 0;
    const char* patch[2] = { "tokens.txt", "tokens2.txt" };
    Token** tokens = readAllTokens(patch, 2, &tSize);

    ifstream textIn;
    textIn.open("text.txt");

    ofstream out;
    out.open("ans.txt");

    ofstream log;
    log.open("log.txt");

    if (out.is_open() && textIn.is_open()) {
        char buff[405];
        int row = 0;
        while (textIn.getline(buff, 400, '\n')) {
            size_t size = 0;
            char** words = replaceWords(row++, log, buff, &size, tokens, tSize);
            for (size_t i = 0; i < size; i++) {
                out << words[i] << " ";
            }
            clearBuff(buff, 405);
            delete[] words;
            out << endl;
        }
    }
    else {
        cout << "File not opened!!!" << endl;
    }
}