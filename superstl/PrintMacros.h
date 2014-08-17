#ifndef PRINT_MACROS_H
#define PRINT_MACROS_H

#include <iostream>

#define ERROR(str) std::cerr<<"[ERROR ("<<__FILE__<<":"<<__LINE__<<")]: "<<str<<std::endl;

#define DEBUG(str)  std::cerr<< str <<std::endl;
#define DEBUGN(str) std::cerr<< str;

#define PRINT(str)  std::cout <<str<<std::endl;
#define PRINTN(str) std::cout <<str;

#endif /*PRINT_MACROS_H*/
