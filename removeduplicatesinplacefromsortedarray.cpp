int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}
