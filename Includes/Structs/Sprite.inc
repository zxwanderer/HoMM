
                ifndef _STRUCTS_SPRITE_
                define _STRUCTS_SPRITE_

                struct FSpriteData
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | D1 | D0 | MR | P4 | P3 | P2 | P1 | P0 |
;   +----+----+----+----+----+----+----+----+
;
;   D1,D0   [7,6]       - тип вывода спрайта
;                           00 - LD
;                           01 - OR & XOR
;                           10 - LD с атрибутами
;                           11 - OR & XOR с атрибутами
;   MR      [5]         - флаг, зеркального отображения спрайта по горизонтали
;   P4-P0   [4..0]      - страница хранения спрайта (32 страницы)
; -----------------------------------------
Page            DB #00                                                          ; номер страницы
Adr             DW #0000                                                        ; адрес спрайта (#C000 - #FFFF)

                ends


                struct FSpriteInfo
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. | W4 | W3 | W2 | W1 | W0 |
;   +----+----+----+----+----+----+----+----+
;
;   W4-W0   [4..0]      - ширина спрайта
; -----------------------------------------
Width           DB #00                                                          ; ширина спрайта                    (в пикселях)
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. | H4 | H3 | H2 | H1 | H0 |
;   +----+----+----+----+----+----+----+----+
;
;   H4-H0   [4..0]      - высота спрайта
; -----------------------------------------
Height          DB #00                                                          ; высота спрайта                    (в пикселях)
SOx             DB #00                                                          ; смещение спрайта по горизонтали   (в пикселях)
SOy             DB #00                                                          ; смещение спрайта по вертикали     (в пикселях)

                ends


                struct FSprite
Info            FSpriteInfo                                                     ; информация о спрайте
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. | .. | .. | .. | .. | .. |
;   +----+----+----+----+----+----+----+----+
;
; -----------------------------------------
ExtraFlags      DB #00                                                          ; дополнительные флаги
Data            FSpriteData                                                     ; данные расположения спрайта

                ends

                struct FSpritesRef                                              ; указатель на спрайты
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | RF | CS | N5 | N4 | N3 | N2 | N1 | N0 |
;   +----+----+----+----+----+----+----+----+
;
;   RF      [7]         - флаг, структура хранит смещение до актуальных данных о спрайтах
;                         используется, когда спрайт имеет множество анимаций
;   CS      [6]         - флаг, указывает на композитный спрайт
;   N5-N0   [5..0]      - количество спрайтов
; -----------------------------------------
Num             DB #00                                                          ; на какое количество спрайтов указывает
Data            FSpriteData                                                     ; данные расположения спрайта
Dummy           DS 4, 0                                                         ; резерва
                ends

                struct FGraphicHeader                                           ; структура описывающая заголовок графики
Lable           TEXT 13, {"", 0}
Num             DB #00
Offset          DW #0000
                ends

                endif ; ~_STRUCTS_SPRITE_
