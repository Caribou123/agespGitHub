# FDF

File de Fer is the first graphic project @school42.

The idea is to create a wireframe structure from a given file.

![Screen Shot 2019-04-19 at 2 43 22 PM](https://user-images.githubusercontent.com/41552833/56425318-04762e00-62b4-11e9-84c8-732937386f2e.png)


The file format should be as follow :

```
X X X X X
X X X X X      Xs represent the height of a given point in space.
X X X X X      Examples can be found in the maps directory
X X X X X
```

Two different projections are available : isometric and oblique

```
Make
./fdf [-i or -p] file ## i for isometric and p for oblique
````

You'll be asked to choose a 'contrast', to scale the distance between each point in space.  
Choose 1 at first, increase/decrease the value for more/less pronounced relief.  
Use ESC to leave the program.
