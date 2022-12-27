t = int(input())
for abcd in range(t):
  n = int(input())
  arr=[]
  temp=input()
  arr=temp.split(' ')
  print(arr)
  for i in range(n):
    arr[i]=int(arr[i])
  for i in range(n):
    temp=input()
    temp=temp.split(' ')
    nOper=int(input())
    oper=input()
    for el in oper:
      if el=='D':
        arr[i]=arr[i]+1
        arr[i]=arr[i]%10
      else:
        arr[i]=arr[i]-1
        if arr[i]<0:
          arr[i]=arr[i]+10

  print(arr)

