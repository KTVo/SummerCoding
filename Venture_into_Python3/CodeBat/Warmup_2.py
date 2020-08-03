"""
Warmup-2 > string_times

Given a string and a non-negative int n, return a larger string that is n copies of the original string.


string_times('Hi', 2) → 'HiHi'
string_times('Hi', 3) → 'HiHiHi'
string_times('Hi', 1) → 'Hi'

"""

def string_times(str, n):
    if(n >= 0):
        larger_str = ""
        for i in range(n):
            larger_str += str
        return larger_str
        
        
"""
Warmup-2 > front_times

Given a string and a non-negative int n, 
we'll say that the front of the string is the first 3 chars, 
or whatever is there if the string is less than length 3. 

Return n copies of the front;


front_times('Chocolate', 2) → 'ChoCho'
front_times('Chocolate', 3) → 'ChoChoCho'
front_times('Abc', 3) → 'AbcAbcAbc'

"""

def front_times(str, n):
  if(n >= 0):
    sz = 3
    if(len(str) < sz):
      sz = len(str)
      
    pre = ""
    
    for i in range(n):
      pre += str[:sz]
      
    return pre
    
 """
Warmup-2 > string_bits

Given a string, return a new string made of every other char starting with the first, so "Hello" yields "Hlo".


string_bits('Hello') → 'Hlo'
string_bits('Hi') → 'H'
string_bits('Heeololeo') → 'Hello'

"""

def string_bits(str):
  sz = len(str)
  eo_str = ""
  for i in range(sz):
    if(i%2 == 0):
      eo_str += str[i]
      
  return eo_str

"""
Warmup-2 > string_splosion

Given a non-empty string like "Code" return string like "CCoCodCode".


string_splosion('Code') → 'CCoCodCode'
string_splosion('abc') → 'aababc'
string_splosion('ab') → 'aab'


"""
  
def string_splosion(str):
  sz = len(str)
  repeat = ""
  if(sz > 0):
    for i in range(sz+1):
      j = 0
      for j in range(i):
        repeat += str[j]
    
    return repeat


def string_splosion(str):
  sz = len(str)
  repeat = ""
  if(sz > 0):
    for i in range(sz+1):
        repeat += str[:i]
    
    return repeat
    
    
"""

Warmup-2 > last2

Given a string, return the count of the number of times that a substring length 2 appears in the string 
and also as the last 2 chars of the string, so "hixxxhi" yields 1 (we won't count the end substring).


last2('hixxhi') → 1
last2('xaxxaxaxx') → 1
last2('axxxaaxx') → 2

"""

def last2(str):
  sz = len(str)
  if(sz < 2):
    return 0
  
  post = str[sz-2:]
  
  cnt_appear = 0
  
  for i in range(sz-2):
    if(post == str[i] + str[i+1]):
      cnt_appear += 1
      
  
  return cnt_appear


"""

Warmup-2 > array_count9

Given an array of ints, return the number of 9's in the array.


array_count9([1, 2, 9]) → 1
array_count9([1, 9, 9]) → 2
array_count9([1, 9, 9, 3, 9]) → 3

"""

def array_count9(nums):
  cnt9 = 0
  
  for nums in nums:
    if(nums == 9):
      cnt9 += 1
      
  return cnt9
  

"""
Warmup-2 > array_front9

Given an array of ints, return True if one of the first 4 elements in the array is a 9. The array length may be less than 4.


array_front9([1, 2, 9, 3, 4]) → True
array_front9([1, 2, 3, 4, 9]) → False
array_front9([1, 2, 3, 4, 5]) → False
"""
  
def array_front9(nums):
  sz = 4
  sz_arr = len(nums)
  
  if(sz_arr < sz):
    sz = sz_arr
      
  for i in range(sz):
    if(nums[i] == 9):
      return True
        
  return False
  
"""

Warmup-2 > array123

Given an array of ints, return True if the sequence of numbers 1, 2, 3 appears in the array somewhere.


array123([1, 1, 2, 3, 1]) → True
array123([1, 1, 2, 4, 1]) → False
array123([1, 1, 2, 1, 2, 3]) → True

"""
  
def array123(nums):
  sz = len(nums)
  for i in range(sz-2):
    if(nums[i] == 1 and nums[i+1] == 2 and nums[i+2] == 3):
      return True
  
  return False
  
  
  
"""

Warmup-2 > string_match

Given 2 strings, a and b, 
return the number of the positions where they contain the same length 2 
substring. So "xxcaazz" and "xxbaaz" yields 3, 
since the "xx", "aa", and "az" substrings appear in the same place in 
both strings.


string_match('xxcaazz', 'xxbaaz') → 3
string_match('abc', 'abc') → 2
string_match('abc', 'axc') → 0

"""
  
def string_match(a, b):
  cntSame = 0
  
  sz_a = len(a)
  sz_b = len(b)
  
  sz = sz_a
  arr = a
  other_arr = b
  
  if(sz_b < sz):
    sz = sz_b
  
    
  for i in range(sz-1):
    if arr[i:i+2] == other_arr[i:i+2] :
      cntSame += 1
      
  return cntSame


  

