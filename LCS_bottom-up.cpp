/** 
 *	Program 1 : LCS bottom-up
**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void lcs(string str_i, int length_i, string str_j, int length_j, int **c, char **d, ofstream *output_f)
{
	int i, j, start, end, millisec;
	
	// Records system clock ticks
	start = clock();
int //Now check what amount of ticks we have now. 
//To get the time, just subtract start from end, and divide by CLOCKS_PER_SEC.
std::cout << "it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << std::endl;
	
	for (i = 1; i < length_i + 1; i++)
	{
		for (j = 1; j < length_j + 1; j++)
		{
			if (str_i[i-1] == str_j[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				d[i][j] = 'D';
			}
			else
			{
				if (c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					d[i][j] = 'U';
				}		
				else
				{
					c[i][j] = c[i][j-1];
					d[i][j] = 'L';
				}
			}
		}
	}
	
	// Records system clock ticks again
	end = clock();
	millisec = (end - start) / (CLOCKS_PER_SEC / 1000)
	
	
	// Matrix to file
	if (length_i <= 10 && length_j <= 10)
	{
		for (i = 0; i < length_i + 1; i++)
		{
			for (j = 0; j < length_j + 1; j++)
			{
				cout << c[i][j] << ',' << d[i][j] << '\t';
			}
			cout << endl;
		}
	}
}
