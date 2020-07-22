
import math

def BinarySearch(val, arr, sz, min, max, cnt):
    
    mid = math.floor((max + min)/2)

    if(arr[mid] == val):
        return mid
    elif(cnt >= sz):
        return -1
    elif(arr[mid] > val):
        max = mid-1
    else:
        min = mid+1

    return BinarySearch(val, arr, sz, min, max, cnt+1)


def driver():

    v = 99999
    a = [1, 2, 3, 55, 66, 77, 88, 833, 9000]
    sz = len(a)
    
    bs = BinarySearch(v, a, math.floor(sz/2), 0, sz-1, 0)

    if(bs == -1):
        print("\nDNE\n")
    else:
        print("\n", v," is at index = ", bs)


driver()