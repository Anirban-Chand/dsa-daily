class Solution:
    def fillCups(self, amount: List[int]) -> int:
        ans=0
        while amount[0]>0 or amount[1]>0 or amount[2]>0:
            amount.sort()
            ans+=1
            amount[1]-=1
            amount[2]-=1
        
        return ans
