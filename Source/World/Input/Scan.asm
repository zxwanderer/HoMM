
                ifndef _WORLD_INPUT_SCAN_
                define _WORLD_INPUT_SCAN_
; -----------------------------------------
; сканирование устроиств ввода
; In:
; Out:
; Corrupt:
; Note:
; -----------------------------------------
Scan:           ; проверка HardWare ограничения мыши
                CHECK_HARDWARE_FLAG HARDWARE_KEMPSTON_MOUSE_BIT
                JR Z, .KeyCheck                                                 ; переход, если мышь недоступна
                CALL Mouse.UpdateCursor                                         ; обновить положение курсора

                LD BC, Mouse.Position

                LD A, (BC)                                                      ; позиция корсора по горизонтали
                CP SCREEN_EDGE
                CALL C, Movement.Left.Force

                LD A, (BC)
                CP SCREEN_CURSOR_X - SCREEN_EDGE
                CALL NC, Movement.Right.Force

                INC BC

                LD A, (BC)                                                      ; позиция корсора по вертикали
                CP SCREEN_EDGE
                CALL C, Movement.Up.Force

                LD A, (BC)
                CP SCREEN_CURSOR_Y - SCREEN_EDGE
                CALL NC, Movement.Down.Force

.KeyCheck       ; проверка клавиши "выбор"
                LD A, (GameConfig.KeySelect)
                CALL Input.CheckKeyState
                LD HL, GameState.Input.Value
                RES SELECT_KEY_BIT, (HL)
                JR NZ, $+4
                SET SELECT_KEY_BIT, (HL)                                        ; установка флага, нажатия клавиши "выбор"

                ; проверка клавиши "выход"
                ; LD A, (GameConfig.KeyESC)

                ; проверка клавиши "меню/пауза"
                ; LD A, (GameConfig.KeyMenu)

                ; проверка клавиш перемещения
                LD A, (GameConfig.KeyAccel)
                CALL Input.CheckKeyState
                LD HL, GameState.Input.Value
                RES ACCELERATE_CURSOR_BIT, (HL)
                JR NZ, $+4
                SET ACCELERATE_CURSOR_BIT, (HL)                                 ; установка флага, ускореное перемещение

                ; опрос перемещения влево
                LD A, (GameConfig.KeyLeft)
                CALL Input.CheckKeyState
                CALL Z, Movement.Left

                ; опрос перемещения вправо
                LD A, (GameConfig.KeyRight)
                CALL Input.CheckKeyState
                CALL Z, Movement.Right

                ; опрос перемещения вверх
                LD A, (GameConfig.KeyUp)
                CALL Input.CheckKeyState
                CALL Z, Movement.Up

                ; опрос перемещения вниз
                LD A, (GameConfig.KeyDown)
                CALL Input.CheckKeyState
                CALL Z, Movement.Down

                LD A, (GameState.Input.Value)
                AND MOVEMENT_MASK
                RET Z                                                           ; выход если нет онажатия клавиш

                SET_SCROLL_FLAG SCROLL_MAP_BIT                                  ; установка флага разрешения обновления скрола карты
                RET

                endif ; ~_WORLD_INPUT_SCAN_
