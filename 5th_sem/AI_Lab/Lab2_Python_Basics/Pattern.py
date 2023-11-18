def pattern(m):
    k=int(m)+1
    for i in range(1,k):
        for j in range(k-i):
          print("  ",end="")
        for n in range(i):
          print(i,end="   ")
        print("\n")


k=input("Enter the number between 1 to 10:\n")
pattern(k)

