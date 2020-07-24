#include <iostream>

using namespace std;

/*
    This function copies data from one array into another
    Parameters: clone_arr -> The empty array
                orig_arr  -> The original array
                start     -> starting index to be copied
                end       -> ending index to be copied
*/
void populateArray(int *cloned_arr, const int *orig_arr, const int start, const int end)
{
    int indx_orig = start;  //Index for the array being cloned from
    int indx_clone = 0;     //Index for the array being cloned to

    while(indx_orig <= end)
        cloned_arr[indx_clone++] = orig_arr[indx_orig++];
    
}

void display(const int *a, const int sz)
{
    cout<<endl;
    for(int i = 0; i < sz; i++)
    {
        cout<<a[i];
        if(i < sz-1)
            cout<<", ";
    }
    cout<<endl;

}
void merge(int *orig_arr, int start, int mid, int end)
{
    int L_size = mid/2;     //Size of Left array
    int R_size = end - mid; //Size of Right array

    //Left & Right arrays for merge sorting the original array orig_arr
    int Left[L_size];
    int Right[R_size];

    //Populate Left array
    populateArray(Left, orig_arr, 0, L_size);

    //Populate Right array
    populateArray(Right, orig_arr, L_size-1, end);

    int L_cnt = 0;          //index counter for Left array
    int R_cnt = 0;          //index counter for Right array
    int Orig_cnt = start;   //index counter for Original array

    while(L_cnt < L_size && R_cnt < R_size)
        if(Left[L_cnt] <= Right[R_cnt])
            orig_arr[Orig_cnt++] = Left[L_cnt++];
        else
            orig_arr[Orig_cnt++] = Right[R_cnt++];
    

    while(L_cnt < L_size)
        orig_arr[Orig_cnt++] = Left[L_size++];
    

    while(R_cnt < R_size)
        orig_arr[Orig_cnt++] = Right[R_size++];
    

    

}



void mergeSort(int *a, int start, int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        mergeSort(a, start, end);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }

}
int main()
{
    /*
    int sz = 7;
    int a[sz] = {0, 4, 5, 6, 7, 8, 100};
    int b[4];
    int c[3]; 
    
    
    populateArray(b, a, 0, 4-1);
    populateArray(c, a, 4, sz-1);

    display(b, 4);
    display(c, 3);
    */

   const int sz = 7;
   int a[sz] = {56, 2, 9, 19, 23, 9000, -4};

    display(a, sz);

    mergeSort(a, 0, sz-1);

    display(a, sz);
    
    return 0;
}