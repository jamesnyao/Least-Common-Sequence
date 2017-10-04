#include "Functions.h"

using namespace std;

void running_time_to_file(ofstream &ofs, int start, int end)
{
    ofs << (double)(end - start) / (double)(CLOCKS_PER_SEC) << " seconds" << endl;
}

void matrix_to_file(ofstream &ofs, int length_i, int length_j, int **c, char **d)
{
    int i, j;
    
    for (i = 0; i < length_i + 1; i++)
    {
        for (j = 0; j < length_j + 1; j++)
        {
            ofs << c[i][j] << ',' << d[i][j] << '\t';
        }
        ofs << endl;
    }
}

void lcs_to_file(ofstream &ofs, string str_i, int length_i, string str_j, int length_j, int **c, char **d)
{
    int i, j, subseq_len, current_len, d_i, d_j;
    
    subseq_len = 0;
    for (i = length_i; i > 0; i--)
    {
        for (d_j = length_j, d_i = i; d[d_i][d_j]; )
        {
            if (d[d_i][d_j] == 'U')
            {
                d_i--;
            }
            else if (d[d_i][d_j] == 'L')
            {
                d_j--;
            }
            else
            {
                d_i--;
                d_j--;
                current_len++;
            }
        }
        if (current_len > subseq_len)
        {
            subseq_len = current_len;
        }
    }
    for (j = length_j - 1; j > 0; j--)
    {
        for (d_j = j, d_i = length_i; d[d_i][d_j]; )
        {
            if (d[d_i][d_j] == 'U')
            {
                d_i--;
            }
            else if (d[d_i][d_j] == 'L')
            {
                d_j--;
            }
            else
            {
                d_i--;
                d_j--;
                current_len++;
            }
        }
        if (current_len > subseq_len)
        {
            subseq_len = current_len;
        }
    }
    
    ofs << subseq_len << endl;
}
