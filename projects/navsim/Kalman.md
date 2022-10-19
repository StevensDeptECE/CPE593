# Kalman Filter Navigation Problem

First step, build a [navigation simulator](navsim.md).
Then implement a Kalman filter estimating position. You will know the "real" location because your simulation creates that. You will know the calculated position based on the sensors with errors. Demonstrate the error, and in particular demonstrate the situations where a failure causes an error far larger than is explainable using the variance of the sensors. Can you detect the error?

For example, if your beacons are reporting distances of 1000m, 1005m, 1280m, and then one of them has a problem and due to missing the response reports 2025m, what does that do to your answer, and can you figure it out? As usual, since this is an algorithms class you have to analyze your code for complexity as a function of the variables including the number of beacons, the number of robots, and the number of readings forward and backward in time that are used to estimate the current position.
