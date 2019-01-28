# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, K):
    # write your code in Python 3.6
    
    newVector = [0]*len(A)
    for index in range(len(A)):
        newVector[(index+K)%len(A)] = A[index]

    return newVector

A = [3, 8, 9, 7, 6]
K = 3
print "After rotating array",A,"",K,"times, we obtain:",solution(A, K)

corrAnsw = [9, 7, 6, 3, 8]
if solution(A, K) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
