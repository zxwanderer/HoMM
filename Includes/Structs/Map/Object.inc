
                ifndef _STRUCT_MAP_OBJECT_
                define _STRUCT_MAP_OBJECT_

                struct FMapObject
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | T6 | T5 | T4 | T3 | T2 | T1 | T0 | .. |
;   +----+----+----+----+----+----+----+----+
;
;   T6-T0   [7..1]  - тип объекта, ID дефолтных настроек используя таблицу
; -----------------------------------------
Type            DB #00                                                          ; тип объекта
; -----------------------------------------
;   +----+----+----+----+----+----+----+----+
;   |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
;   +----+----+----+----+----+----+----+----+
;   | T6 | T5 | T4 | T3 | T2 | T1 | T0 | CB |
;   +----+----+----+----+----+----+----+----+
;
;   T6-T0   [7..1]  - положение объекта в тайлах
;   CB      [0]     - дробная часть тайла (знакоместо)
; -----------------------------------------
Position        FVector8                                                        ; позиция объекта на карте
SpriteIndex     DB #00                                                          ; индекс спрайта в графическом пакете данной карты
                ends

                endif ; ~_STRUCT_MAP_OBJECT_
