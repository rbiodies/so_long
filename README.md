# So_long
### ***The aim of the mandatory part is:***
To create a 2D game where any hero collects any valuables before leaving the place. It is built to make our work with textures, sprites. And some gameplay elements.

### ***Bonus list:***

• enemy patrols that cause the player to lose in case of contact.

• There’s some sprite animation.

• Movement count is directly displayed on the screen instead of shell output.
### ***Example of a minimal .ber map:***
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
>• **0** for an empty space,
>
>• **1** for a wall,
>
>• **C** for a collectible,
>
>• **E** for a map exit,
>
>• **P** for the player’s starting position.
### ***Run:***
```
%> make bonus
%> ./so_long map4.ber
```
<img width="912" alt="Screen Shot 2021-11-27 at 6 15 53 PM" src="https://user-images.githubusercontent.com/90090114/143686999-43be0b49-6855-4b58-8cf8-5f31947d5d13.png">
