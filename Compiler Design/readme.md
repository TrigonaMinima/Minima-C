Compiler Design Lab
=====

1. lex.txt
2. Regex Parser
3. DFA
4. [Mealy Machine](#mealy)
5. Moore Machine
6. NFA to DFA


## <a name="mealy"></a> Mealy Machine

Input Structure:

```
initial state
distinct states
distinct inputs
output(i) state(i) for each state
```

The dictionary which is created in memory.

```
{
    q1: {
        0: {
            "out": <value>,
            "state": <value>
        },
        1: {
            "out": <value>,
            "state": <value>
        }
    },
    q2: {
        0: {
            "out": <value>,
            "state": <value>
        },
        1: {
            "out": <value>,
            "state": <value>
        }
    }
}
```