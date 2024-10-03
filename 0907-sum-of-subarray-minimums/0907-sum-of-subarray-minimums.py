class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        #appending [value,ocuurance,replaces n items]
        total=0
        stack=[]
        for i in arr:
            if not stack:
                stack.append([i,1,0])
                #print(stack[-1])
            else:
                count=0
                while stack and stack[-1][0]>i:
                    a,b,c=stack.pop()
                    total+=(a*(count+b))+(count*c*a)
                    #print(total)
                    count+=b
                stack.append([i,1+count,count])
                #print(stack[-1])
        count=0
        while stack:
            a,b,c=stack.pop()
            #print(a,b,c)
            total+=(a*(count+b))+(count*c*a)
            #print(total)
            count+=b
        m=(10**9)+7
        return total%m

                


        