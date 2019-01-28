# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S, P, Q):
    # write your code in Python 3.6
    dictIF = {'A':1, 'C':2, 'G':3, 'T':4}

    prefixSum = [[0 for x in range(4)] for y in range(len(S)+1)]
    for index in range(len(S)):
        IF = dictIF[S[index]]
        prefixSum[index+1] = list(prefixSum[index])    #Python variables are all pointers!!!
        prefixSum[index+1][IF-1]+=1

    minIF = [4]*len(P)
    for index in range(len(P)):
        for i in range(4):
            if prefixSum[Q[index]+1][i]-prefixSum[P[index]][i] != 0:
                minIF[index] = min(minIF[index], i+1)

    return minIF

P = [2, 5, 0]
Q = [4, 5, 6]
S = "CAGCCTA"
print "The minimal nucleotide from a range of sequence DNA is:", solution(S, P, Q)

corrAnsw = [2, 4, 1]
if solution(S, P, Q) != corrAnsw:
  print "WRONG SOLUTION!"
else:
  print "Correct solution found!"
