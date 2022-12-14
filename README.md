# Aqfer-assignment-COE19B051
## Ratelimiter program C++ implementation
### Problem Statement
Create a rate limiter program using a sliding window which allows/blocks request based on timestamps. Program will receive sequence of timestamps via arguments. For each timestamp it has to output allowed/blocked based on the sliding window.
Sliding window to have 2 configurations,   
R: maximum number of requests allowed in sliding window   
S: sliding window time period in seconds   
   
Program arguments   
Rate Limiter program to accept 3 or more arugments   
0th argument is for specifying R   
1st argument is for specifying S   
2nd argument onwards for specifying sequence of timestamps in ascending   
### To build & run:   
```
g++ ratelimiter.cpp -o ratelimiter
./ratelimiter 2 5 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
```

### Runtime environment
`g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0`   
`cpp (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0`

### Sample input and output

Normal cases
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
1 allowed
2 allowed
4 blocked
5 blocked
6 blocked
7 blocked
8 blocked
9 allowed

./ratelimiter 3 5 1 2 4 5 6 7 8 9
1 allowed
2 allowed
4 allowed
5 blocked
6 blocked
7 allowed
8 allowed
9 blocked
```
Corner cases
```
./ratelimiter 7 4 1 2 4 5 6 7 8 9
1 allowed
2 allowed
4 allowed
5 allowed
6 allowed
7 allowed
8 allowed
9 allowed

./ratelimiter 3 0 1 2 4 5 6 7 8 9
1 allowed
2 allowed
4 allowed
5 allowed
6 allowed
7 allowed
8 allowed
9 allowed

./ratelimiter 0 4 1 2 4 5 6 7 8 9
1 blocked
2 blocked
4 blocked
5 blocked
6 blocked
7 blocked
8 blocked
9 blocked

./ratelimiter 0 0 1 2 4 5 6 7 8 9
1 blocked
2 blocked
4 blocked
5 blocked
6 blocked
7 blocked
8 blocked
9 blocked

./ratelimiter 3 4 100 200 300 400 500 600 700 800
100 allowed
200 allowed
300 allowed
400 allowed
500 allowed
600 allowed
700 allowed
800 allowed
```
With unix timestamp
```
./ratelimiter 2 7 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
1671023342 allowed
1671023343 allowed
1671023345 blocked
1671023346 blocked
1671023347 blocked
1671023348 blocked
1671023349 blocked
1671023350 allowed

./ratelimiter 3 5 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
1671023342 allowed
1671023343 allowed
1671023345 allowed
1671023346 blocked
1671023347 blocked
1671023348 allowed
1671023349 allowed
1671023350 blocked

./ratelimiter 3 7 1671023342 1671023343 1671023345 1671023346 1671023347 1671023348 1671023349 1671023350
1671023342 allowed
1671023343 allowed
1671023345 allowed
1671023346 blocked
1671023347 blocked
1671023348 blocked
1671023349 blocked
1671023350 allowed
```
### Logic

Maintain a queue to store currently allowed timestamps max upto R.   
At each timestamp
```
if queue_size<R: //if currently less than R timestamp allowed in window
  "timestamp allowed"
  queue.push(cur_timestamp)
else:
  cur_timestamp-s >queue_front: // if cur_timestamp is outside window
    "tiemstamp allowed"
    queue.pop()
    queue.push(cur_timestamp)
  else:
    "timestamp blocked"
  ```
### Time and Space Complexity
Time complexity: $O$(1) per timestamp   
Space complexity: $O$(R)
