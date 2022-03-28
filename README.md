# Mandelbrot
A small mandelbrot set renderer in C and SDL


# Theory

The famous Mandelbrot set is a set of points in the complex plane. In essence, what we want to find out is if the iterative function C below will converge to some constant or diverge to infinity.

The function is

`C_{n+1} = C_{n}^2 + C_{0}`

with the initial condition simply formed by taking the coordinates in the complex plane,

`C_{0} = x + iy`

Looking at the function, one can easily see that for big initial values, the function should diverge. But for values close to origo (i.e., for |x| and |y| less than 1), we would expect the function to converge to zero, since the product of two numbers less than one will always be less than either of the factors (e.g., 0.5 x 0.4 = 0.2, which is less than both factors).

But if we actually plot it, what we get out isn't any nice plot. Instead, we get an amazingly complex and fractured plot. This is the Mandelbrot set.

You can zoom forever into the plot, and it will present you with an unending complex shape. One can also calculate it's so-called Hausdorff dimension, which yields a noninteger number. Thus, it's a fractal.

![image](https://user-images.githubusercontent.com/56733438/160474613-1fb914f4-6853-4cf3-9508-a16d5919855f.png)
