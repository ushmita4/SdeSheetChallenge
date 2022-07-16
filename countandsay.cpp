

string writeAsYouSpeak(int n) 
{

    
    string s = "1";
 
    int iterations = n - 1;
    while (iterations--) 
    {
        
        string temp = "";
        vector<int> count;
        
        
        int currentIndex = 0;
        
        
        while (currentIndex < s.length()) 
        {
            char currentChar = s[currentIndex];
            int currentCount = 0;
            while ((currentIndex < s.length()) && (s[currentIndex] == currentChar)) 
            {
                currentCount++;
                currentIndex++;
            }

            temp += currentChar;
            count.push_back(currentCount);
        }
        
       
        s = "";
        for(int i = 0; i < count.size(); i++) 
        {
            s += (char)('0' + count[i]);
            s += temp[i];
        }
    }
    return s;
}
