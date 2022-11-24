# The Snake's Den- A Snake Game
### Video Demo: [click here](https://youtu.be/m0emKMhjKLI)
## Cs50- Final Project
> This is the final project to the CS50- Introduction to Computer Science Course
> This project includes frameworks used with the programming language Python

## Why a snake game?
Since childhood I was Intruiged by the way games were designed and always had the curiousity about the work which took place behind the creation of the game. My first game ever which I played was a Snake game which I had come across on a website which contained numerous flash games. I was fascinated by how a simple game kept me occupied for ample number of hours.

## About The Project
* This project is a simple and my take on the classic and timeless game which is famously known as the "Snake Game"
* Making this game was extremely nostalgic and refreshing as it brought back a lot of memories
* "The Snake's Den" is programmed in core Python. I have not used any frameworks (excluding Tkinter) because I wanted to test my core Python skills and what I had learned CS50x.
* The game is fully programmed in the Python programming language and uses Tkinter for the GUI Interface

## How Does It Work?
The code contains multiple functions which are responsible for various actions performed by the:
* snake
* food (which the snake eats to level himself up)
* game window
* game over window (which tells that we have lost)

## Creating the Window
The window of the game is specified the following way through variables
```python
GAME_WIDTH = 700
GAME_HEIGHT = 700
```

GAME_WIDTH, GAME_HEIGHT are linked the following way:
```python
window_width = window.winfo_width()
window_height = window.winfo_height()
screen_width = window.winfo_screenwidth()
screen_height = window.winfo_screenheight()
```
## Creating the Snake
The snake is the most essential and basic part without which the game isnt even close to complete.
All the attributes of the snake are stores in a class called "Snake"
```python
class Snake:
```
The following code defines the:
* size of the body of the snake (which is stores inside of `BODY_PARTS`)
* the co-ordinate of the start point of the snake
* color of the snake (which is stored inside of `SNAKE_COLOR`)
```python
 def __init__(self):
        self.body_size = BODY_PARTS
        self.coordinates = []
        self.squares = []

        for i in range(0, BODY_PARTS):
            self.coordinates.append([0, 0])

        for x, y in self.coordinates:
            square = canvas.create_rectangle(x, y, x + SPACE_SIZE, y + SPACE_SIZE, fill=SNAKE_COLOR, tag="snake")
            self.squares.append(square)
```

## Creating the Food
The food is the second most important element of our game because without it the snake wont be able to grow itself and the points wont increase without which the game will lack the competetive spirit and wont have a proper and rigid reason to continously play it.
* The food is procedurely generated (i.e the food appears on a random spot on the screen everytime the window is opened or the snake eats it)
* When the snake eats the food it dissapears from the previous area and respawns at a random co-ordinate on the window.
* The food is stored in a python class
```python
class Snake: #stores the attributes and functionalities of the 'food'
```
* The food's shape can be anything. It can be a circle, an oval or a square. In the original version of the game everything was in pixel form i.e
everything was in a square-ish shape.
```python
# creates the food in a rectangular shape on the canvas(the window)
canvas.create_rectangle(x, y, x + SPACE_SIZE, y + SPACE_SIZE, fill=FOOD_COLOR, tag="food")
```
```python
x = random.randint(0, (GAME_WIDTH / SPACE_SIZE)-1) * SPACE_SIZE
y = random.randint(0, (GAME_HEIGHT / SPACE_SIZE) - 1) * SPACE_SIZE
```
* The code above generates a random food object on the surface of the canvas.
* Here x and y are co-ordinates of the window and the `random.randint` generates a random x and y co-ordinate for the food to spawn

## Collisions
The collisions act as a barrier for the snake. The role of the collision in the game is fairly simple, if the snake touches the end of the canvas it will die and the game over screen will show.
### Why are barriers Important?
Barriers are an essential part of the game because:-
* it creates that sense of thrill (You are always constantly trying to avoid touching the collision so that you can play endlessly)
* Without it you will just keep scoring without the feeling of competetiveness and will get bored easily as it will lack in thrill

### How are they made?
```python
 x, y = snake.coordinates[0]

# the following checks if the snake touches the window corner (which is the `GAME_WIDTH` AND THE `GAME_HEIGHT`)
    if x < 0 or x >= GAME_WIDTH:
        return True
    elif y < 0 or y >= GAME_HEIGHT:
        return True

    for body_part in snake.coordinates[1:]:
        if x == body_part[0] and y == body_part[1]:
            return True

    return False
```

## Game Controls
The game control is the input which is taken by the user and tells the snake to move in a certain direction.
- The snake game has very basic controls as the only movable thing in this game is the snake itself which moves in 4 directions `up`, `down`, `left`, `right`.
- the main goal of controls are to direct the snake to the food which is spawned.
### How are the controls made?
```python
window.bind('<Left>', lambda event: change_direction('left'))
window.bind('<Right>', lambda event: change_direction('right'))
window.bind('<Up>', lambda event: change_direction('up'))
window.bind('<Down>', lambda event: change_direction('down'))
```
the following code is responsible for the change of actions of the snake.

## The Game Over Screen
The game over screen is prompted when the snake dies i.e. it touches the end of the window (which is the collision)
- to create the game over screen can be created by passing a function named `game_over`
```python
    def game_over():

    canvas.delete(ALL)
    canvas.create_text(canvas.winfo_width()/2, canvas.winfo_height()/2,
                       font=('consolas',70), text="GAME OVER", fill="red", tag="gameover")
```
- `canvas.delete(ALL)` deletes the canvas
- `canvas.create_text` creates the text which has to be displayed on the game over window/screen
- `font` inside the `canvas.create_text` defines in what font 'Game Over' will display
- `text` defines what text has to be displayed
- `fill` defines the color of the text

## Output
The final stage of the project is to play the project 😜
- The following output can be seen:
<img src="project/images/Screenshot 2022-10-19 175326.png" alt="output image">

## Thank you!
#### This is the end of the the project and the end of a fantastic course "CS50x" 👍