
                ifndef _MEMORY_DETERMINE_
                define _MEMORY_DETERMINE_

                module Memory
                DISP Adr.SharedPoint
Begin:          EQU $
Const:          ; константные значения
.MaxPages       EQU 8                                                           ; максимальное количество страниц памяти по 16кб
.MinPagesAllow  EQU 8                                                           ; минимальное допустимое количество страниц памяти по 16кб
.CheckPageAdr   EQU #FFFF                                                       ; адрес для проверкаи записи/чтения номера страниц
.INDEX_NONE     EQU #FF                                                         ; недоступный индекс

; -----------------------------------------
; определение доступной памяти
; In:
; Out:
;   флаг переполнения сброшен, если недостаточно памяти
; Corrupt:
; Note:
; -----------------------------------------
Determine:      ; проверка порта #7FFD
                CALL CheckPort
                CP Const.MinPagesAllow
                SCF
                RET Z

                OR A
                RET
; -----------------------------------------
; првоерка порта, на возможность переключать страницы памяти
; In:
;   HL - адрес функции переключения страниц, проверяемог порта
; Out:
;   A  - количество доступных страниц
; Corrupt:
; Note:
; -----------------------------------------
CheckPort:      ; -----------------------------------------
                ; нумерация страниц
                ; -----------------------------------------
                LD HL, Const.CheckPageAdr
                LD BC, PORT_7FFD
                LD E, Const.MaxPages

.SetPage_Loop   CALL SetPort_7FFD
                DEC E
                LD (HL), E
                JR NZ, .SetPage_Loop

                ; -----------------------------------------
                ;  проверка нумерации строк
                ; -----------------------------------------
                XOR A
                EX AF, AF'
                LD E, Const.MaxPages
     
.CheckPage_Loop CALL SetPort_7FFD
                ; проверка ранее проверенной страницы
                LD A, (HL)
                INC A
                JR Z, .NextPage                                                 ; переход, если страница ранее была определена

                ; фиксация новой страницы
                EX AF, AF'
                INC A                                                           ; увеличение счётчика доступных страниц
                LD (HL), #FF                                                    ; затереть номер определённой страницы
                EX AF, AF'

.NextPage       ; переход к следующей странице
                DEC E
                JR NZ, .CheckPage_Loop
                EX AF, AF'                                                      ; количество доступных страниц

                RET
; -----------------------------------------
; установка страницы для порт #7FFD
; In:
;   E  - значение для записи в порт
;   BC - номер порта #7FFD
; Out:
; Corrupt:
;   AF
; Note:
; -----------------------------------------
SetPort_7FFD    LD A, (BC)
                XOR E
._5_bit         EQU $+1
                AND PAGE_MASK_INV
                XOR E
                LD (BC), A
                OUT (C), A
     
                RET

                include "Source/Memory/Message_InsufficientRAM.asm"
Determine.Size  EQU $-Begin
                ENT
                display " - Memory determine:\t\t\t\t\t\t\t= busy [ ", /D, Determine.Size, " byte(s) ]"
                endmodule

                endif ; ~ _MEMORY_DETERMINE_
