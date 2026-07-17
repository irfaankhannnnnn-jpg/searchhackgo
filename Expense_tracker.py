expenses = []

n = int(input("Enter the number of expenses: "))

for i in range(n):
  name = input(f"{i+1}.Enter the name of expense: ")
  amount = float(input(f"{i+1}.Enter the amount: "))
  expenses.append((name, amount))


max_expense = max(expenses, key=lambda x: x[1])
min_expense = min(expenses, key=lambda x: x[1])
total_expense = sum(item[1] for item in expenses)
sorted_expense = sorted(expenses, key=lambda x: x[1], reverse=True)


print(f"Maximum expense: {max_expense}")
print(f"\nMinimum expense: {min_expense}")
print(f"\nSorted expense: {sorted_expense}")
print(f"\nTotal expense: {total_expense}")


with open("expenses.txt", "w") as f:
  f.write(str(expenses))
  f.write("\nMaxium expense: " + str(max_expense))
  f.write("\nMinimum expense: " + str(min_expense))
  f.write("\nSorted expense: " + str(sorted_expense))
  f.write("\nTotal expense: " + str(total_expense))

print("Data has been saved in 'expenses.txt'")