# termtris

This is a minimal implementation of Tetris which can be played from the convenience of your terminal.

Why? Because I really like Tetris.

![Alt Text](https://cdn.discordapp.com/attachments/665849154186248202/935680885414572122/termtris_cropped.gif)

Requirements:

- Currently only works under linux
- uses gcc to compile
- you must have ncurses installed
  - Void Linux: xbps-install -S ncurses-devel
  - Arch Linux/Manjaro: sudo pacman -S ncurses
  - Debian based Distros: sudo apt install libncurses5-dev libncursesw5-dev

The current control scheme is:

1. A: Left
2. D: Right
3. N: Rotate Piece counter clockwise
4. M: Rotate Piece clockwise
5. Q: Quit Termtris

Planned improvements:

- Change the character set to make pieces and board easier to follow as you play
- Add second control scheme which uses the arrow keys
- Add delayed auto shift on the side to side movement
- Add ability to push down to increase drop speed
- Add scores and levels with drop speed increases
