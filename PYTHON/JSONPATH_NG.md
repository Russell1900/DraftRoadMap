# JSONPATH

https://yuz.one/post/jsonpath-ng-jiao-cheng/

## JSONPATH v.s. XPATH

| **XPath** | **JSONPath**      | **Description**                                              |
| --------- | ----------------- | ------------------------------------------------------------ |
| /         | $                 | the root object/element                                      |
| .         | @                 | the current object/element                                   |
| /         | . or []           | child operator                                               |
| ..        | n/a               | parent operator                                              |
| //        | ..                | recursive descent. JSONPath borrows this syntax from E4X.    |
| *         | *                 | wildcard. All objects/elements regardless their names.       |
| @         | n/a               | attribute access. JSON structures don't have attributes.     |
| []        | []                | subscript operator. XPath uses it to iterate over element collections and for [predicates](http://www.w3.org/TR/xpath#predicates). In Javascript and JSON it is the native array operator. |
| \|        | [,]               | Union operator in XPath results in a combination of node sets. JSONPath allows alternate names or array indices as a set. |
| n/a       | [start:end :step] | array slice operator borrowed from ES4.                      |
| []        | ?()               | applies a filter (script) expression.                        |
| n/a       | ()                | script expression, using the underlying script engine.       |
| ()        | n/a               | grouping in Xpath                                            |

## sample

```python
#! /usr/bin/python3
from typing import Match
from jsonpath_ng import jsonpath, parse
import json

data = '''
{
    "a": {
        "a": 1,
        "b": 2,
        "x": {
            "a": 3
        }
    },
    "b": ["a", "b"]
}
'''
data = json.loads(data)
print(data)
jsonpath_expr = parse('$..a')
res = jsonpath_expr.find(data)
print(res)
print('----')
for r in res:
    print(r.context)
    print(r.value)
print('----')
# val = jsonpath_expr.find(data)[0].value
jsonpath_expr.update(data, 'asd')
print(json.dumps(data, indent=2))
```

