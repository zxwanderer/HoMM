
                ifndef _CONST_GAME_SCREEN_WORLD_
                define _CONST_GAME_SCREEN_WORLD_
SCR_WORLD_POS_X         EQU 1                                                   ; положение мира на экране по горизонтали в знакоместах
SCR_WORLD_POS_Y         EQU 1                                                   ; положение мира на экране по вертикали в знакоместах
SCR_WORLD_SIZE_X        EQU 12                                                  ; количество видимых тайлов мира по горизонтали
SCR_WORLD_SIZE_Y        EQU 11                                                  ; количество видимых тайлов мира по вертикали

SCREEN_CURSOR_X         EQU 256                                                 ; ширина экрана для курсора
SCREEN_CURSOR_Y         EQU 192                                                 ; высота экрана для курсора
SCREEN_EDGE             EQU 4                                                   ; ширина границы скролла карты

                endif ; ~_CONST_GAME_SCREEN_WORLD_
