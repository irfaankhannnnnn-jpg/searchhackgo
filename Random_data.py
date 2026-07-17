data = [
    {'sqft': 1200, 'price': 50_00_000, 'city': 'Chandigarh'},
    {'sqft': 1500, 'price': 75_00_000, 'city': 'Delhi'},
    {'sqft': 1800, 'price': None, 'city': 'Mumbai'}
]

gst = map(lambda g: g['price'] * 0.18 if g['price'] is not None else None, data)

filter_data = filter(lambda g: g['price'] is not None and g['price'] < 75_00_000, data)
sorted_data = sorted(filter_data, key=lambda g: g['price'], reverse=True)

print(list(gst))
print(list(filter_data))
print(list(sorted_data))


with open("hours.txt", "w") as f:
  f.write(str(data))

print("Data has been saved in 'hours.txt'")