#include "parser.h"
void check_variable_declaration(const std::vector<std::pair<std::string, std::string>>& tokens,int i)
{
    if (tokens.size() < 5 || tokens[i].second != "int" || tokens[i+1].first != "identifier" || tokens[i+2].second != "=" || tokens[i+3].first != "number" || tokens[i+4].second != ";")
    {
        throw std::invalid_argument("Invalid variable declaration syntax");
    }
}

void check_if_statement(const std::vector<std::pair<std::string, std::string>>& tokens,int i)//if(x=6){y=7;}else{y=7;}
{
    if (tokens.size() < 12 || tokens[i].second != "if" || tokens[i+1].second != "(" || tokens[i+2].first != "identifier" || tokens[i+3].second != "=" || tokens[i+4].first != "number" || tokens[i+5].second != ")" || tokens[i+6].second != "{" || tokens[i+7].first != "identifier"||tokens[i+8].second != "=" || tokens[i+9].first != "number"  || tokens[i+10].second != ";" || tokens[i+11].second != "}" )
    {
        throw std::invalid_argument("Invalid if statement syntax");
    }
}

void check_else_statement(const std::vector<std::pair<std::string, std::string>>& tokens,int i)//else{y=7;}
{
    if (tokens.size() < 5 || tokens[i].second != "else" || tokens[i+1].second != "{" || tokens[i+2].first != "identifier" ||tokens[i+3].second != "=" || tokens[i+4].first != "number" || tokens[i+5].second != ";" || tokens[i+6].second != "}")
    {
        throw std::invalid_argument("Invalid else statement syntax");
    }
}

void check_while_loop(const std::vector<std::pair<std::string, std::string>>& tokens,int i)//while(x<5){x++;}
{
    if (tokens.size() < 10 || tokens[i].second != "while" || tokens[i+1].second != "(" || tokens[i+2].first != "identifier" || tokens[i+3].second != "<" || tokens[i+4].first != "number" || tokens[i+5].second != ")" || tokens[i+6].second != "{" || tokens[i+7].first != "identifier" ||tokens[i+8].second != "+"|| tokens[i+9].second != "+"||tokens[i+10].second != ";" || tokens[i+11].second != "}")
    {
        throw std::invalid_argument("Invalid while loop syntax");
    }
}


void check_switch_statement(const std::vector<std::pair<std::string, std::string>>& tokens,int i)//switch(x){case 7:}
{
    if (tokens.size() < 5 || tokens[i].second != "switch" || tokens[i+1].second != "(" || tokens[i+2].first != "identifier" ||tokens[i+3].second != ")"||tokens[i+4].second != "{"||tokens[i+5].second != "case" ||  tokens[i+6].first != "number" || tokens[i+7].second != ":")
    {
        throw std::invalid_argument("Invalid switch statement syntax");
    }
}

void check_for_loop(const std::vector<std::pair<std::string, std::string>>& tokens,int i)//for( x=0 ; x<5 ;x++){x++;}
{
    if (tokens.size() < 12 || tokens[i].second != "for" || tokens[i+1].second != "(" || tokens[i+5].second != ";" || tokens[i+9].second != ";" ||tokens[i+13].second != ")"|| tokens[i+14].second != "{" || tokens[i+15].first != "identifier" ||tokens[i+16].second != "+"|| tokens[i+17].second != "+"||tokens[i+18].second != ";" || tokens[i+19].second != "}" )
    {
        throw std::invalid_argument("Invalid for loop syntax");
    }
}

void check_enum(const std::vector<std::pair<std::string, std::string>>& tokens,int i)//enum color{RED, GREEN, YELLOW};
{
    if (tokens.size() < 3 || tokens[i].second != "enum" || tokens[i+1].first != "identifier" || tokens[i+2].second != "{" || tokens[i+3].first != "identifier" ||tokens[i+4].second != ","|| tokens[i+5].first != "identifier" || tokens[i+6].second != "," ||tokens[i+7].first != "identifier"|| tokens[i+8].second != "}"||tokens[i+9].second != ";"  )
    {
        throw std::invalid_argument("Invalid for enum syntax");
    }
}

void parse(const std::vector<std::pair<std::string, std::string>>& tokens)
{
    size_t i = 0;
    try
    {
        while (i < tokens.size())
        {
            if (tokens[i].second == "int")
            {
                check_variable_declaration(tokens,i);

                i += 1;
                while (tokens[i].second != ";")
                {
                    i += 1;
                }
                if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }
            else if (tokens[i].second == "if")
            {
                check_if_statement(tokens,i);
                i += 1;
                while (tokens[i].second != "}")
                {
                    i += 1;
                }
                if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }
            else if (tokens[i].second == "else")
            {
                check_else_statement(tokens,i);
                i += 1;
                while (tokens[i].second != "}")
                {
                    i += 1;
                }
                if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }
            else if (tokens[i].second == "while")
            {
                check_while_loop(tokens,i);
                i += 1;
               while (tokens[i].second != "}")
                {
                    i += 1;
                }
                if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }
            else if (tokens[i].second == "switch")
            {
                check_switch_statement(tokens,i);
                i += 1;
                while (tokens[i].second != "}")
                {
                    if (tokens[i].second == "case")
                    {

                        // Handle case statement
                        i += 1; // Move past "CASE_KEYWORD"
                        while(tokens[i].second!="break"){
                                if(tokens[i].second != "}"){
                                    break;
                                }
                            i+=1;
                        }
                        i+=1;
                    }
                    else
                    {
                        i += 1;
                    }

                }

               if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }
            else if (tokens[i].second == "for")
            {
                check_for_loop(tokens,i);
                i += 1;
                while (tokens[i].second != "}")
                {
                    i += 1;
                }
                if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }else if (tokens[i].second == "enum")
            {
                check_enum(tokens,i);
                i += 1;
               while (tokens[i].second != ";")
                {
                    i += 1;
                }
                if(i==tokens.size()-1)
                {
                    cout<<" syntax is correct"<<endl;
                }
                i += 1;
            }
            else
            {
                std::cout << "Syntax Error: Unexpected token '" << tokens[i].second << "' at position " << i << "." << std::endl;
                i += 1;
            }
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Error: Incomplete statement at the end of the input." << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Syntax Error: " << e.what() << std::endl;
    }
}

void parser_start()
{
    std::string input_file_path = "tokens.txt";
    try
    {
        std::ifstream input_file(input_file_path);
        if (!input_file.is_open())
        {
            throw std::invalid_argument("File not found");
        }

        std::vector<std::pair<std::string, std::string>> input_tokens;
        std::string line;
        while (std::getline(input_file, line))
        {
            size_t pos = line.find(": ");
            if (pos != std::string::npos)
            {
                std::string type = line.substr(0, pos);
                std::string value = line.substr(pos + 2); //while
                input_tokens.emplace_back(type, value);
            }
        }
        input_file.close();

       /* for(int i=0;i<input_tokens.size();i++) {
               std::cout <<i<<" "  <<input_tokens[i].first << ": " <<input_tokens[i].second << std::endl;
           }*/
        parse(input_tokens);




    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return ;
    }
    return;
}
