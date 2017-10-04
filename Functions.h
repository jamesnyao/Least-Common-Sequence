#ifndef __CS375_PROGRAM1_FUNCTIONS_H__
#define __CS375_PROGRAM1_FUNCTIONS_H__

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

int running_time_to_file(std::ofstream &ofs, int start, int end);

void matrix_to_file(std::ofstream &ofs, int length_i, int length_j, int **c, char **d);

void lcs_to_file(std::ofstream &ofs, std::string str_i, int length_i, std::string str_j, int length_j, int **c, char **d);

#endif
