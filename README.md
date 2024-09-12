<div align=center>
	<h1>
		<i>Fract-ol</i>
	</h1>
	<img src=https://github.com/AnaVolkmann/42_project_badges/blob/main/badges/fract-olm.png alt=fract-ol_badge/>
	<p align=center>
    		In this repository, you can accsess the code created for the Fract-ol project, mandatory and bonus part.
	</p>

---

<h2>
		Final score
	</h2>
	<img src=https://github.com/AnaVolkmann/AnaVolkmann/blob/main/fractol%20score alt=fractol_grade/>

---

<p><b>The <code>fract-ol</code> project from the 42 School is one of the three "beginner" graphical projects of the cursus. It teaches you about manipulating a low-level graphic library, advanced math, and more.</b></p>

<img src=https://github.com/AnaVolkmann/AnaVolkmann/blob/main/mandelbrot_opening.png alt=fract-ol_opening/>

  
<h3>
		What is a fractal?
</h3>
 </h4>
A fractal is an infinitely complex pattern that repeats at different scales, created through a simple, recursive process. 
These patterns, often linked to chaos, exist between familiar dimensions. Fractals are common in nature, appearing in trees, 
rivers, coastlines, mountains, clouds, and hurricanes.
Abstract fractals, like the Mandelbrot Set, can be generated by computers through repeated calculations of equations.
  </h4>
</div>

--- 

## 👨‍💻 Usage

### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

* **Clone** the repository

	```bash
	git clone https://github.com/AnaVolkmann/42_FRACTOL.g
	```

* To **compile** the program, run the following command

	```bash
	make
	```

* To **execute** the program, use the following command

	```bash
	./fractol <fractal>
	```

> Available commands: `mandelbrot`, `julia`.

## 🎮Controls

The program supports the following controls:
<table align="center">
  <tr align="center">
    <td><b>Mouse Scroll</b></td>
    <td>Zoom</td>
  </tr>
  <tr align="center">
    <td><b>⬆️ ⬇️ ⬅️ ➡️</b></td>
    <td>Move the view</td>
  </tr>
  <tr align="center">
    <td><b>SHIFT</b></td>
    <td>Shift the color range</td>
  </tr>
  <tr align="center">
    <td><b>-</b> and <b>+</b></td>
    <td>Decrease or increase the max iterations</td>
  </tr>
  <tr align="center">
    <td><b>SPACE</b></td>
    <td>Generate new constants for the Julia fractal</td>
  </tr>
  <tr align="center">
    <td><b>ESC</b></td>
    <td>Close the program window</td>
  </tr>
</table>


> 🚀 The lower the  iterations, the faster the program will run.
>
> 🐢 The deeper the zoom, the more iterations are needed to render the fractal, the slower the program.

---

## 📐The math behind fractals

Fractals are formed by mathematical suites.

For example, the Julia and Mandelbrot sets are defined by the following suite:

$$
z_{n+1} = z_n^2 + c
$$

Fractals are based on complex numbers (i.e. numbers with a real and imaginary part, like $z = a + bi$).

* The $a$ (real) part of the complex number is represented on a x-axis.
* The $b$ (imaginary) part of the complex number is represented on a y-axis.
* This means that the coordinates $(3, 7)$ represent number $z = 3 + 7i$, and that every pixel of a window can be used to represent a complex number.
* Every complex number put into the suite will either:

	* converge to a finite number
	* diverge to infinity.

* The pixels of the window can be colored depending on whether the complex number they represent converges or diverges.
