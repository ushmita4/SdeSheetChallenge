

#include <unordered_set>

#include <queue>

bool wordBreak(vector < string > & arr, int n, string & target) {
   
    unordered_set < string > hashMap;

    
    for (string s: arr) {
        hashMap.insert(s);
    }

 
    queue < int > q;

   
    unordered_set < int > visited;


    q.push(0);

   
    while (q.size() > 0) {
       
        int frontElement = q.front();
        q.pop();

        
        if (visited.find(frontElement) == visited.end()) {
          
            visited.insert(frontElement);

            
            for (int j = frontElement; j < target.size(); j++) {
               
                if (hashMap.find(target.substr(frontElement, j - frontElement + 1)) != hashMap.end()) {
                    q.push(j + 1);

                  
                    if (j + 1 == target.size())
                        return true;
                }
            }
        }
    }

    return false;
}
