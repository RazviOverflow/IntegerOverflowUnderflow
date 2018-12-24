# Integer overflow and underflow 

### There's a little script that shows in realtime what happens when you sum something to singed integer max value or when you subtract something from signed integer min value. 

To ease the understanding, I recommend you to targer the compilation to a 32bit architecture machine. 

```
gcc integerTests.c -o integerTest -m32
```