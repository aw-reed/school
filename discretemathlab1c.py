# More Even and Odd
first = int(input("Enter Whole Number (1/10): "))
second = int(input("Enter Whole Number (2/10): "))
third = int(input("Enter Whole Number (3/10): "))
fourth = int(input("Enter Whole Number (4/10): "))
fifth = int(input("Enter Whole Number (5/10): "))
sixth = int(input("Enter Whole Number (6/10): "))
seventh = int(input("Enter Whole Number (7/10): "))
eigth = int(input("Enter Whole Number (8/10): "))
ninth = int(input("Enter Whole Number (9/10): "))
tenth = int(input("Enter Whole Number (10/10): "))

if first%2 == 0:
    first = 0
else:
    first = first
if second%2 == 0:
    second = 0
else:
    second = second
if third%2 == 0:
    third = 0
else:
    third = third
if fourth%2 == 0:
    fourth = 0
else:
    fourth = fourth
if fifth%2 == 0:
    fifth = 0
else:
    fifth = fifth
if sixth%2 == 0:
    sixth = 0
else:
    sixth = sixth
if seventh%2 == 0:
    seventh = 0
else:
    seventh = seventh
if eigth%2 == 0:
    eigth = 0
else:
    eigth = eigth
if ninth%2 == 0:
    ninth = 0
else:
    ninth = ninth
if tenth%2 == 0:
    tenth = 0
else:
    tenth = tenth

number = first, second, third, fourth, fifth, sixth, seventh, eigth, ninth, tenth

max = max(number)
if max == 0:
    print("No odd numbers were entered.")
else:
    print(max, "is the largest odd number inputted.")
