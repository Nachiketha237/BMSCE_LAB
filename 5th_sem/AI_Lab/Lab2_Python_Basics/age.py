def Criteria(age1):
    age=int(age1)
    if(age<13):
        return "Kid"
    elif(age<20):
        return "tean"
    elif(age<60):
        return "adult"
    else:
        return "old hag"
    

age = input("Enter the age:")
print("Person is",Criteria(age))
