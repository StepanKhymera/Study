#include "token.h"


static QList<QString> keywords = {"if","while","tag"};

static QList<QString> functions = {"open","find_all","find_f"};

Token::Token(QString lexem)
{
    value = lexem;

    if(isdigit(lexem[0].toLatin1())){
        tag = "integer";
        return;
    }

    if(isalpha(lexem[0].toLatin1())){
        if(keywords.contains(lexem)){
            tag = "keyword";
            return;
        }
        if(functions.contains(lexem)){
            tag = "functions";
            return;
        }

        tag = "identifier";
        return;
    }


    switch (lexem[0].toLatin1()) {
    case('<'):{
        tag = "HTML_tag";
        return;
    }
    case('\"'):{
        tag = "dquotes";
        return;
    }
    case(','):{
        tag = "coma";
        return;
    }
    case('='):{
        tag = "is_equall";
        return;
    }
    case('('):{
        tag = "open_par";
        return;
    }
    case(')'):{
        tag = "closed_par";
        return;
    }
    case('{'):{
        tag = "open_curl";
        return;
    }
    case('}'):{
        tag = "closed_curl";
        return;
    }
    }


}
