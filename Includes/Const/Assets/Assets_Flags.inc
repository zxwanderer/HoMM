
                ifndef _CONST_ASSETS_FLAGS_
                define _CONST_ASSETS_FLAGS_
ASSETS_ARCHIVE_BIT      EQU 0x00                                                ; флаг, архивности ресурса на диске
ASSETS_LOAD_BIT         EQU 0x01                                                ; флаг, загруженности ресурса в память
ASSETS_MARKED_BIT       EQU 0x07                                                ; флаг, помечен как невостребованный (в поле страницы адреса)
ASSETS_ALLOCATION_BIT   EQU 0x06                                                ; флаг, необходимости аллокации ресурса
                                                                                ;   0 - не требуется автоматическая аллокация
                                                                                ;   1 - требуется автоматическая аллокация
ASSETS_NOT_SWITCH_BIT   EQU 0x05                                                ; флаг, не требуется переключать страницу (она лежит в адресном пространстве)
ASSETS_ARCHIVE          EQU 1 << ASSETS_ARCHIVE_BIT
ASSETS_ORIGINAL         EQU 0 << ASSETS_ARCHIVE_BIT
ASSETS_NOT_SWITCH       EQU 1 << ASSETS_NOT_SWITCH_BIT
ASSETS_EMPTY_ELEMENT    EQU 0xFF
ASSETS_MAX              EQU 32                                                  ; максимальное количество ресурсов

                endif ; ~_CONST_ASSETS_FLAGS_
