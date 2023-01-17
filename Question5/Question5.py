def solution(cutoffScore, scoresLength, scores):
    BoW = 0
    s,e = 0,0
    sum = scores[0]
    while (s < scoresLength and e < scoresLength):
        if (sum >= cutoffScore):
            sum = sum - scores[s]
            s = s + 1
        else :
            e = e + 1
            if (e < scoresLength):
                sum = sum + scores[e]
 
            if (s<=e):
                inc = e-s
                BoW = BoW + inc
    return BoW

def main():
    cutoffScore = int(input().split()[0])
    scoresLength = int(input().split()[0])
    scores = [int(x) for x in input().split()]
    result = solution(cutoffScore, scoresLength, scores)
    print(result)


if __name__ == '__main__':
    main()
