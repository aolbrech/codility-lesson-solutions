# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    
    xorTotal = A[0]
    for index in range(1, len(A)):
        xorTotal = xorTotal^A[index]
    return xorTotal

A = [9, 3, 9, 3, 9, 7, 9]
print "The unpaired element in this list is:", solution(A)

corrAnsw = 7
if solution(A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
