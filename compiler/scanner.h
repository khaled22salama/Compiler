


#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int is_operator(char ch);
int is_delimeter(char ch);
int is_special_char(char ch);
int is_identifier(string s);
int is_keyword(string s);
int is_number(string s);
int tokenizer(string *s);
#endif // SCANNER_H_INCLUDED
