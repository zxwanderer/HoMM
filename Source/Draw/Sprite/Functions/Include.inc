
                ifndef _DRAW_SPRITE_FUNCTIONS_INCLUDE_
                define _DRAW_SPRITE_FUNCTIONS_INCLUDE_

                module Function

                include "Shift_OR_XOR.asm"
                include "Shift_M_OR_XOR.asm"
                include "Shift_OR_XOR_Save.asm"
                include "NoShift_OR_XOR.asm"
                include "NoShift_M_OR_XOR.asm"
                include "NoShift_LD_ATTR.asm"
                include "NoShift_OR_XOR_Save.asm"
                include "NoShift_OR_XOR_ATTR.asm"

                ; -----------------------------------------
                ; тип вывода спрайта
                ; + 000 - OR & XOR с сохранением фона
                ;           H'  - старший байт адреса таблицы сдвига
                ;           DE' - адрес буфера
                ; - 001 - OR & XOR с сохранением фона, отражённый спрайт по горизонтали
                ; + 010 - OR & XOR
                ;           H'  - старший адрес таблицы зеркальных байт
                ;           D'  - старший адрес таблицы сдвига
                ; + 011 - OR & XOR, отражённый спрайт по горизонтали
                ;           H'  - старший адрес таблицы зеркальных байт
                ;           D'  - старший адрес таблицы сдвига
                ; + 100 - LD с атрибутами
                ;           H'  - старший байт таблицы преобразования адреса экрана в атрибутный
                ; - 101 - LD с атрибутами, отражённый спрайт по горизонтали
                ; + 110 - OR & XOR с атрибутами
                ;           H'  - старший байт таблицы преобразования адреса экрана в атрибутный
                ; - 111 - OR & XOR с атрибутами, отражённый спрайт по горизонтали
                ; -----------------------------------------
Table:          
                ; таблица функций без сдвига (горизонталь, ширина спрайта в знакоместах)
.OR_XOR_SAVE_   DW OR_XOR_SAVE.NoShift.Table.OX_8,      OR_XOR_SAVE.NoShift.Table.OX_16,    OR_XOR_SAVE.NoShift.Table.OX_24,    #0000                               ; +
.M_OR_XOR_SAVE_ DW #0000,                               #0000,                              #0000,                              #0000                               ; -
.OR_XOR_        DW OR_XOR.NoShift.Table.OX_8,           OR_XOR.NoShift.Table.OX_16,         OR_XOR.NoShift.Table.OX_24,         OR_XOR.NoShift.Table.OX_32          ; +
.M_OR_XOR_      DW M_OR_XOR.NoShift.Table.OX_8,         M_OR_XOR.NoShift.Table.OX_16,       M_OR_XOR.NoShift.Table.OX_24,       M_OR_XOR.NoShift.Table.OX_32        ; +
.LD_ATTR_       DW LD_ATTR.NoShift.Table.LDA_8,         LD_ATTR.NoShift.Table.LDA_16,       LD_ATTR.NoShift.Table.LDA_24,       LD_ATTR.NoShift.Table.LDA_32        ; +
.M_LD_ATTR_     DW #0000,                               #0000,                              #0000,                              #0000                               ; -
.OR_XOR_ATTR_   DW OR_XOR_ATTR.NoShift.Table.OXA_8,     OR_XOR_ATTR.NoShift.Table.OXA_16,   OR_XOR_ATTR.NoShift.Table.OXA_24,   OR_XOR_ATTR.NoShift.Table.OXA_32    ; +
.M_OR_XOR_ATTR_ DW #0000,                               #0000,                              #0000,                              #0000                               ; -
                ; таблица функций со сдвигом (горизонталь, ширина спрайта в знакоместах)
.OR_XOR_SAVE    DW OR_XOR_SAVE.Shift.Table.OX_8,        OR_XOR_SAVE.Shift.Table.OX_16,      OR_XOR_SAVE.Shift.Table.OX_24,      #0000                               ; +
.M_OR_XOR_SAVE  DW #0000,                               #0000,                              #0000,                              #0000                               ; -
.OR_XOR         DW OR_XOR.Shift.Table.OX_8,             OR_XOR.Shift.Table.OX_16,           OR_XOR.Shift.Table.OX_24,           OR_XOR.Shift.Table.OX_32            ; +
.M_OR_XOR       DW M_OR_XOR.Shift.Table.OX_8,           M_OR_XOR.Shift.Table.OX_16,         M_OR_XOR.Shift.Table.OX_24,         M_OR_XOR.Shift.Table.OX_32          ; +
.LD_ATTR        DW #0000,                               #0000,                              #0000,                              #0000                               ; -
.M_LD_ATTR      DW #0000,                               #0000,                              #0000,                              #0000                               ; -
.OR_XOR_ATTR    DW #0000,                               #0000,                              #0000,                              #0000                               ; -
.M_OR_XOR_ATTR  DW #0000,                               #0000,                              #0000,                              #0000                               ; -

                endmodule

                endif ; ~ _DRAW_SPRITE_FUNCTIONS_INCLUDE_
