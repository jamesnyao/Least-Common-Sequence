/** 
 *	Program 1 : LCS bottom-up
**/
#include "Functions.h"

using namespace std;

void lcs(string str_i, int length_i, string str_j, int length_j, int **c, char **d, ofstream *output_f)
{
	int i, j, start, end;
	
	// Records system clock ticks
	start = clock();
	
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
	
	// Matrix to file
	if (length_i <= 10 && length_j <= 10)
	{
		matrix_to_file(cout, length_i, length_j, c, d);
	}
    
    // Longest common subsequence to file
    lcs_to_file(cout, str_i, length_i, str_j, length_j, c, d);
    
    // Running time to file
    running_time_to_file(cout, start, end);
}
