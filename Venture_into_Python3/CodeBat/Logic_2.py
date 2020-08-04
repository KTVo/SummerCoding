"""

Logic-2 > make_bricks

We want to make a row of bricks that is goal inches long. We have a number of small bricks (1 inch each) 
and big bricks (5 inches each). Return True if it is possible to make the goal by choosing from the given bricks.
This is a little harder than it looks and can be done without any loops. See also: Introduction to MakeBricks


make_bricks(3, 1, 8) → True
make_bricks(3, 1, 9) → False
make_bricks(3, 2, 10) → True

"""

def make_bricks(small, big, goal):
  sz_big = 5  #the given size of the big bricks
  sz_small = 1 #the given size of small bricks
  
  #considers if there are not enough bricks total
  if(goal%sz_big > small*sz_small):
    return False
    
  elif(goal > big*sz_big + small*sz_small):
    return False
    
    
  return True



"""

Logic-2 > lone_sum

Given 3 int values, a b c, return their sum. However, if one of the values is the same as another of the values, it does not count towards the sum.


lone_sum(1, 2, 3) → 6
lone_sum(3, 2, 3) → 2
lone_sum(3, 3, 3) → 0


"""

def lone_sum(a, b, c):
  if(a == b and a == c):
    return 0
  elif(a == b):
    return c
  elif(a == c):
    return b
  elif(b == c):
    return a
  else:
    return a + b + c
	

def lone_sum(a, b, c):
  sum = 0
  if a != b and a != c: sum += a
  if b != a and b != c: sum += b
  if c != a and c != b: sum += c
  
  return sum

"""

Logic-2 > lucky_sum

Given 3 int values, a b c, return their sum. However, if one of the values is 13 then it does not count towards the sum and values to its 
right do not count. So for example, if b is 13, then both b and c do not count.


lucky_sum(1, 2, 3) → 6
lucky_sum(1, 2, 13) → 3
lucky_sum(1, 13, 3) → 1



"""

def lucky_sum(a, b, c):
  if(a == 13):
    return 0
  elif(b == 13):
    return a
  elif(c == 13):
    return a + b
  else:
    return a + b + c
    
	

"""

Logic-2 > no_teen_sum

Given 3 int values, a b c, return their sum. However, if any of the values is a teen -- in the range 13..19 inclusive 
-- then that value counts as 0, except 15 and 16 do not count as a teens. Write a separate helper "def fix_teen(n):
"that takes in an int value and returns that value fixed for the teen rule. In this way, you avoid repeating the teen code 3 times 
(i.e. "decomposition"). Define the helper below and at the same indent level as the main no_teen_sum().


no_teen_sum(1, 2, 3) → 6
no_teen_sum(2, 13, 1) → 3
no_teen_sum(2, 1, 14) → 3

"""

def no_teen_sum(a, b, c):
	sum = 0
	
	if(a not in range(13, 15) or a not in range(17, 20))
		return sum += a
		
	if(b not in range(13, 15) or b not in range(17, 20))
		return sum += b
		
	if(c not in range(13, 15) or c not in range(17, 20))
		return sum += c
		
	return sum

"""

Logic-2 > round_sum

For this problem, we'll round an int value up to the next multiple of 10 if its rightmost digit is 5 or more, so 15 rounds up to 20. 
Alternately, round down to the previous multiple of 10 if its rightmost digit is less than 5, so 12 rounds down to 10. Given 3 ints, a b c, 
return the sum of their rounded values. To avoid code repetition, write a separate helper "def round10(num):" and call it 3 times. 

Write the helper entirely below and at the same indent level as round_sum().


round_sum(16, 17, 18) → 60
round_sum(12, 13, 14) → 30
round_sum(6, 4, 4) → 10


"""

def no_teen_sum(a, b, c):
	sum = 0
	
	if(a not in range(13, 15) and a not in range(17, 20)):
		sum += a
		
	if(b not in range(13, 15) and b not in range(17, 20)):
		sum += b
		
	if(c not in range(13, 15) and c not in range(17, 20)):
		sum += c
		
	return sum
	
	
"""

Logic-2 > close_far

Given three ints, a b c, return True if one of b or c is "close" (differing from a by at most 1), while the other is "far", 
differing from both other values by 2 or more. Note: abs(num) computes the absolute value of a number.


close_far(1, 2, 10) → True
close_far(1, 2, 3) → False
close_far(4, 1, 3) → True

"""

def round_sum(a, b, c):
  sum = 0
  
  a_mod = a%10
  b_mod = b%10
  c_mod = c%10
  
  if(a_mod >= 5):
    sum += a - a_mod + 10
  else:
    sum += a - a_mod
  
  if(b_mod >= 5):
    sum += b - b_mod + 10
  else:
    sum += b - b_mod
    
  if(c_mod >= 5):
    sum += c - c_mod + 10
  else:
    sum += c - c_mod

  return sum
  
"""

Logic-2 > make_chocolate

We want make a package of goal kilos of chocolate. We have small bars (1 kilo each) and big bars (5 kilos each). 

Return the number of small bars to use, assuming we always use big bars before small bars. Return -1 if it can't be done.


make_chocolate(4, 1, 9) → 4
make_chocolate(4, 1, 10) → -1
make_chocolate(4, 1, 7) → 2

"""

