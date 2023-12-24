#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

void check_variable_declaration(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void check_if_statement(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void check_else_statement(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void check_while_loop(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void check_switch_statement(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void check_for_loop(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void check_enum(const std::vector<std::pair<std::string, std::string>>& tokens,int i);
void parse(const std::vector<std::pair<std::string, std::string>>& tokens);
void parser_start();
#endif // PARSER_H_INCLUDED
