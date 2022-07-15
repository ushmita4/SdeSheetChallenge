long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long s=0;
    int maxi=INT_MIN;
    for(int i=0;i<m;i++)
    {
        s=s+time[i];
        maxi=max(maxi,time[i]);
    }
    long long low=maxi,high=s,res=s,mid,d=1,ct=0;
    while(low<=high){
        mid=(low+high)/2;
        d=1;
        ct=0;
        for(int i=0;i<m;i++){
            ct=ct+time[i];
            if(ct>mid)
            {
                d++;
                ct=time[i];
            }
        }
        if(d<=n)
        {
            res=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return res;
}
