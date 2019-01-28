# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    
    sumArray = [A[0]]*len(A)
    for index in range(1,len(A)):
        sumArray[index] = sumArray[index-1]+A[index]

    minDiff = abs(2*sumArray[0]-sumArray[-1])
    for index in range(0, len(sumArray)-1):
        minDiff = min(minDiff, abs(2*sumArray[index]-sumArray[-1]))
    return minDiff

A = [3, 1, 2, 4, 3]
print "The minimal difference that can be achieved when splitting array", A, "is", solution(A)

corrAnsw = 1
if solution(A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
