#include "mylab.h"


char* find_keyword(char* line) {
	char keywords[47][11] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
	"_asm", "_cdecl", "_declspec", "_except", "_fastcall", "enum", "extern", "float", "for",
	"goto", "if", "int", "inline", "switch", "long", "register", "_finally", "_inline", "_leave",
	"_stdcall", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "typedef",
	"union", "_try", "_declspec", "unsigned", "void", "while", "_Bool", "_Complex", "_Imaginary" };

	for (int i = 0; line[i] != EOF && line[i] != '\n'; i++) if (i == 0 || line[i - 1] == ' ' || line[i - 1] == '\t') {
		for (int j = 0; j != 47; j++) if (equal(&line[i], keywords[j]))
			return &line[i];
	}
	return NULL;
}

int equal(const char* a, const char* b) {
	int i;
	for (i = 0; a[i] != '\0' && a[i] != EOF && a[i] != '\n' && b[i] != '\0' && b[i] != EOF && b[i] != '\n'; i++) if (a[i] != b[i])
		return 0;
	if ((a[i] == ' ' || a[i] == '\t' || a[i] == EOF || a[i] == '\n') && b[i] == '\0' || (b[i] == ' ' || b[i] == '\t' || b[i] == EOF || b[i] == '\n') && a[i] == '\0')
		return 1;
	return 0;
}

void print_keyword(char* keyword, ofstream& fout) {
	for (int i = 0; keyword[i] != ' ' && keyword[i] != '\t' && keyword[i] != EOF && keyword[i] != '\n'; i++)
		fout << keyword[i];
}

char* get_string(FILE* txt) {
	char* str = new char[10];
	static char c;
	static FILE* file = txt;
	int size = 0, capacity = 10;
	if (c == EOF && file == txt) return NULL;
	// аргумент новый файл
	file = txt;
	do {
		c = getc(txt);
		if (size == capacity) {
			capacity *= 2;
			str = (char*)realloc(str, capacity * sizeof(char));
		}
		str[size] = c;
		size++;
	} while (c != '\n' && c != EOF);
	return str;
}

void print_all_keywords(FILE* txt, ofstream& fout) {
	char* str, * keyword;
	for (int i = 1; (str = get_string(txt)) != NULL; i++) {
		if (find_keyword(str) != NULL)
			fout << "line " << i << ":\n";
		keyword = str - 1;
		while ((keyword = find_keyword(keyword + 1)) != NULL) {
			fout << keyword - str + 1 << " - ";
			print_keyword(keyword, fout);
			fout << '\n';
		}
		delete[] str;
	}
}