# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    
    nrCarsTravellingEast = 0
    for value in A:
        nrCarsTravellingEast += value
            
    nrPassingCars = 0
    for value in A:
        if value == 0:
            nrPassingCars += nrCarsTravellingEast
            if nrPassingCars > 1000000000:
                return -1
        else:
            nrCarsTravellingEast -= 1
    
    return nrPassingCars

A = [0, 1, 0, 1, 1]
print "The number of pairs of passing cars is:", solution(A)

corrAnsw = 5
if solution(A) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
