#include <stdio.h>
#include <iostream>
typedef enum
{
    // palavras reservadas
    ARRAY,
    BOOLEAN,
    BREAK,
    CHAR,
    CONTINUE,
    DO,
    ELSE,
    FALSE,
    FUNCTION,
    IF,
    INTEGER,
    OF,
    STRING,
    STRUCT,
    TRUE,
    TYPE,
    VAR,
    WHILE,
    // simbolos
    COLON,
    SEMI_COLON,
    COMMA,
    EQUALS,
    LEFT_SQUARE,
    RIGHT_SQUARE,
    LEFT_BRACES,
    RIGHT_BRACES,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    AND,
    OR,
    LESS_THAN,
    GREATER_THAN,
    LESS_OR_EQUAL,
    GREATER_OR_EQUAL,
    NOT_EQUAL,
    EQUAL_EQUAL,
    PLUS,
    PLUS_PLUS,
    MINUS,
    MINUS_MINUS,
    TIMES,
    DIVIDE,
    DOT,
    NOT,
    // tokens regulares
    CHARACTER,
    NUMERAL,
    STRINGVAL,
    ID,
    // token deconhecido
    UNKNOWN
} t_token;

t_token searchKeyWord(char *name);
char readChar(void);
t_token nextToken(void);
t_token token;
int tokenSecundario;
char nextChar = '\x20';
int searchName(char *name);

typedef struct
{
    byte type; // 0-char, 1-int, 2- string
    union
    {
        char cVal;
        int nVal;
        char *sVal;
    } _;
} t_const;

t_token nextToken(void)
{
    // loop do estado inicial para pular os separadores
    while (isspace(nextChar))
    {
        nextChar = readChar();
    }
    if (isalpha(nextChar))
    {
        char text[MAX_ID_LEN + 1];
        int i = 0;
        do
        {
            text[i++] = nextchar;
            nextChar = readChar();
        } while (isalnum(nextChar) || nextChar == '_');
        text[i] = '\0';
        token = searchKeyWord(text);
        if (token == ID)
        {
            tokenSecundario = searchName(text);
        }
    }
    else if (isdigit(nextChar))
    {
        char numeral[MAX_NUM_LEN + 1];
        int i = 0;
        do
        {
            numeral[i++] = nextchar;
            nextChar = readChar();
        } while (isdigit(nextChar));
        numeral[i] = '\0';
        token = NUMERAL;
        tokenSecundario = addIntConst(numeral);
    }
    else
    {
        if (nextChar == '”')
        {
            char string[MAX_STR_LEN + 1];
            int i = 1;
            do
            {
                string[i++] = nextchar;
                nextChar = readChar();
            } while (nextChar != '”');
            numeral[i++] = '”';
            numeral[i] = '\0';
            token = STRING;
            tokenSecundario = addStringConst(numeral);
        }
        else
            switch (ch)
            {
            case '\'':
                nextChar = readChar();
                token = CHARACTER;
                tokenSecundario = addCharConst(nectChar);
                nextChar = readChar(); // pular o '
                nextChar = readChar();
                break;
            case ':':
                nextChar = readChar();
                token = COLON;
                break;
            case '+':
                nextChar = readChar();
                if (nextChar == '+')
                {
                    token = PLUS_PLUS;
                    nextChar = readChar();
                }
                else
                {
                    token = PLUS;
                }
                break;
                ... default : token = UNKNOWN;
            }
        return token;
    }
}
