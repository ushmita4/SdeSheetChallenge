

#include <unordered_set>
using namespace std;

vector<string> wordBreakHelper(string &s, int idx, unordered_set<string> &dictSet, int size)
{
 
    if (idx == size)
    {
        return {""};
    }

    vector<string> subPart, completePart;
    string word = "";

 
    for (int j = idx; j < size; j++)
    {

        word.push_back(s[j]);
        if (dictSet.count(word) == 0)
        {
            continue;
        }

        subPart = wordBreakHelper(s, j + 1, dictSet, size);

       
        for (int i = 0; i < subPart.size(); i++)
        {
            if (subPart[i].size() != 0)
            {
                string temp = word;
                temp.append(" ");
                temp.append(subPart[i]);
                subPart[i] = temp;
            }
            else
            {
                subPart[i] = word;
            }
        }

        for (int i = 0; i < subPart.size(); i++)
        {
            completePart.push_back(subPart[i]);
        }
    }
    return completePart;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    
    unordered_set<string> dictSet;

    for (int i = 0; i < dictionary.size(); i++)
    {
        dictSet.insert(dictionary[i]);
    }
    return wordBreakHelper(s, 0, dictSet, s.size());
}
