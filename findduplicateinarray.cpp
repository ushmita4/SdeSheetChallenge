/*

	Time complexity: O(N) 
	Space complexity: O(1)
	
	Where N is the length of the array.

*/

int findDuplicate(vector<int> &arr, int n)
{
    
    // Initialise tortoise and hare pointers.
    int tortoise = arr[0];
    int hare = arr[0];

    do 
    {

        // Hare pointer moves twice as fast as tortoise.
        tortoise = arr[tortoise];
        hare = arr[arr[hare]];
    } 
    
    // Find the intersection point of the two runners.
    while (tortoise != hare);

    // To find the entrance to the cycle tortoise begins from start of array while hare begins from intersection point.
    tortoise = arr[0];
    while (tortoise != hare) 
    {
      
      // This time both runners move with same speed.
      tortoise = arr[tortoise];
      hare = arr[hare];
    }

    // Return the entrance to the cycle, which will be the repeated element.
    return hare;
}
