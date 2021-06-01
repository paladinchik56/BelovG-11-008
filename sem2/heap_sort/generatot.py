import random
# lst_10 = [random.randint(0, 100) for _ in range(1000000)]
# lst_100 = [random.randint(0, 100) for _ in range(2000000)]
# lst_1000 = [random.randint(0, 100) for _ in range(3000000)]
# lst_10000 = [random.randint(0, 100) for _ in range(4000000)]
# lst_100000 = [random.randint(0, 100) for _ in range(5000000)]
# lst_1000000 = [random.randint(0, 100) for _ in range(10000000)]
# lst = [lst_10, lst_100, lst_1000, lst_10000, lst_100000, lst_1000000]
lst_1000000 = [random.randint(0, 100) for _ in range(100000000)]
# for i in range(6):
#     with open(f'{i}.txt', 'w') as f:
#         for j in lst[i]:
#             f.write(str(j) + ' ')
with open(f'100000000.txt', 'w') as f:
    for j in lst_1000000:
        f.write(str(j) + ' ')
