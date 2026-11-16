from functools import cache
class Solution:
    @cache
    def uniquePaths(s,m,n):
        return 1 if(m==1)or(n==1)else s.uniquePaths(m-1,n)+s.uniquePaths(m,n-1)