"""
https://codingbat.com/python/Logic-1

Logic-1 > cigar_party

When squirrels get together for a party, they like to have cigars. 
A squirrel party is successful when the number of cigars is between 40 and 60,
inclusive. Unless it is the weekend, in which case there is no upper 
bound on the number of cigars. Return True if the party with the given 
values is successful, or False otherwise.


cigar_party(30, False) → False
cigar_party(50, False) → True
cigar_party(70, True) → True

inclusive means <=
"""

def cigar_party(n_cigar, isWeekend):
    if(not isWeekend and (n_cigar >= 40 and n_cigar <= 60)):
        return True
    elif(isWeekend and n_cigar >= 40):
        return True
    else:
        return False
        
"""

Logic-1 > date_fashion

You and your date are trying to get a table at a restaurant. 
The parameter "you" is the stylishness of your clothes, in the range 0..10, 
and "date" is the stylishness of your date's clothes. The result getting the 
table is encoded as an int value with 0=no, 1=maybe, 2=yes. If either of you 
is very stylish, 8 or more, then the result is 2 (yes). With the exception 
that if either of you has style of 2 or less, then the result is 0 (no). 
Otherwise the result is 1 (maybe).


date_fashion(5, 10) → 2
date_fashion(5, 2) → 0
date_fashion(5, 5) → 1

"""

def date_fashion(you, date):
    if(you <= 2 or date <= 2):
        return 0
    elif(you >= 8 or date >= 8):
        return 2
    else:
        return 1

"""
Logic-1 > squirrel_play

The squirrels in Palo Alto spend most of the day playing. 
In particular, they play if the temperature is between 60 and 90 (inclusive). 
Unless it is summer, then the upper limit is 100 instead of 90. 
Given an int temperature and a boolean is_summer, 
return True if the squirrels play and False otherwise.


squirrel_play(70, False) → True
squirrel_play(95, False) → False
squirrel_play(95, True) → True
Go...S
"""

def squirrel_play(temp, isSummer):
    if(isSummer and (temp >= 60 and temp <= 100)):
        return True
    elif(not isSummer and (temp >= 60 and temp <= 90)):
        return True
    else:
        return False
        

"""
Logic-1 > caught_speeding

You are driving a little too fast, and a police officer stops you. 
Write code to compute the result, encoded as an int value: 0=no ticket, 
1=small ticket, 2=big ticket. If speed is 60 or less, the result is 0. 
If speed is between 61 and 80 inclusive, the result is 1. 
If speed is 81 or more, the result is 2. Unless it is your birthday -- on 
that day, your speed can be 5 higher in all cases.


caught_speeding(60, False) → 0
caught_speeding(65, False) → 1
caught_speeding(65, True) → 0
"""

def caught_speeding(speed, isBirthday):
  adj_speed = speed
  
  if(isBirthday):
    adj_speed -= 5
        
  if(adj_speed <= 60):
    return 0
  elif(adj_speed >= 61 and adj_speed <= 80):
    return 1
  else:
        return 2
        
"""
Logic-1 > sorta_sum

Given 2 ints, a and b, return their sum. However, sums in the range 10..19 
inclusive, are forbidden, so in that case just return 20.


sorta_sum(3, 4) → 7
sorta_sum(9, 4) → 20
sorta_sum(10, 11) → 21
"""

def sorta_sum(a, b):
  sum = a + b
  if(sum >= 10 and sum <= 19):
    return 20
  else:
    return sum


"""
Logic-1 > alarm_clock

Given a day of the week encoded as 0=Sun, 1=Mon, 2=Tue, ...6=Sat, 
and a boolean indicating if we are on vacation, return a string of the 
form "7:00" indicating when the alarm clock should ring. Weekdays, 
the alarm should be "7:00" and on the weekend it should be "10:00". 
Unless we are on vacation -- then on weekdays it should be "10:00" and 
weekends it should be "off".


alarm_clock(1, False) → '7:00'
alarm_clock(5, False) → '7:00'
alarm_clock(0, False) → '10:00'
"""

def alarm_clock(day, vacation):
  if(day == 0 or day == 6):
    if(vacation):
      return "off"
    else:
      return "10:00"
  else:
    if(vacation):
      return "10:00"
    else:
      return "7:00"


"""
Logic-1 > love6

The number 6 is a truly great number. Given two int values, a and b, return 
True if either one is 6. Or if their sum or difference is 6. 
Note: the function abs(num) computes the absolute value of a number.


love6(6, 4) → True
love6(4, 5) → False
love6(1, 5) → True
"""

def love6(a, b):
    if(a + b == 6 or abs(a-b) == 6 or a == 6 or b == 6):
        return True
    else: 
        return False
"""
Logic-1 > in1to10

Given a number n, return True if n is in the range 1..10, inclusive. 
Unless outside_mode is True, in which case return True if the number is less or equal to 1, 
or greater or equal to 10.


in1to10(5, False) → True
in1to10(11, False) → False
in1to10(11, True) → True
"""

def in1to10(n, outside_mode):
  if(outside_mode):
    if(n <= 1 or n >= 10):
      return True
  else:
    if(n >= 1 and n <= 10):
      return True
      
  return False
  
"""
Logic-1 > near_ten

Given a non-negative number "num", return True if num is within 2 of a multiple of 10. 

Note: (a % b) is the remainder of dividing a by b, so (7 % 5) is 2. See also: Introduction to Mod


near_ten(12) → True
near_ten(17) → False
near_ten(19) → True
"""

def near_ten(num):
  modded = num%10
  
  if(modded <= 2 and modded >= -2 or modded == 8 or modded == 9):
    return True
    
  return False
