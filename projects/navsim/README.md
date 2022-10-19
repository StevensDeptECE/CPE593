# Navigation Simulator

## The Environment

The navigation simulator consists of an environment capable of defining a terrain consisting of land and water (with air above), and allowing the simulation of n robots moving through this environment. Depending on your project, you do not need to implement all the robots. This document defines the common environment that you must implement as part of your project.

The environment consists of a grid. Each cell in the grid will have land (with a height in m).  On top of the land may be water (a depth in meters). A height of zero is defined as mean sea level, but bodies of water can be high up as well. The simulator world is therefore a 2D grid where each cell contains two numbers. An example is shown here:

| ---  | ---- | ---  | ---  | ---   |
| 3  0 | 4  0 | 5 0  | 5  0 | 10  0 |
| 4  0 | -5 3 | -6 3 | -5 3 | 11  0 |
| 8  0 | -4 3 | -8 3 | -6 3 | 11  0 |
| 5  0 | -3 3 | -8 3 | -6 3 | 11  0 |
| 6  0 | 10 0 | 11 0 | 12 0 | 8   0 |

In the above grid, some land has a small "ocean" in the center


The world must define the integer size of the grid in rows/columns, the size of each grid square (dx,dy). Together, this defines the size of the world as a rectangle.

Optionally, you may define a grid defining a spherical world, in which case the mathematics is more complicated since a rectangular grid does not fit a sphere.


Airplanes will have to avoid hitting the water or the land.

Optional feature: air and water currents.
Air and water can be in motion (river or current in the ocean).  The environment can specify the motion of water flow at each location.

Create a single random number generator and use it for all random actions in the simulation. To make testing deterministic, seed with a constant (like 0). Do not have multiple random number generators. Use a single generator which can be global (C++) or a static variable of the top-level navsim class (Java).

The environment will also maintain a list of all robots moving around and is responsible to check when a robot collides with something (land, water, or another robot).

The environment must be able to read in a file containing all this information to load the scenario, and to save out the state to a file so it can be loaded later.
Behavior Common to all Robots
All robots will have the following state:
x,y,z (position).  This is a Vector, to be written as a separate object
vx,vy,vz (velocity) This is also a vector
theta (direction, 0 to 360)
pitch (angle up or down, -90 to +90)
mass (the mass of the robot
battery life (Amp-hours)
maximum current (Amps)
voltage (V)
maximum velocity

When a robot runs out of power it will stop applying power.  If it is a boat, it will slow down unless it is in a current.  If it is an airplane it will begin to fall.

## Kinds of Robots

Airplanes will fly through the air, and if they go too low they hit the ground (or water) and crash. If airplanes move too slowly they will lose lift and start to stall (ie airplanes have a minimum stall velocity)

Boats will have to remain on the surface, and have a minimum depth.  If the water is too shallow, the boat will run aground.  Boats will have a maximum acceleration/deceleration, so of course this means that a boat will tend to go a long distance before it can stop because they tend to have high mass. Boats also have a turning radius and may be hard to turn.

Submarines can go down through the water but not above the surface.  If they hit the bottom too hard they can be damaged and sink.  Submarines will have buoyancy and if lighter than water will tend to rise.  If heavier, they will tend to sink. They can overcome this somewhat by moving through the water.

Wheeled vehicles will have a number of powered wheels that can exert forces.  The wheeled robot should be able to turn in place by turning one side to forward while the other side moves back.  Your wheeled vehicle cannot go into water.

## Sensors

There are a number of sensors that robots in our simulation can carry.  All sensors have error (stored as variance).  Each sensor will take the real value of the measured value (for example, the distance of the robot from a beacon) and add a normally distributed random number based on the variance. (See normal distribution in Wikipedia if you do not know about this kind of random number.  Both C++ and Java support normally distributed random numbers in the standard library).

* A GPS measures position.  It takes the real position of the robot and adds normally distributed error to x,y and z.  Depending on the satellite locations, error may be as little as 1m or as great as 10m.  Simulate the varying error as a sinusoid varying with a period of 1 hour, which is not at all correct, but should be interesting.

* RADAR.  RADAR measures distance from the sensor to something else.    RADAR will have a maximum distance, a distance variance, and an angular variance.  It will report that something is at an angle and distance away.  Doppler RADAR will also support the velocity of the object moving toward or away from the RADAR.

* Altimeter.  Reports the height of the sensor above sea level.

* RADAR altimeter.  Reports the height of the sensor above ground or water.

* SONAR.  Like RADAR but works under water.

* Compass. Shows the direction a vehicle is heading.  For this simulation compass will always point due north.

* Accelerometer.  Measure accelerations of the vehicle in x,y,z

* Wheel rotation measurement.  Measures the total rotation of the wheel.  Error is due to slippage.
Robot Viewer
The Robot Viewer class should display the environment and all robots in the system.  Each robot should be displayed at its actual location, but simultaneously there should be a display of its belief of where it is.

* Beacon. If you are making your own beacon system, then if it's  like GPS, it broadcasts a signal which can be used to infer the distance from the beacon. With two beacons, the position of the robot is at the intersection between two circles. Usually there are two solutions, so to discriminate between them you need to know approximately where you are. With 3 beacons, assuming they agree, there is a single point of maximum probability.
