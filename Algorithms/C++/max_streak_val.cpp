/* 
 * File:   FindMaxSubArray_main.cpp
 * Author: Kevin Vo
 *
 * Created on August 1, 2020, 5:36 PM
 */

#include <iostream>
#include <cstdlib>
#include <queue>    //used to store index

using namespace std;

int finMaxSubArray(const int *a, const int sz, queue<int> *q)
{
   
    int max = a[0];  //Min value of int

    
    for(int i = 0; i < sz; i++)
    {
        if(i != 0)
            //Skips 1st term if 1st term is negative
            while(i < sz-1 && a[i] < 0)
                i++;
           

        int sum = a[i]; //Sets sum to 1st term
        
        for(int j = i + 1; j < sz-1; j++)  
        {
            //Checks if sum with next term will have sum be negative
            //if so, then it will halt the inner for-loop
            if((sum + a[j + 1]) < 0 )   
            {
                //Checks if current summation will make total sum greater
                //if so, sums it
                if((a[j] + sum) > 0)
                {
                    sum += a[j];
                    q->push(j);
                }
                
                if(max < sum)
                    max = sum;
                
                j = sz; //sets j stop inner for-loop
            }
            else
            {
                sum += a[j];    //Continually adds terms to sum
                q->push(i);
            }
            //sets max to sum if sum is ever greater
            if(max < sum)
                    max = sum;
        }
        

    }
    
    //Adds the very last term if it's a positive or 0
    if(a[sz-2] >= 0)
    {
        max += a[sz-1];
        q->push(sz-1);
    }
    
    return max;
}
int main(int argc, char** argv) {
    queue<int> q;
    const int sz = 8;
    const int a[sz] = { 1, -3, 2, 1, -1, 200, -1000, 1 }; 
    
    cout<<finMaxSubArray(a, sz, &q);
    
    cout<<endl;
    
    while(!q.empty())
    {
        cout<<q.front()<<", ";
        q.pop();
    }
    
    return 0;
}


