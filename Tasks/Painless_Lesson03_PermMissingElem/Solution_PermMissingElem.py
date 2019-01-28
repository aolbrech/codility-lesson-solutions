# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    sumUsingMaxElem = int(max(A)*(max(A)+1)/2)
    sumOfArray = 0
    for value in A:
        sumOfArray+=value
    
    if sumOfArray != sumUsingMaxElem:
        return int(sumUsingMaxElem-sumOfArray)
    return len(A)+1

A = [2, 3, 1, 5]
print "The missing element in array", A, "is:", solution(A)

corrAnsw = 4
if solution(A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
