# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import math

def solution(A, B, K):
    # write your code in Python 3.6
        
    divLowerValue = math.ceil(A/K)*K
    divUpperValue = math.floor(B/K)*K
    
    return int((divUpperValue-divLowerValue)/K+1)

A = 6
B = 11
K = 2
print "The number of integers divisible by", K, "between",A, "and", B, "is:", solution(A, B, K)

corrAnsw = 3
if solution(A, B, K) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
