# Fillit

Fillit is a project at 42 that will help familiarize you with recursion to solve a problem. You will be given tetrimino squares and be expected to fit them in the smallest possible square in a short period of time.

## Program Creation

To create the executable `fillit` run `make`. To use fillit `./fillit target_file`.

## Diagnostic Fillit

If you would like diagnostic information, go into the diagnostic folder and use the program creation instructions.

This fillit will print out what the computer is doing behind the scenes to try and solve.

## Solving Engine

To solve fillit is no easy task. We took the approach of using linked lists. We converted our input to 4 coordinates per tetrimino.
```
x[4]
y[4]
```
Each index of x and y correspond to a single coordinate. E.g. x[0], y[0] corresponds to a single '#' of the tetrimino. This makes solving and placing pieces on the map easy as you just have to overlay the coordinates on a 2d array that represents the map.

Keep in mind these coordinates will be for a 2d array and will look different on a standard x-y plane. In this grid y at 0 is the top most position whereas if you tried to map these coordinates on an x-y plane the coordinates of 0, 1 would look like 3, 1 if you were to translate them from our program to an accurate representation on an x-y coordinate plane. X remains unchanged.

Our solver was 2 functions. A function to check to see if we could solve on a map. A function that would increase the map size when we couldn't solve on a map.

This is the function to see if we can solve on a map.
```
int		solve(t_tetro *piece, t_map *map)
{
	int		i;

	i = -1;
	if (!piece)
		return (1);
	while (++i < ((map->size - 1) * (map->size - 1)))
	{
		if (check(piece, map->go, map))
		{
			place_tetri(piece, map);
			if (solve(piece->next, map))
				return (1);
			else
			{
				ft_remove(piece->letter, map->go, map->size);
				transform(piece, map, 0);
				transform(piece->next, map, 7);
			}
		}
		else if (!transform(piece, map, 0))
			transform(piece, map, 7);
	}
	return (0);
}
```

This function calls itself until it solves, or until it realizes that there is no possible solution on the given map due to size constraints. We have a while loop to try and place a given piece in all possible areas of a map.

If we have a Tetrimino like so:

```
##
##
```

and a 3x3 map, we must try to place it in all possible positions of the map. We will use the smallest possible tetrimino as our assumption for all pieces so that we will always try all possible solutions. Here are all possible solutions for placing our above piece on a 3x3 map.

```
1)
##.
##.
...

2)
.##
.##
...

3)
...
##.
##.

4)
...
.##
.##
```
There are 4 possible combinations for placing the piece on the above map. Our loop checks all possible positions to place. Map size is 3 so we subtract - 1 and then square the remainder to find out how many times we should try to place a given piece. Keep in mind for a larger piece like this:
```
##
#
#
```
There will be less possibilities for where we can place. However, we generalize and assume that each piece is the smallest possible piece because that is an easier assumption to implement an algorithm on even though it might take more computing power to solve.

Each time we cannot place we move our piece either to the right by increasing all x values by 1, or, if we cannot move to the right due to the current map size, we increase all y values by 1 which moves the tetrimino down. If y is increased, x is pushed as far left as possible.

If we cannot move the current piece down or right anymore, we push it to the top right hand corner because we know we cannot place it on the current map size, so we push it to the start.

This is the second part to our solving function:
```
void	start(t_tetro *piece, t_map *map)
{
	while (!solve(piece, map))
	{
		plus_map(map);
		transform(piece, map, 1);
	}
	printmap(map->go, map->size);
	freemap(map->go, map->size);
	free(map);
}
```
This function checks to see if our solve function could find a solution on the given map. If it couldn't, we increment map size so we can try all combinations again, on a bigger map. Once we are done solving, we print the map out and give back all memory we allocated using free.

### Acknowledgments

* Thank you to Hiroshi and Tapa for explaining recursive backtracking
