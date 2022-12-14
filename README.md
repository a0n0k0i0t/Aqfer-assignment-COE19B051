# Aqfer-assignment-COE19B051
## Ratelimiter program C++ implementation

### To build & run:   
```
g++ ratelimiter.cpp -o ratelimiter
./ratelimiter 2 5 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
```

### Runtime environment
g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
cpp (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

### Sample input and output
```
./ratelimiter 2 5 1 2 4 5 6 7 8 9   
1 allowed
2 allowed
4 blocked
5 blocked
6 blocked
7 allowed
8 allowed
9 blocked
./ratelimiter 2 7 1 2 4 5 6 7 8 9
./ratelimiter 3 5 1 2 4 5 6 7 8 9
./ratelimiter 2 7 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
./ratelimiter 3 5 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
./ratelimiter 3 7 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
```
