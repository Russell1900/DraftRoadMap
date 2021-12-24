# PANDAS

## Series

```python
#! /usr/bin/python3
import pandas as pd
# pandas.Series(data, index, name, dtype, ...)
a = list(range(10))
sr = pd.Series(a)
print(sr)

idx = list('abcdefghij')
sr = pd.Series(a, index=idx)
print(sr)

print(sr[5])
print(sr['c'])

b = dict(zip(idx, a))
sr = pd.Series(b)
print(sr)

sr = pd.Series(b, name='My Series', dtype=float)
print(sr)

print(sr[0:2]) # 切片 0，1两行，相当于[0,2[
```

## Data Frame

DataFrame，可以视为多个Series的数组，每个Series为一列。

初始化时，使用二位数组，则每个子数组为一行；使用字典的数组，每个数组元素为一个字典，字典key为列名（df中没有的话则添加，有的话使用已有的），value为新建行的对应列的值；若使用数组的字典，每个key是列名，value时列值。

访问DF时，访问列：df[col],可以使用默认1234...，也可以使用列名；访问行：df.loc['row']，不能使用默认的01234...

```python
#! /usr/bin/python3
import pandas as pd

# pandas.DataFrame(data, index, columns, dtype, copy)
# data: ndarry, series, map, lists, dict ...
# copy: 拷贝数据，默认false
a = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
df = pd.DataFrame(a)
print(df)

df = pd.DataFrame(a, index=list('abc'), columns=list('xyzv'))
print(df)

a = {'a':[1,2,3], 'b': [11,12,13]}
df1 = pd.DataFrame(a)
print(df1)

print('------')
print(df)
print('---访问列---')
print(df['x']) # 必须使用当前列id，不支持默认的01234，除非没有设置列id
print(df['x'][0])
print(df[0:2]) # 列切片，返回所有列的前两个元素（相当于0，1两行），切片只能使用数字id
print('---访问行---') # df.loc[index, colowns]
print(df.loc['a'])  # 必须使用当前行id，不支持默认的01234，除非没有设置行id
print(df.loc['a'][1])
print(df.loc['a','x'])

print('使用数字idx')
print(df)
print(df.iloc[1,2])
print(df.iloc[0:2,1:3]) # 切片
```

## 与CSV交互

```python
import pandas as pd

df = pd.read_csv('nba.csv')
df.to_csv('nba.csv')
```

## 与json交互

```python
#! /usr/bin/python3
import pandas as pd
import json
data =[
    {
      "id": "A001",
      "name": "菜鸟教程",
      "url": "www.runoob.com",
      "likes": 61
    },
    {
      "id": "A002",
      "name": "Google",
      "url": "www.google.com",
      "likes": 124
    },
    {
      "id": "A003",
      "name": "淘宝",
      "url": "www.taobao.com",
      "likes": 45
    }
]
df = pd.DataFrame(data)

print(df)


URL = 'https://static.runoob.com/download/sites.json'
df = pd.read_json(URL)
print(df)

# 使用pd.json_normalize, 会将record_path中的数据组成df，舍弃其他数据，如果meta制定了其他数据，也会一起组成df，但是meta指定的数据列应该在record_path之外。
# glom 模块也可以一起使用来读取json，有一些高级功能
data = {
    "school_name": "ABC primary school",
    "class": "Year 1",
    "students": [
    {
        "id": "A001",
        "name": "Tom",
        "math": 60,
        "physics": 66,
        "chemistry": 61
    },
    {
        "id": "A002",
        "name": "James",
        "math": 89,
        "physics": 76,
        "chemistry": 51
    },
    {
        "id": "A003",
        "name": "Jenny",
        "math": 79,
        "physics": 90,
        "chemistry": 78
    }]
}

df = pd.DataFrame(data)
print(df)

df = pd.json_normalize(data, record_path=['student'], meta= ['school_name', 'class'])
print(df)
```

## 清洗数据

https://www.runoob.com/pandas/pandas-cleaning.html