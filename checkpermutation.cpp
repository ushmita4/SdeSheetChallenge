bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int check[256]={0};
    int i;
    int l1=str1.length();
    int l2=str2.length();
    if(l1!=l2)
        return false;
    else
    {
        
        for(int i=0;i<l1;i++){
            check[str1[i]]++;
            check[str2[i]]--;
        }
    }
    for(int i=0;i<256;i++)
    {
        if(check[i])
            return false;
    }
    return true;
}
