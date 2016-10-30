#pragma once

#include <string>
#include <cstdio>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

typedef enum _bcolor{BLACK,
                     RED,
                     GREEN,
                     DGREEN,
                     YELLOW,
                     BLUE,
                     PURPLE,
                     WHIRE} BCOLOR;
static const char* BColorStrings[] = {"40m" //black
                                      ,"41m"//red
                                      ,"42m"//green
                                      ,"46m" //dark green
                                      ,"43m"//yellow
                                      ,"44m"//blue
                                      ,"45m"//purple
                                      ,"47m" //white
};

typedef enum _fcolor{BLACK,
                     RED,
                     GREEN,
                     DGREEN,
                     YELLOW,
                     BLUE,
                     PURPLE,
                     WHITE,
                     CYAN,
                     NONE } FCOLOR;
static const char* FColorStrings[] = {"\033[30;" //black
                                      ,"\033[31;"//red
                                      ,"\033[32;"//green
                                      ,"\033[6;" //dark green
                                      ,"\033[33;"//yellow
                                      ,"\033[34;"//blue
                                      ,"\033[35;"//purple
                                      ,"\033[7;" //white
                                      ,"\x1b[36m"//cyan
                                      ,"\033[0m" //none
};

const char* getFontColorForEnum( FCOLOR color ){
  return FColorStringStrings[color];
}
const char* getBackgroundColorForEnum( BCOLOR color ){
  return BColorStringStrings[color];
}

#define PRINTFONTCOLOR(color, str) printf( color str "\033[0m");
#define PRINTBACKGROUNDCOLOR(color, str) printf( color str "\033[0m");
#define PRINTBACKGROUNDCOLOR(fcolor, bcolor, str) printf( fcolor bcolor str "\033[0m");
