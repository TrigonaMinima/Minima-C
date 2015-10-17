Compiler Design Lab
=====

1. lex.txt
2. Regex Parser
3. [DFA](#dfa)
4. [Mealy Machine](#mealy)
5. [Moore Machine](#moore)
6. [NFA to DFA](#nfa2dfa)


## <a name="dfa"></a> Deterministic Finite Automaton

Input Structure:

```
initial state
distinct states
output states
distinct inputs
output(i) for each input on state
```

The dictionary which is created in memory.

```
{
    "q1": {
        "0": <state>,
        "1": <state>
    },
    "q2": {
        "0": <state>,
        "1": <state>
    }
}
```


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

## <a name="moore"></a> Moore Machine

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

## <a name="nfa2dfa"></a> NFA to DFA Conversion

Input Structure:

```
initial state
distinct states
output states
distinct inputs
output(i) for each input on state
```

The dictionary which is created in memory.

```
{
    "q1": {
        "0": <state>,
        "1": <state>
    },
    "q2": {
        "0": <state>,
        "1": <state>
    }
}
```


