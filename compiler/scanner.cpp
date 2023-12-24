
#include"scanner.h"


int is_operator(char ch){
    if(ch == '+' || ch == '-' || ch == '='|| ch == '*' || ch == '/' || ch == '<' || ch == '>'){
       return 1;
    }
    return 0;
}
int is_delimeter(char ch){
    if(ch == '+' || ch == '-' || ch == '='|| ch == '*' || ch == '/' || ch == '<' || ch == '>' ||
       ch == ' ' || ch == ',' || ch == ';'|| ch == '*' || ch == '(' || ch == ')' || ch == '[' ||
       ch == ']' || ch == '{' || ch == '}'|| ch == ':')
    {
       return 1;
    }
    return 0;
}
int is_special_char(char ch){
    if(ch == ':' || ch == '#' || ch == '$'|| ch == '%' || ch == '/' || ch == '<' || ch == '>' ||
       ch == '!' || ch == ',' || ch == ';'|| ch == '*' || ch == '(' || ch == ')' || ch == '[' ||
       ch == ']' || ch == '{' || ch == '}'|| ch == '&')
    {
       return 1;
    }
    return 0;
}
int is_identifier(string s){
    if (s[0]=='0'||s[0]=='1'||s[0]=='2'||s[0]=='3'||s[0]=='4'||s[0]=='5'||s[0]=='6'||s[0]=='7'||
        s[0]=='8'||s[0]=='9'||is_delimeter(s[0]==1))
    {
        return 0;
    }
    return 1;
}
int is_keyword(string s){
    if (s == "auto"||      s == "double"||    s == "long"||      s == "switch"||
        s == "case"||      s == "enum"||      s == "register"||  s == "typedef"||
        s == "char"||      s == "extern"||    s == "return"||    s == "union"||
        s == "const"||     s == "float"||     s == "short"||     s == "unsigned"||
        s == "continue"||  s == "for"||       s == "signed"||    s == "void"||
        s == "default"||   s == "goto"||      s == "sizeof"||    s == "volatile"||
        s == "do"||        s == "if"||        s == "static"||    s == "while"||    s == "int"||s=="break")
    {
       return 1;
    }
    return 0;
}
int is_number(string s){
    int len = s.length();
    int dot_counter=0;
    if (len == 0)
    {
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if ((s[i]!='0'   &&s[i]!='1'   &&s[i]!='2'   &&s[i]!='3'   &&s[i]!='4'   &&s[i]!='5'&&
            s[i]!='6'   &&s[i]!='7'   &&s[i]!='8'   &&s[i]!='9'    &&s[i]!='.')   &&  (s[i]!='-' || i>0))
        {
            return 0;
        }
        if (s[i]=='.')
        {
            dot_counter++;
        }
    }
    if (dot_counter>1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int tokenizer(string *s){
    int left=0, right=0, len=s->length(), range=0;
    char ch;
    ofstream outfile("tokens.txt");
    while (right<=len && left<=right)
    {
        ch = (*s)[right];
        if (is_delimeter(ch)==0)
        {
            right++;
        }
        if (is_delimeter(ch)==1 && left==right)
        {
            if (is_operator(ch)==1)
            {
                outfile<<"operator: "<<(*s)[right]<<endl;
            }
            else if (is_special_char(ch)==1)
            {
                outfile<<"special character: "<<(*s)[right]<<endl;
            }
            right++;
            left=right;
        }
        else if (is_delimeter(ch)==1 && left!=right || (right==len && left!=right))
        {
            range = right-left;
            string substr = s->substr(left,range);
            if (is_keyword(substr))
            {
                outfile<<"keyword: "<<substr<<endl;
            }
            else if (is_number(substr))
            {
                outfile<<"number: "<<substr<<endl;
            }
            else if (is_identifier(substr)==1 && is_delimeter((*s)[right-1])==0)
            {
                outfile<<"identifier: "<<substr<<endl;
            }
            else if (is_identifier(substr)==0 && is_delimeter((*s)[right-1])==0)
            {
                outfile<<"not identifier: "<<substr<<endl;
            }
            left = right;
        }
    }
}
