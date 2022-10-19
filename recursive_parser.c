#include <stdio.h>
#include <stdlib.h>

#define wordsize 5012

// Functions
void lex();
void error(char missing_item);
int S();
int NGM();
int C();
int E();
int X();

// Global variables
char token;
char word[wordsize];
int topword = -1;

int main(void) {
  lex();
  S();

  return(0);
}

void lex() {
  if(scanf("%c", &token) == EOF) {
    printf("\nEnd of input!\n");

    printf("\nWord until was accepted => ");
    for(int i = 0; i <= topword; ++i) {
      printf("%c", word[i]);
    }
    printf("\n");

    exit(0);
  }

  word[++topword] = token;
}

void error(char missing_item){
  printf("\nERROR!");

  if(64 < missing_item && missing_item < 91) {
    printf("\nNo derivation compatible in: %c\n", missing_item);
  } else {
    printf("\nMissing char: %c\n", missing_item);
  }

  printf("\nWord until was accepted => ");
  for(int i = 0; i < topword; ++i) {
    printf("%c", word[i]);
  }
  printf("\n");
  
  exit(0);
}

int S() {
  if(token == 'm') {
    lex();
    NGM();
  } else if(token == 'g') {
    lex();
    NGM();
    if(token == 'm') {
      lex();
      NGM();
    } else { error('m'); }
  } else if(token == 'n') {
    lex();
    NGM();
    if(token == 'g') {
      lex();
      NGM();
      if(token == 'm') {
        lex();
        NGM();
      } else { error('m'); }
    } else { error('g'); }
  } else { error('S'); }

  return(0);
}

int NGM() {
  if(token == '(') {
    lex();
    if(token == ')') {
      lex();
      if(token == '{') {
        lex();
        C();
        if(token == ';') {
          lex();
          if(token == 'r') {
            lex();
            if(token == '(') {
              lex();
              E();
              if(token == ')') {
                lex();
                if(token == ';') {
                  lex();
                  if(token == '}') {
                    lex();
                  } else { error('}'); }
                } else { error(';'); }
              } else { error(')'); }
            } else { error('('); }
          } else { error('r'); }
        } else { error(';'); }
      } else { error('{'); }
    } else { error(')'); }
  } else { error('('); }

  return(0);
}

int C() {
  if(token == 'h') {
    lex();
    if(token == '=') {
      lex();
      E();
    } else { error('='); }
  } else if(token == 'i') {
    lex();
    if(token == '=') {
      lex();
      E();
    } else { error('='); }
  } else if(token == 'j') {
    lex();
    if(token == '=') {
      lex();
      E();
    } else { error('='); }
  } else if(token == 'k') {
    lex();
    if(token == '=') {
      lex();
      E();
    } else { error('='); }
  } else if(token == 'z') {
    lex();
    if(token == '=') {
      lex();
      E();
    } else { error('='); }
  } else if(token == '(') {
    lex();
    E();
    X();
    E();
    if(token == ')') {
      lex();
    } else { error(')'); }
  } else if(token == 'w') {
    lex();
    if(token == '(') {
      lex();
      E();
      if(token == ')') {
        lex();
        if(token == '{') {
          lex();
          C();
          if(token == ';') {
            lex();
            if(token == '}') {
              lex();
            } else { error('}'); }
          } else { error(';'); }
        } else { error('{'); }
      } else { error(')'); }
    } else { error('('); }
  } else if(token == 'f') {
    lex();
    if(token == '(') {
      lex();
      E();
      if(token == ')') {
        lex();
        if(token == '{') {
          lex();
          C();
          if(token == ';') {
            lex();
            if(token == '}') {
              lex();
            } else { error('}'); }
          } else { error(';'); }
        } else { error('{'); }
      } else { error(')'); }
    } else { error('('); }
  } else if(token == 'o') {
    lex();
    if(token == '(') {
      lex();
      E();
      if(token == ';') {
        lex();
        E();
        if(token == ';') {
          lex();
          E();
          if(token == ')') {
            lex();
            if(token == '{') {
              lex();
              C();
              if(token == ';') {
                lex();
                if(token == '}') {
                  lex();
                } else { error('}'); }
              } else { error(';'); }
            } else { error('{'); }
          } else { error(')'); }
        } else { error(';'); }
      } else { error(';'); }
    } else { error('('); }
  } else { error('C'); }

  return(0);
}

int E() {
  if(token == '0') {
    lex();
  } else if(token == '1') {
    lex();
  } else if(token == 'x') {
    lex();
  } else if(token == 'y') {
    lex();
  } else if(token == '(') {
    lex();
    E();
    X();
    E();
    if(token == ')') {
      lex();
    } else { error(')'); }
  } else { error('E'); }

  return(0);
}

int X() {
  if(token == '+') {
    lex();
  } else if(token == '-') {
    lex();
  } else if(token == '*') {
    lex();
  } else if(token == '/') {
    lex();
  } else { error('X'); }

  return(0);
}