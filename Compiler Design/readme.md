Compiler Design Lab
=====

1. lex.txt
2. Regex Parser
3. DFA
4. [Mealy Machine](#mealy)
5. [Moore Machine](#moore)
6. NFA to DFA


## <a name="mealy"></a> Mealy Machine

Input Structure:

```
initial state
distinct states
distinct inputs
output(i) next_state(i) for each state
```

The dictionary which is created in memory.

```
{
    "q1": {
        "0": {
            "out": <value>,
            "state": <value>
        },
        "1": {
            "out": <value>,
            "state": <value>
        }
    },
    "q2": {
        "0": {
            "out": <value>,
            "state": <value>
        },
        "1": {
            "out": <value>,
            "state": <value>
        }
    }
}
```

## <a name="mealy"></a> Mealy Machine

Input Structure:

```
initial state
distinct states
state outputs
distinct inputs
next_state(i) fixed_output(i) for each state
```

The dictionary which is created in memory.

```
{
    "q1": {
        "0": {
            "out": <value>,
            "state": <value>
        },
        "1": {
            "out": <value>,
            "state": <value>
        }
    },
    "q2": {
        "0": {
            "out": <value>,
            "state": <value>
        },
        "1": {
            "out": <value>,
            "state": <value>
        }
    }
}
```
