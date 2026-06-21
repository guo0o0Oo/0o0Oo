ans=0
n=1
input(n)
for i in range(2,n):
    ans=ans*i
    if i%2==1:
        ans=ans-1
    else:
        ans=ans+1
print(ans)