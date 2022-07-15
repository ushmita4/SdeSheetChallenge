

vector<int> stringMatch(string &str, string &pat) {

    int prime = 31;
    int mod = 998244353;

    int m = pat.length();
    int n = str.length();

   
    vector<long long> primePower(n);

    primePower[0] = 1;
    for (int i = 1; i < n; i++)
    {
        primePower[i] = (primePower[i - 1] * prime) % mod;
    }

    
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (str[i] - 'A' + 1) * primePower[i]) % mod;
    }

   
    long long hashPattern = 0;
    for (int i = 0; i < m; i++)
    {
        hashPattern = (hashPattern + (pat[i] - 'A' + 1) * primePower[i]) % mod;
    }
    
    vector<int> occurences;

   
    for (int i = 0; i + m - 1 < n; i++) 
    {
        long long currentHash = (h[i + m] + mod - h[i]) % mod;

        if (currentHash == hashPattern * primePower[i] % mod)
        {
            occurences.push_back(i);
        }
    }

    return occurences;
    
}
