import sys

def Min(arr, cnt, end, min):
    if(cnt < end):
        if(min > arr[cnt]):
            min = arr[cnt]

    else:
        return min

    return Min(arr, cnt+1, end, min)

def Max(arr, cnt, end, max):
    if(cnt < end):
        if(max < arr[cnt]):
            max = arr[cnt+1]

    else:
        return max

    return Max(arr, cnt+1, end, max)

    
def driver():
    a = [3, 45, 233, 542, 2, 56, 9, 1, 3, -69, -233]

    sz = len(a)

    m = Max(a, 0, sz, 0)

    print("\n\n max = ", m, "\n\n")

    m = Min(a, 0, sz, 0)

    print("\n\n min = ", m, "\n\n")

driver()