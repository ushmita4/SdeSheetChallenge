int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
        int i=1,j=0,p=1,r=1;
    while(i<n && j<n){
        if(at[i]<=dt[j])
        {
            p++;
            i++;
        }
        else if(at[i]>dt[j])
        {
            p--;
            j++;
        }
        if(p>r)
            r=p;
    }
    return r;
}
