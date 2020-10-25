//
// Created by timmy on 10/14/20.
//

#ifndef UNTITLED_FILEDETECT_H
#define UNTITLED_FILEDETECT_H

#include "program.h"
#include <filesystem>
#include <filesystem>
#include <vector>

int getfiles(std::vector<program> &toFill);
bool validate_program(std::string progName); // checks if we have a corresponding instructionfile for progName


#endif //UNTITLED_FILEDETECT_H
