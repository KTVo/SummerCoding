import numpy as np

def getPrice(lb):

    if(lb <= 2.00):
        return 1.50
    elif(lb > 2.00 and lb <= 6.00):
        return 3.00
    elif(lb > 6.00 and lb <= 10.00):
        return 4.00
    else:
        return 4.75

def a():
    
    for x in np.arange(0.00, 12.01, 0.10):
        x = round(x, 2)
        print(x, "->", "$", getPrice(x), "\n")

a()
