int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int ans=0;
    for(int i=0;i<arr.size();i++)
        ans=ans^arr[i];
    
    return ans;
}
