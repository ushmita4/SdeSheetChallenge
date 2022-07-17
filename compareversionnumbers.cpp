
string removeZerosFromEnd(string a) 
{

    
    int p = a.length() - 1;

   
    for (int i = a.length() - 1; i >= 1; i -= 2) 
    {

        
        if (a[i] == '0'  and a[i - 1] == '.') 
        {
            p -= 2;
        }

    
        else 
        {
            break;
        }

    }

   
    return a.substr(0, p + 1);
}

int compareVersions(string a, string b) 
{

    a = removeZerosFromEnd(a);
    b = removeZerosFromEnd(b);


    int start1 = 0, start2 = 0, end1 = 0, end2 = 0;

 
    while (true) 
    {

        
        while (end1 < a.length() and a[end1] != '.') 
        {
            end1++;
        }

        
        while (end2 < b.length() and b[end2] != '.') 
        {
            end2++;
        }
        
       
        if (end1 > end2) 
        {
            return 1;
        }
        else if (end1 < end2) 
        {
            return -1;
        }
        
     
        for (int i = start1; i < end1; i++) 
        {
            if (a[i] > b[i]) 
            {
                return 1;
            }
            else if (b[i] > a[i]) 
            {
                return -1;
            }

        }

 
        if (end1 == a.length() and end2 == b.length()) 
        {
            return 0;
        }
        
        // Check if we reached end of string a
        if (end1 == a.length()) 
        {
            return -1;
        }

       
        if (end2 == b.length()) 
        {
            return 1;
        }

        
        start1 = end1;
        start2 = end2;
        end1++;
        end2++;
    }
}
