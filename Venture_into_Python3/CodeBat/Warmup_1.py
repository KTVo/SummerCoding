"""
Warmup-1 > sleep_in

The parameter weekday is True if it is a weekday, and the parameter vacation is True 
if we are on vacation.

We sleep in if it is not a weekday or we're on vacation. 
Return True if we sleep in.

If NOT a weekday OR ON vacation
    TRUE, we sleep-in


sleep_in(False, False) → True
sleep_in(True, False) → False
sleep_in(False, True) → True

W | V | Result
--------------
T | T |   T
T | F |   F
F | T |   T
F | F |   T

"""

def sleep_in(weekday, vacation):
    if(not weekday or vacation):
        return True
    else:
        return False


"""
Warmup-1 > monkey_trouble

We have two monkeys, a and b, and the parameters a_smile and b_smile indicate if each is smiling. 

We are in trouble if they are both smiling or if neither of them is smiling. 
    Return True if we are in trouble.


monkey_trouble(True, True) → True
monkey_trouble(False, False) → True
monkey_trouble(True, False) → False

a | b | Result
--------------
T | T |   T
T | F |   F
F | T |   F
F | F |   T

"""

def monkey_trouble(a_smile, b_smile):
    if(a_smile and b_smile or not a_smile and not b_smile):
        return True
    else:
        return False



"""
Warmup-1 > sum_double

Given two int values, return their sum. 

Unless the two values are the same, then return double their sum.


sum_double(1, 2) → 3
sum_double(3, 2) → 5
sum_double(2, 2) → 8

"""

def sum_double(num1, num2):
    sum = num1 + num2
    if(num1 != num2):
        return sum
    else:
        return 2*sum


"""
Warmup-1 > diff21

Given an int n, return the absolute difference between n and 21, 

except return double the absolute difference if n is over 21.


diff21(19) → 2
diff21(10) → 11
diff21(21) → 0
"""

def diff21(n):
    if(n <= 21):
        return 21 - n
    else:
        return 2*(n-21)

"""

Warmup-1 > parrot_trouble

We have a loud talking parrot. The "hour" parameter is the current hour time in the range 0..23.

We are in trouble if the parrot is talking and the hour is before 7 or after 20. 

Return True if we are in trouble.


parrot_trouble(True, 6) → True
parrot_trouble(True, 7) → False
parrot_trouble(False, 6) → False

L | H | In_Trouble
-------------------
T | T |     T
T | F |     F
F | T |     F
F | F |     F

"""

def parrot_trouble(talking, hour):
  if(hour in range(-1, 24)):
    if(talking and (hour < 7 or hour > 20)):
      return True
    else:
      return False


"""
Warmup-1 > makes10

Given 2 ints, a and b, return True if one if them is 10 or if their sum is 10.

a | b | S | RESULT
-------------------
T | T | T |    T
T | T | F |    T
T | F | T |    T
T | F | F |    T
F | T | T |    T
F | T | F |    T
F | F | T |    T
F | F | F |    F

makes10(9, 10) → True
makes10(9, 9) → False
makes10(1, 9) → True

"""

def makes10(a, b):
    if(a == 10 or b == 10 or a + b == 10):
        return True
    else:
        return False

"""

Warmup-1 > near_hundred

Given an int n, return True if it is within 10 of 100 or 200. 

Note: abs(num) computes the absolute value of a number.


near_hundred(93) → True
near_hundred(90) → True
near_hundred(89) → False

"""

def near_hundred(n):
  if(abs(n-100) in range(-1, 11) or abs(n-200) in range(-1, 11)):
    return True
  else:
    return False

"""

Warmup-1 > pos_neg

Given 2 int values, return True if one is negative and one is positive. 

Except if the parameter "negative" is True, then return True only if both are negative.

"""

pos_neg(1, -1, False) → True
pos_neg(-1, 1, False) → True
pos_neg(-4, -5, True) → True
def pos_neg(a, b, negative):
  if(negative and a < 0 and b < 0):
    return True
  elif(not negative and ((a >= 0 and b < 0) or (a < 0 and b >= 0))):
    return True
  else:
    return False


"""
Warmup-1 > not_string

Given a string, return a new string where "not " has been added to the front. However, if the string already begins with "not", return the string unchanged.


not_string('candy') → 'not candy'
not_string('x') → 'not x'
not_string('not bad') → 'not bad'

"""

def not_string(str):
  if(len(str) >= 3 and str[0] == 'n' and str[1] == 'o' and str[2] == 't'):
    return str
  else:
    return 'not ' + str
    

"""

Warmup-1 > missing_char

Given a non-empty string and an int n, 
return a new string where the char at index n has been removed. 
The value of n will be a valid index of a char in the original string (i.e. n will be in the range 0..len(str)-1 inclusive).


missing_char('kitten', 1) → 'ktten'
missing_char('kitten', 0) → 'itten'
missing_char('kitten', 4) → 'kittn'

"""
def missing_char(str, num):
  newStr = ""
  length = len(str)
  if(num >= 0 and num < length):
    for i in range(0, length):
        if(i != num):
          newStr += str[i]
    return newStr

def missing_char(str, num):
    length = len(str)
    temp = ""
    if(num >= 0 and num < length):
      if(num > 0 and num < length):
          temp = str[0 : num]
          temp += str[num + 1 : length]
            
          return temp
            
      elif(num == length):
        return str[0 : length]
      else:
        return str[1 : length]
        
def missing_char(str, num):
    temp = str[:num]
    temp += str[num+1 : len(str)]
    
    return front
    
"""

Warmup-1 > front_back

Given a string, return a new string where the first and last chars have been exchanged.


front_back('code') → 'eodc'
front_back('a') → 'a'
front_back('ab') → 'ba'

"""

#my solution
def front_back(str):
  last = len(str)-1
  if(last > 0):
    temp = ""
    temp += str[last]
    
    for i in range(1, last):
      temp += str[i]
      
    temp += str[0]
    
    return temp
    
  return str


#Theirs, being new to python, I had no idea you could intercept strings with str[1st_term : last_term]
def front_back(str):
  last = len(str)-1
  if(last <= 0 ):
    return str
  temp = str[last]
  temp += str[ 1 : last] 
  temp += str[0]
  
  return temp
  
  
  
 """
 Warmup-1 > front3

Given a string, we'll say that the front is the first 3 chars of the string. 
If the string length is less than 3, the front is whatever is there. 

Return a new string which is 3 copies of the front.


front3('Java') → 'JavJavJav'
front3('Chocolate') → 'ChoChoCho'
front3('abc') → 'abcabcabc'


"""
def front3(str):
  end = 3
  length = len(str)
  if(length < end):
    return str + str + str
    
  pre = str[0:end]
  
  if(pre[0] == pre[1] and pre[1] != pre[2]):
    return pre[0] + pre[2]
  else:
    return pre + pre + pre
    
    
def front3(str):
  front_end = 3
  if len(str) < front_end:
    front_end = len(str)        #re-adjust size if less than 3
  front = str[:front_end]       #splice string to readjusted/unadjusted size
  return front + front + front



        

