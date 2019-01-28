# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    
    if len(A) < 3:
        return 0
        
    A.sort()
    
    #When all values are negative the smallest negative value should be returned
    return max(A[-1]*A[-2]*A[-3], A[-1]*A[0]*A[1])

A = [-3, 1, 2, -2, 5, 6]
print "The maximal product of any triplet is:", solution(A)

corrAnsw = 60
if solution(A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
