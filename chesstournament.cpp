int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int high=positions[n-1],low=1,res=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int f=1;
        int h=positions[0];
        for(int i=1;i<n;i++){
            if(positions[i]-h>=mid)
            {
                f++;
                h=positions[i];
            }
        }
        if(f>=c)
        {
            res=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return res;
}
