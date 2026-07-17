marks = [20, 28, 35, 40, 67, 83, 96, 99]

pass_stud = filter(lambda x: x>=40, marks)
top_3 = sorted(pass_stud, reverse=True)[:3]
average = sum(top_3) / len(top_3)

print(f"\nPass students: {list(pass_stud)}")
print(f"\nTop 3 students: {top_3}")
print(f"\nAverage of top 3 students: {average}")


with open("marks.txt", "w") as f:
  f.write(str(marks))
  f.write("\nPass students: " + str(list(pass_stud)))
  f.write("\nTop 3 students: " + str(top_3))
  f.write("\nAverage of top 3 students: " + str(average))

print("Data has been printed in 'marks.txt'")