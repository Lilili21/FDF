# FDF

This is my first graphic project on the mlx library.
The program takes an ".fdf" file with coordinates and colors (optional), as a parameter. Then draws a 3D map from a 2D representation.
Using the keyboard, you can rotate the picture in three planes, increase the size of the picture, the height along the Z axis, and change the position on the screen. The mouse can additionally adjust the size along the Z axis.
Projections and rotations are calculated using the rotation matrix formulas.
Rendering occurs using function "the mlx_put_image".
