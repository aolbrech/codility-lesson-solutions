# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
    # write your code in Python 3.6
    
    fallenLeaves = [0]*X
    nrLeaves = 0
    for index in range(len(A)):
        value = A[index]
        if fallenLeaves[value-1] == 0:
            fallenLeaves[value-1] = 1
            nrLeaves += 1
        if nrLeaves == X:
            return index
    
    return -1

A = [1, 3, 1, 4, 2, 3, 5, 4]
X = 5
print "The earliest time a leave appears on all positions in the river is: ", solution(X, A)

corrAnsw = 6
if solution(X, A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
