
void getLps(string p, vector<int> &lps) 
{
    int len = 0;
    int index = 1;
    int m = p.size();

    while (index < m)
    {
        if (p[index] == p[len])
        {
            len += 1;
            lps[index] = len;
            index += 1;
        }

        else
        {
            if (len == 0)
            {
                lps[index] = 0;
                index += 1;
            }

            else
            {
              
                len = lps[len - 1]; 
            }
        }
    }
}

bool findPattern(string p, string s)
{
    int m = p.size();
    int n = s.size();
    vector<int> lps(m, 0);

    getLps(p, lps);

    
    int index1 = 0;
    int index2 = 0;

    while (index1 < n)
    {
        if (s[index1] == p[index2])
        {
            index2++;
            index1++;
            if (index2 == m)
            {
                return true;
            }

            if (index1 == n)
            {
                return false;
            }
        }
        else
        {
            if (index2 == 0)
            {
                index1 += 1;
            }
            else
            {
                
                index2 = lps[index2 - 1];
            }
        }
    }

    return false;
}
