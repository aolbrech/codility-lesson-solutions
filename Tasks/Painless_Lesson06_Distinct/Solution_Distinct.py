# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    
    if len(A) < 2:
        return len(A)
    
    A.sort()            #O(N*log(N))

    nrDistinctElems = 1
    for index in range(1, len(A)):
        if A[index] != A[index-1]:
            nrDistinctElems+=1
    return nrDistinctElems

A = [2, 1, 1, 2, 3, 1]
print "The number of distinct values in the array", A, "is:", solution(A)

corrAnsw = 3
if solution(A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
