Project: MyDew Valley
==============================

📓 Synopsis
-----------

Alex is a young man/woman who decided to quit the rat race of modern society. He/she then traveled to a remote region of the countryside looking for a peaceful farm life. While looking for plot of land to build the foundation of his/her farm he/her was approached by a mysterious person (Ilias) who proposed to sell him a suspicious old farm in the middle of nowhere. while exploring the old abandoned barn he/she encounters a seemingly normal chicken who then reveal to be a magical chicken named Sanders that can talk. Just as the revelation happens, [enemies] start to appear and attack the player thus starting the tutorial sequence and the player journey into his farm building and [enemy] slaying. After the tutorial, the starting quest [ex: gather wood] begin, the first one is to repair the barn, the second one to plant seeds, and the third one to go talk to the different residents of the island. The goal of the game is to purify the island and rebuild the farm.

🥅 Project goal
--------------------

The goal of this project was to make a fully fleched RPG game, using the csfml graphical library. The project was limited to 1 month of development time on this month we had multiple requirements we needed to fufill while also doing a complete game and not a just a prototype.

🤔 How To Run?
--------------------

To run our game use the following commands to copile, then run the game.

make re

./my_rpg Assets/scenes/

⚠️ Project Requirements
--------------------

-   Project Name: "my_rpg"
-   Binary Name: "my_rpg"
-   Language: C

### General Requirements

-   The totality of your source files, except all useless files (binary, temp files, obj files,...), must be included in your delivery.
-   Error messages have to be written on the error output, and the program should then exit with the 84 error code (0 if there is no error).
-   The size of your repository (including the assets) must be as small as possible. Think of the format and the encoding of your resource files (sounds, music, images,..). An average maximal size might be 30MB, all included. Any repository exceeding this limit might not be evaluated at all.

### Mandatory Requirements

-   The player needs to have characteristics
-   The player can fight enemies AND the characteristics impact the fights results
-   The player have an inventory which can contain a limited set of items
-   The player can earn experience by winning fights and/or accomplishing specific actions
-   The player can level up thanks to experience AND upgrading its characteristics
-   The game contains NPC
-   The game contains at least one quest
-   The game contains a how to play system at the very beginning

### Technical Requirements

-   A collision system including moving and static elements with different shapes.
-   Camera movements (zoom, translation, rotation).
-   3D effects (depth scaling, isometric projection. . . ).
-   Buttons must have at least 3 different states.
-   Saving system.

### General Rules

-   The window may be closed using events.
-   The windows may have different modes:
    -   Window mode
    -   Full-screen mode
-   The windows may have different resolutions, at least two (1920x1080, and another).
-   The game manages inputs from the mouse click and keyboard.
-   The game contains animated sprites rendered thanks to sprite sheets.
-   Animations in your program are frame rate independent.
-   Animations and movements in your program are timed by clocks.

### Main Menu

-   Must contain at least these options:
    -   Start the game
    -   Resume game (grayed out if not possible)
    -   Settings
    -   Quit the game
-   The settings option must contain:
    -   Sound and music volume options
    -   A window size and resolution options

### In-Game Menu

-   Must be accessible by pressing the Escape key.
-   Must contain at least these options:
    -   Character options
    -   Equipment and inventory management
    -   Characteristics management
    -   Saving
    -   Loading
    -   Settings (the same as main menu)
    -   Commands list
-   The starting and the game menu
