
                ifndef _WORLD_TILEMAP_VISIBLE_OBJECTS_
                define _WORLD_TILEMAP_VISIBLE_OBJECTS_
; -----------------------------------------
; определение видимых объектов
; In:
; Out:
;   A - количество объектов в массиве
; Corrupt:
; Note:
; -----------------------------------------
VisibleObjects: SET_PAGE_WORLD                                                  ; включить страницу работы с картой "мира"

                ;
                LD IX, AddObjects
                LD DE, Adr.SortBuffer
                EXX

                ;
                LD HL, GameSession.WorldInfo + FWorldInfo.MapPosition
                LD BC, #0202                                                    ; минимальный захватываемое окно в чанках
                LD E, (HL)                                                      ; X
                INC L
                LD D, (HL)                                                      ; Y

                ; приведение положение окна к тайлам (есть проблемы с этим)
                SRL D
                SRL E

                ; корректировка ширины захвата чанков, если не выровнено
                LD A, E
                AND Kernel.ChunkArray.CHUNK_SIZE_MASK
                JR Z, $+3
                INC C

                ; корректировка высоты захвата чанков, если не выровнено
                LD A, D
                AND Kernel.ChunkArray.CHUNK_SIZE_MASK
                JR Z, $+3
                INC B

                ifdef _DEBUG
                LD (.VisibleSize), BC
.VisibleSize    EQU $+1
                LD BC, #0000
                endif
                
                ; -----------------------------------------
                ; получение значений в области
                ; In:
                ;   HL - адрес счётчиков массива чанков (выровненый 256 байт)
                ;   DE - координаты области в тайлах (D - y, E - x)
                ;   BC - размер охватываемой области в чанках (B - y, C - x)
                ;   IX - адрес обработчика сортировки
                ;       A - количествой добавляемых элементов
                ;       H - старший адрес текущего массива чанков
                ;       E - смещение в массиве чанков первого элемента
                ; Out:
                ; Corrupt:
                ;   L, DE, BC, AF
                ; Note:
                ; -----------------------------------------
                LD HL, Adr.ChunkArrayCounters
                CALL ChunkArray.Area
                
                EXX
                LD A, E
                SRL A

                ifdef _DEBUG
                LD (.VisibleObjects), A
.VisibleObjects EQU $+1
                LD A, #00
                endif

                RET
;   A - количествой добавляемых элементов
;   H - старший адрес текущего массива чанков
;   E - смещение в массиве чанков первого элемента
AddObjects:     ; 
                EX AF, AF'
                LD A, E
                PUSH HL
                EXX

                POP HL
                INC H                                                           ; переход на массив значений
                LD L, A
                
                EX AF, AF'
                LD B, A

.Loop           ;
                LD A, (HL)
                INC L

                ; %0aaaaaaa
                LD C, HIGH Adr.ObjectsArray >> 4    ; %00001100
                ADD A, A    ; %aaaaaaa0 : 0
                RL C        ; %0001100a
                ADD A, A    ; %aaaaaa00 : a
                RL C        ; %001100aa
                ADD A, A    ; %aaaaa000 : a
                RL C        ; %01100aaa
                ADD A, A    ; %aaaa0000 : a
                RL C        ; %1100aaaa

                ; сохранение адреса
                LD (DE), A
                INC E
                LD A, C
                LD (DE), A
                INC E

                DJNZ .Loop

                EXX
                RET

                endif ; ~_WORLD_TILEMAP_VISIBLE_OBJECTS_
