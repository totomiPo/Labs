#ifndef LAB_11
#define LAB_11

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char* find_keyword(char* line);
int equal(const char* a, const char* b);
char* get_string(FILE* txt);
void print_keyword(char* keyword, ofstream& fout);
void print_all_keywords(FILE* txt, ofstream& fout);

#endif


