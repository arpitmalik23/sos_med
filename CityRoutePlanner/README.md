# City Route Planner 🗺️

A C++ project that finds the shortest path through a grid-represented city map using Dijkstra's algorithm.

## Features
- Load ASCII maps with road types (H, L, T, A, etc.)
- Assign cost to each road type
- Compute shortest path from Start (S) to End (E)
- Visualize path on the map

## Run

```bash
make
./route
```

## Sample Map like 

```
##########
#S..L...E#
#.##T##..#
#H....A..#
##########
```

## Legend
- `H`: Highway (1)
- `L`: Local road (2)
- `T`: Traffic (5)
- `A`: Alley (3)
- `#`: Wall (impassable)
- `S`: Start
- `E`: End
- `*`: Path found
