# Least Squares Fit to Data
For this project you will be generating data with an underlying distribution with noise added, then testing your ability to recognize the data.

First step is to create randomized data. Implement the code in the
test file for the generation. Each function generates a different
distribution. For example, there is linear, quadratic, cubic, quartic,
a general polynomial, an exponential decay, exponential growth and a
sine wave.

Next step is to be able to add random noise to the data. For each
function there is at least one corresponding function which adds
random noise. You must use the good random number generator in
<random> not the old garbage rand() which does not generate
statistically valid random numbers for this purpose.

Having done this, you will then write a program that given a data set,
attempts to fit each of the distributions using least squares and
picks the fit with the least error.

Last, write a master routine that applies the best fit least squares,
subtracts it, and attempts to fit a distribution to the remainder. In
this way, you may fit a combination function such as linear + sine
wave, or exponential decay + sine wave.

