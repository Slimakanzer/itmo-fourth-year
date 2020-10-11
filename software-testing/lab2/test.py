second = """0.02 -26465.8
0.1 -675.99
0.2 -60.0068
0.3 -8.64993
0.4 -0.999078
0.5 0.487504
0.55 0.714449

0.6 0.826229
0.7 0.909484
0.8 0.928675
0.9 0.931799

1.0 NAN

1.05 0.931952
1.1 0.931852
1.15 0.931464
1.2 0.930531

1.3 0.92594
1.5 0.900074
1.75 0.836129

1.8 0.821522
1.9 0.794358
2.0 0.774356

2.0884971449233825358269495952366013421428061969691576000370777169 0.76756354102375411049030346684527510737400057387717261292998154511104

2.1 0.767694
2.5 1.02447
3.0 2.63606
5.0 44.3698
10.0 604.538
20.0 3935.8
100.0 81368.217"""

first = """-0.4 50.2412
-0.7 10.964
-1.15 3.65397

-1.2 3.60465
-1.25 3.65465

-1.3 3.97437
-1.4 5.61428
-1.5 13.4263

-1.7 -9.26823
-1.8 -6.30266
-1.9 -5.40983

-1.95 -5.23951
-2.1 -5.27951

-2.2 -5.61752
-2.5 -8.44473
-2.8 -21.5672
-3.1 -1171.27

-3.2 -580.903
-3.5 -17.4998
-3.8 -7.27089
-4.2 -5.05901

-4.25 -5.04151

-4.3 -5.08678
-4.4 -5.45166
-4.5 -6.5621
-4.6 -10.3553

-4.8 10.7877
-4.9 5.15571
-5.0 3.78871
-5.1 3.41948

-5.15 3.40621

-5.2 3.41623
-5.3 3.74355
-5.4 4.16767
-5.5 4.66807
-5.6 5.12033

-5.65 5.24277

-5.7 5.13277
-5.8 3.89952
-6.0 -29.835
-6.2 -2866.63"""

import os;
import math 

def writeExpected(f, function, number, expected):
    f.write("when(")
    f.write(function)
    f.write("(")
    f.write(number)
    f.write(")).thenReturn(")
    f.write(str(expected))
    f.write(");\n")

def writeExpectedBasic(f, function, number, expected):
    f.write("when(")
    f.write(function)
    f.write("(")
    f.write(number)
    f.write(", precision)).thenReturn(")
    f.write(str(expected))
    f.write(");\n")

def writeLogs(f, number):
    floatNumber = float(number)
    writeExpected(f, "lf.ln", number, math.log(floatNumber))
    writeExpected(f, "lf.log_2", number, math.log(floatNumber, 2))
    writeExpected(f, "lf.log_3", number, math.log(floatNumber, 3))
    writeExpected(f, "lf.log_5", number, math.log(floatNumber, 5))
    writeExpected(f, "lf.log_10", number, math.log(floatNumber, 10))

def writeTrig(f, number):
    floatNumber = float(number)
    writeExpected(f, "tf.sin", number, math.sin(floatNumber))
    writeExpected(f, "tf.cos", number, math.cos(floatNumber))
    writeExpected(f, "tf.tan", number, math.tan(floatNumber))
    writeExpected(f, "tf.cot", number, math.cos(floatNumber) / math.sin(floatNumber))
    writeExpected(f, "tf.csc", number, 1 / math.sin(floatNumber))
    writeExpected(f, "tf.sec", number, 1 / math.cos(floatNumber))

def writeLogBasic(f, number):
    floatNumber = float(number)
    writeExpectedBasic(f, "math.ln", number, math.log(floatNumber))

def writeTrigBasic(f, number):
    floatNumber = float(number)
    writeExpectedBasic(f, "math.sin", number, math.sin(floatNumber))
    writeExpectedBasic(f, "math.cos", number, math.cos(floatNumber))

with open("simplefunc", 'w') as f:
   lines = second.splitlines()
   for line in lines:
        numbers = line.split()

        if (len(numbers) == 0):
            f.write("\n")
            continue

        number = numbers[0]
        writeLogs(f, number)

   lines = first.splitlines()
   for line in lines:
        numbers = line.split()

        if (len(numbers) == 0):
            f.write("\n")
            continue

        number = numbers[0]
        writeTrig(f, number)

with open("basicfunc", 'w') as f:
   lines = second.splitlines()
   for line in lines:
        numbers = line.split()

        if (len(numbers) == 0):
            f.write("\n")
            continue

        number = numbers[0]
        writeLogBasic(f, number)

   lines = first.splitlines()
   for line in lines:
        numbers = line.split()

        if (len(numbers) == 0):
            f.write("\n")
            continue

        number = numbers[0]
        writeTrigBasic(f, number)
       
       