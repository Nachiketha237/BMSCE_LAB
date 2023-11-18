def bubble_sort(list_item):
    for i in range(len(list_item)):
        for j in range(i+1,len(list_item)):
             if(list_item[i]>list_item[j]):
                  temp= list_item[i]
                  list_item[i]= list_item[j]
                  list_item[j]=temp
    return list_item
                                
  
k=(input("enter the size:"))
list_item=[]
print("Enter the elements")
for j in range(int(k)):  # A for loop for column entries  
        list_item.append(int(input()))
list_item=bubble_sort(list_item)
print(list_item)
