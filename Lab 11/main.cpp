#include "mylab.h"
/*
1)НЕ ДОП:
для всех строк!
2)ДОП:
создавать файл, содержащий список следующего вида:
имя файла
строка позиция в строке найденное ключевое слово
/все ключевые слова в форме таких записей/
имя файла
/все ключевые слова этого файла в форме таких записей/


ВАЖНО: в строке ищутся ВСЕ ключевые слова
На вход поступает несколько(хотя бы два файла, но желательно организовать как "введите количество файлов" + ввод имен файлов)
выходной файл(имя) вводится пользователем

*/

int main() {
    int files_num;
    char file_names[100][100];
    char output_file[100];
    FILE* file;
    cout << "Enter num of files:";
    if (!(cin >> files_num) ) {
        cout << "Incorrect";
        return -1;
    }
    for (int i = 0; i != files_num; i++) {
        cout << "Enter name of file " << i + 1 << ":";
        cin >> file_names[i];
        if ((file = fopen(file_names[i], "r")) == NULL) {
            cout << "Incorrect";
            return -2;
        }
        fclose(file);
    }
    cout << "Enter name of output file:";
    cin >> output_file;
    if ((file = fopen(output_file, "w")) == NULL) {
        cout << "Incorrect";
        return -1;
    }
    fclose(file);

    ofstream fout;
    fout.open(output_file);
    for (int i = 0; i != files_num; i++) {
        fout << file_names[i] << ":\n";
        print_all_keywords(fopen(file_names[i], "r"), fout);
        fout << '\n';
    }
    fout.close();

    return 0;
}