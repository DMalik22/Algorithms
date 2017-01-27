#implemented a simple 1 line solution to a Hacker rank challenge
#to rotate a given array of length n left by k places
def array_left_rotation(a, n, k):
    return a[-(n-k):] + a[:k]

n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
answer = array_left_rotation(a, n, k);
print(*answer, sep=' ')
