import math

list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

c=0


def create_board(list):
    print("\n\n")
    for i in range(3):
        for j in range(3):
            print("     ",list[i][j],"     ",end="|")
        print("\n-------------------------------------------\n")


def check_winner(list):
    for i in range(3):
        if(list[i][0]==list[i][1] and list[i][1]==list[i][2]):
            return True
        elif(list[0][i]==list[1][i] and list[1][i]==list[2][i]):
            return True
    x=list[0][0]
    y=list[0][2]
    count=0
    count1=0
    for i in range(3):
        for j in range(3):
            if(i==j and list[i][j]==x):
                    count=count+1
            if(i+j==2 and list[i][j]==y):
                    count1=count1+1
    if(count==3 or count1==3):
        return True
    return False

def play(k,i):
    n=k//3
    m=(k%3)
    if(list[n][m]=='x'or list[n][m]=='o'):
        print("Player",i,"Already placed")
        c=c-1
    else:
        if(i==1):
            list[n][m]='x'
        else:
            list[n][m]='o'




while(1):
    create_board(list)
    print("Player",c%2+1,"chance to play\n")
    print("Enter position value from 1 to 9\n")
    x=int(input())
    play(x,c%2+1)

    if(check_winner(list)):
        create_board(list)
        print("Player",c%2+1,"won")
        break
    c=c+1
    if(c==9):
        print("its a draw")
        break
    


        

