# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    
    if len(A) != max(A):
        return 0
    
    sumArray = 0
    for index in range(len(A)):
        value = A[index]
        if abs(value) <= len(A):
            if A[abs(value)-1] < 0:    #Dealing with a value already encountered in list
                return 0
            A[abs(value)-1] = -A[abs(value)-1]
        else:
            return 0
        sumArray += abs(A[index])
    if sumArray != int(((len(A)+1)*len(A))/2):
        return 0
    
    return 1

A = [4, 1, 3, 2]
if solution(A) == 1:
  print "Dealing with a permutation!"
else:
  print "Not dealing with a permutation"
