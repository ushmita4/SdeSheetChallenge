

int zAlgorithm(string s, string p, int n, int m)
{
    int count = 0, l = 0, r = 0, pos;
    string c = p + "#" + s;
    int k = c.length();
    
    
    int zarr[k];
    zarr[0] = 0;
    for (int i = 1; i < k; i++)
    {
        if (i > r)
        {
    
           
            l = i;
            r = i;
    
           
            while (r < k and c[r - l] == c[r] )
            {
                r++;
            }

            zarr[i] = (r--) - l;
            
            
            if (zarr[i] == m)
            {
                count++;
            }

        }

        else
        {
            int pos = i - l;

            if (zarr[pos] < r - i + 1)
            {
                zarr[i] = zarr[pos];
    
                
                if (zarr[i] == m)
                {
                    count++;
                }

            }

            else
            {
                l = i;
    
                while (r < k and c[r - l] == c[r])
                {
                    r++;
                }

                zarr[i] = (r--) - l;
    
              
                if (zarr[i] == m)
                {
                    count++;
                }

            }
        }
    }

    return count;
}
