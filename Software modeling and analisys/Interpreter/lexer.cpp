#include "lexer.h"

Lexer::Lexer()
{

}

QString Lexer::BREAK_DOWN(QString data){
    QString input = data, output = "";

    auto lines = input.split('\n',QString::SplitBehavior::SkipEmptyParts);
    tokens = new  QVector<QVector<Token*>>;
    tokens->resize(lines.size());

    for (int i = 0; i < lines.size(); ++i) {
        auto a_line = lines[i].split(" ",QString::SplitBehavior::SkipEmptyParts);
        for (int word = 0;word < a_line.size();++word){
            (*tokens)[i].push_back( new Token(a_line[word]));
            output.append("< "+ (*tokens)[i][word]->tag + " ; " + (*tokens)[i][word]->value + " >\n");
        }
    }

    return output;

}
