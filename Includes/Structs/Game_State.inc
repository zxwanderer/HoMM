
                ifndef _STRUCTS_GAME_STATE_
                define _STRUCTS_GAME_STATE_

                struct FGameState                                               ; переменные состояния игры                                     [10 байт]
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. | .. | .. | .. | NS | FS |
;   +----+----+----+----+----+----+----+----+
;
;   NS      [1]     - флаг, отключение смены экранов
;   FS      [0]     - флаг, рендер завершён
; -----------------------------------------
Render          DB #00                                                          ; флаги отрисовки                                               [1 байт]
Screen          DB #00                                                          ; старший бит адрес экрана                                      [1 байт]
Assets          FAssets                                                         ; копия данных об ассете (с последним)                          [8 байт ]
                ends

                endif ; ~_STRUCTS_GAME_STATE_
