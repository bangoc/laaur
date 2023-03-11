import sys
import time
if len(sys.argv) != 3:
  print("Usage: python sel-sort.py input.txt output.txt")
  exit()

lst = []
n = 0
inp = open(sys.argv[1], "r")
n = int(inp.readline())
for line in inp:
  line = line.split()
  if line:
    for i in line:
      lst.append(int(i))

start = time.process_time()
for i in range(0, n - 1):
  for j in range(i + 1, n):
    if (lst[i] > lst[j]):
      tmp = lst[i]
      lst[i] = lst[j]
      lst[j] = tmp
end = time.process_time()
print(f'Thời gian xử lý: {end - start: .3f} s')

out = open(sys.argv[2], "w")
for x in lst:
  out.write(str(x) + " ")