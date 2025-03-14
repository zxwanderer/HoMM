
                ifndef _CONST_MEMORY_MAP_PAGE_0_
                define _CONST_MEMORY_MAP_PAGE_0_

                ;   +-------+------------------------------------------+-------+
                ;   | #C000 |                           BiomeRenderBuf | #0100 |
                ;   +-------+------------------------------------------+-------+
                ;   | #C100 |                          StaticRenderBuf | #0100 |
                ;   +-------+------------------------------------------+-------+
                ;   | #C200 |                         DynamicRenderBuf | #0100 |
                ;   +-------+------------------------------------------+-------+
                ;   | #C300 |                             FoWRenderBuf | #0100 |
                ;   +-------+------------------------------------------+-------+

                ;   +-------+------------------------------------------+-------+
                ;   | #CC00 |                         StaticChunkArray | #0100 |
                ;   +-------+------------------------------------------+-------+
                ;   | #CD00 |                        DynamicChunkArray | #0100 |
                ;   +-------+------------------------------------------+-------+
                ;   | #CC00 |                              StaticArray | #0800 |
                ;   +-------+------------------------------------------+-------+
                ;   | #CD00 |                             DynamicArray | #0800 | ; ToDo можно уменьшить размер структуры динамических объектов
                ;   +-------+------------------------------------------+-------+
                ;   | #C400 |                                 BiomeBuf | #1000 | ; примерно 64х64 по байту и 90х90 на 0.5 дайт на ID биома
                ;   +-------+------------------------------------------+-------+
                ;   | #CE00 |                                   FoWBuf | #1000 | ; примерно 64х64 по байту и 90х90 на 0.5 дайт на ID биома
                ;   +-------+------------------------------------------+-------+

                ; таблица быстрого формирования тумана войны (256 байт)
                ; таблица смещений быстрого рассчёта положения тайла (256 байт)

                module Page
MapRaw          EQU PAGE_0
                endmodule

                module Size
                endmodule

                module Adr
MapRaw          EQU #C000                                                       ; адрес карты сырых данных
BiomeRenderBuf  EQU #C000                                                       ; адрес буфера рендер биома
StaticRenderBuf EQU #C100                                                       ; адрес буфера рендер статических объектов
DynamicRenderBuf EQU #C200                                                      ; адрес буфера рендер динамических объектов
FoWRenderBuf    EQU #C300                                                       ; адрес буфера рендер тумана войны
                endmodule

                endif ; ~_CONST_MEMORY_MAP_PAGE_0_
