
import math  
def binarySearch(val, arr):
    sz = len(arr)
    mid = 0
    min = 0
    max = sz-1
    indx = -1
    cnt = 0
  

    while(indx==-1 and cnt < sz/2):
        mid = math.floor( (min + max)/2 )

        if(arr[mid] == val):
            indx = mid
        elif(arr[mid] > val):
            max = mid -1
        else:
            min = mid+1

        cnt += 1
    
    return indx

def driver():
    a = [3, 4, 5, 5, 87, 87, 92]
    
    findVal = 87

    indx = binarySearch(findVal, a)

    if(indx == -1):
        print("\nDNE.\n")
    else:
        print("\n", findVal, " at INDEX = ", indx, "\n")


driver()