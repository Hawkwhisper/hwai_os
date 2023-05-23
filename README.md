# About

This is just a fun challenge... It originally started with NodeJS - I'm trying to recreate A.I without any documentation or videos of any kind to show me the way, I'm only allowed to use the limited knowledge I have on Neural Networks in actual brains and whatnot, it's been fun! I've been going ham on C language for the past week or 2 and I'm comfortable enough with it now to really move things along. As such I'm making it open source ^.^

`run.sh` is a shell script that runs this;

Required:
Linux... this uses libx11, so if you're on windows be sure to use WSL with an x window service or windows 11's built in linux gui handler thing...

All reqs: (see src/main.h)

X11/Xlib.h
X11/Xutil.h
X11/Xos.h
stdio.h
stdarg.h
stdlib.h
stdbool.h
string.h
assert.h
pthread.h
locale.h
wchar.h
termios.h
unistd.h
sys/sysinfo.h
sys/resource.h
sys/ioctl.h
errno.h

---

## Neural Algorithm
Variable map:

- bce<hr>Brains current energy levels<br>$Min^|Max\left ( { \frac{0.000000000000000}{1.000000000000000}} \right )$
- nc <hr> Neural Count, how many neurons there are within the brain container thing
- rpi<hr> a random between 0 and 2×π
- e <hr> Effeciency of this neuron (calculated by $ distance $)
- lo <hr> The amount of outputs this neuron currently has
- oe <hr> Output node's effeciency
- d <hr> Distance between the 2 neurons
- ie <hr> The input node's effeciency of the receiving neuron
- sx, sy, sz <hr> Self neuron - the one doing this's x y and z position in the brain
- cx, cy, cz <hr> Connecting neuron - the neuron the current output node is connected to's x, y and z position in the brain


    The above variables are used for this algorithm, which each neuron processes every tick:
<style>.d{zoom:2}</style>
<div class='d'>

$$
\frac{1}{\left(\frac{bce}{\sqrt{nc}}+cos(rpi)\right)\cdot\left(\frac{\frac{e}{lo+oe}}{sin(rpi)}\cdot\frac{ie}{oe}d\right)}
$$

</div>

^ <b>I COULD BE WRONG</b> on this visualization... I suck at irl math, and I had a friend (emi) help me out with this one.

The algorithm in code

```c
//split
float results =
        1 / 
        (
            bce / sqrt(nc) + cos(rpi[0]) *
            (
                (
                    e / 
                    (
                        lo + le
                    ) / sin(rpi[1])
                ) * (
                    d * (ie / oe)
                )
            )
        );

//Compact:
1 / (bce / sqrt(nc) + cos(rpi[0]) *((e / (lo + le) / sin(rpi[1])) * (d * (ie / oe))));
```
### This is likely to change
---
