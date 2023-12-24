/*
أسامة السيد محمدى جبر
أيمن رجب عبد الواحد حمود
خالد عبد الحميد رشاد سلامة
محمد أحمد السيد الفقى
*/
#include <iostream>
#include <string>
#include <fstream>
#include "scanner.h"
#include"parser.h"
using namespace std;



int main()
{
    string s;
    cout<<"Enter the statement: ";
    getline(std::cin, s);
    tokenizer(&s);

    parser_start();

}
