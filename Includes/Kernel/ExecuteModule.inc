
                ifndef _KERNEL_EXECUTE_MODULE_
                define _KERNEL_EXECUTE_MODULE_
ExecuteModule
.Core           EQU Kernel.Modules.Core                                         ; запуск инициализации "ядра"
.LoadMap        EQU Kernel.Modules.Map.Load                                     ; запуск загрузки карты
.Session        EQU Kernel.Modules.Session                                      ; запуск загрузки/инициализации сессии
.World          EQU Kernel.Modules.World                                        ; запуск "мира"

                endif ; ~_KERNEL_EXECUTE_MODULE_
