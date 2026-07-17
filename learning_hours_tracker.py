import datetime


try:
    with open("hours.txt", "r") as f:
        data = eval(f.read())

        if isinstance(data, list):
            data = {}
except FileNotFoundError:
    data = {}


today = str(datetime.date.today())
user_hour = int(input(f"Enter today's learning hours for {today}:"))
data[today] = user_hour


total = sum(data.values())
print(f"\nTotal hours till now: {total}")
print(f"Your Log:", data)


# -----File saving process-----
with open("hours.txt", "w") as f:
    f.write(str(data))


print("Saved!")


