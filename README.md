# Hasing Strings

All SI session info on [csc3102si.rohankadkol.com](https://csc3102si.rohankadkol.com)

## Intro

**[SI session recording](https://lsu.zoom.us/rec/share/osWc5VtLPKqo0EzFmx-7B8KU8dYwzluwxQpRQFLJvfVk4YPORxIhFYh4RMwaSxhV.jh14Vy4pCPJYv9tI)**

This is a code example to hash strings using the Horner's rule. For more information, refer to slide 13 of Dr Shah's slide deck, "3102 14 2020 (Hashing)" under the Moodle section, "Hashing".

Also you can **[watch the recording](https://lsu.zoom.us/rec/share/osWc5VtLPKqo0EzFmx-7B8KU8dYwzluwxQpRQFLJvfVk4YPORxIhFYh4RMwaSxhV.jh14Vy4pCPJYv9tI)** where I explain the algorithm and each line of code in detail.

## To run the code (Linux / MacOS)

```
./main < textFile.txt
```

## Sample Text File

```
the fox Fox Fox jumps jumps jumps in in in a cart jumps ,,./, steal the
```

## Sample Output

```
$ ./main < textFile.txt 
**
hashAddress = 27
Word: in, Frequency: 3
Word: Fox, Frequency: 2
**
hashAddress = 38
Word: cart, Frequency: 1
**
hashAddress = 59
Word: fox, Frequency: 1
**
hashAddress = 85
Word: jumps, Frequency: 4
**
hashAddress = 97
Word: a, Frequency: 1
**
hashAddress = 126
Word: steal, Frequency: 1
**
hashAddress = 132
Word: the, Frequency: 2
```