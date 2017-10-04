#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern void lcs(string str_i, int length_i, string str_j, int length_j, int **c, char **d, ofstream *output_f);

int main(int argc, char **argv)
{
	int length_i, length_j, i, j;
	string str_i, str_j;
	int **c;	// Occurance table
	char **d;	// Direction table
	ofstream *output_f;
	
	str_i = "ABCB";
	str_j = "BDCAB";
	
	length_i = str_i.length();
	length_j = str_j.length();
	
	// Initializing tables
	c = new int*[length_i + 1];
	d = new char*[length_i + 1];
	for (i = 0; i < (length_i + 1); i++)
	{
		c[i] = new int[length_j + 1];
		d[i] = new char[length_j + 1];
	}
	for (i = 0; i < (length_i + 1); i++)
	{
		c[i][0] = 0;
		d[i][0] = 0;
	}
	for (j = 0; j < (length_j + 1); j++)
	{
		c[0][j] = 0;
		d[0][j] = 0;
	}
	
	lcs(str_i, length_i, str_j, length_j, c, d, output_f);
	
	for (i = 0; i < (length_i + 1); i++) 
	{
		delete[] c[i];
		delete[] d[i];
	}
	delete[] c;
	delete[] d;
	
	return 0;
}