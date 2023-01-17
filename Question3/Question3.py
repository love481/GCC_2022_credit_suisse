def solution(N,M,P):
    j=0
    FOUND=1
    while j+1<N:
        if (P[j+1]-P[j])<0:
            sum_value=P[j+1]+P[j]
            if sum_value<=M:
                P[j:j+2]=list(reversed(P[j:j+2]))
            else:
                FOUND=0
                break
        else:
            FOUND=1
        j+=1
    return FOUND

def main():
    N,M=map(int,input().split())
    P=list(map(int,input().split()))
    print(solution(N,M,P))
  

if __name__ == '__main__':
    main()
