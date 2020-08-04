import math

def isPalindrome(str):
  sz = len(str)
  
  mid = 0

  if(sz%2 == 0): #if odd
    mid = math.floor((sz+1)/2)
  else:
    mid = math.floor(sz/2)
 
  left = ""
  right = ""

  left = str[0:mid]

  right = str[sz:-1]  
  print(left + " = " + right)

  if(left == right):
    return True
  else:
    return False

print(isPalindrome("BOOB"))